// Copyright Replitz Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

protected:
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Aiming)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:	
	void AimAt(FVector HitLocation);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 10000.f;

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime = 3.f;

	double LastFireTime = 0.00;
};
