// Copyright Replitz Studios

#include "Tank.h"
#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerTank) {
		FVector PlayerPosition = PlayerTank->GetActorLocation();

		MoveToActor(PlayerTank, AcceptanceRadius);

		ControlledTank->AimAt(PlayerPosition);
		ControlledTank->Fire();
	}
}
