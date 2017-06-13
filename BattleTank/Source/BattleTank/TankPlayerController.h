// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Aiming")
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere, Category = "Aiming")
	float CrosshairYLocation = 0.33333;
	UPROPERTY(EditAnywhere, Category = "Aiming")
	float LineTraceRange = 1000000;
	UWorld* world;

	bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair()const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
