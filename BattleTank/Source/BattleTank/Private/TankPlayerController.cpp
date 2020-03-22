// Copyright Replitz Studios

#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent))
	{
		FoundAimingComponent(AimingComponent);
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation;
	if (GetSightRayLocation(HitLocation))
	{
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;
	FVector LookLocation;
	if (GetLookDirection(ScreenLocation, LookDirection, LookLocation))
	{
		FVector HitLocation;
		if (GetLookVectorHitLocation(LookDirection, LookLocation, HitLocation))
		{
			OutHitLocation = HitLocation;
			return true;
		}
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection, FVector& OutLookLocation) const
{
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OutLookLocation, OutLookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector LookLocation, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = LookLocation;
	FVector EndLocation = LookLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility)
	)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0.f);
	return false;
}