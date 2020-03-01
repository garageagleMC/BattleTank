// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find a player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("AIController found player tank %s."), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		FVector PlayerPosition = GetPlayerTank()->GetActorLocation();
		GetControlledTank()->AimAt(PlayerPosition);
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	 APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	 if (!PlayerPawn) { return nullptr; }
	 return Cast<ATank>(PlayerPawn);
}
