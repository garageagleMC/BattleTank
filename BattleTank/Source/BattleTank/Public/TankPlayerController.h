// Copyright Replitz Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingComponentReference);

private:
	UFUNCTION()
	void OnTankDeath();

	void AimTowardsCrosshair();

	bool GetSightRayLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f; 
	
	UPROPERTY(EditDefaultsOnly) 
	float CrosshairYLocation = 0.33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection, FVector& OutLookLocation) const;

	UPROPERTY(EditDefaultsOnly)
	int32 LineTraceRange = 400000;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector LookLocation, FVector& OutHitLocation) const;

	UTankAimingComponent* AimingComponent;
};
