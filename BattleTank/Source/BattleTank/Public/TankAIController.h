// Copyright Replitz Studios

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	APawn* ControlledTank;
	APawn* PlayerTank;
	
	UTankAimingComponent* AimingComponent;

protected:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float AcceptanceRadius = 10000;

};
