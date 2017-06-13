// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::AimAt(FVector& target, float LaunchSpeed) const
{
	if (!Barrel) return;
	FVector OutLauncVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if(UGameplayStatics::SuggestProjectileVelocity(this, 
		OutLauncVelocity, 
		StartLocation, 
		target, 
		LaunchSpeed, false , 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		FVector AimDirection = OutLauncVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrel(FVector& AimDirection) const
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator  DeltaRotator = AimAsRotator - BarrelRotation;
	UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimAsRotator.ToString());
	//Barrel->Elevate(5);
}

void UTankAimingComponent::SetBarrelReverence(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}
