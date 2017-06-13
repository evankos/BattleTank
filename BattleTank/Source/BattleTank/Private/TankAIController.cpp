// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Possessed Tank from AI"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI possessed pawn: %s"),*ControlledTank->GetName())
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Cant find Player tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player tank is: %s"), *PlayerTank->GetName())
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController) {
		ATank* PlayerTank = Cast<ATank> (PlayerController->GetPawn());
		return PlayerTank;
	}
	else {
		return nullptr;
	}
}

void ATankAIController::AimTowardsCrosshair() const
{
	if (!GetControlledTank()) return;
	FVector HitLocation;
	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
	
}

