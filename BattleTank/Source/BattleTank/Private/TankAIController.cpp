// Copyright Replitz Studios

#include "TankAimingComponent.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetPawn();
	PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	FVector PlayerPosition = PlayerTank->GetActorLocation();
	MoveToActor(PlayerTank, AcceptanceRadius);

	AimingComponent->AimAt(PlayerPosition);
	//ControlledTank->Fire();
}
