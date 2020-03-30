// Copyright Replitz Studios

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetPawn();
	PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn) {
		ATank* PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	FVector PlayerPosition = PlayerTank->GetActorLocation();
	MoveToActor(PlayerTank, AcceptanceRadius);

	AimingComponent->AimAt(PlayerPosition);

	if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
	{
		AimingComponent->Fire();
	}
}

void ATankAIController::OnTankDeath()
{
	if (!ControlledTank) { return; }
	ControlledTank->DetachFromControllerPendingDestroy();
	
	UE_LOG(LogTemp, Display, TEXT("AI tank %s died."), *ControlledTank->GetName());
}
