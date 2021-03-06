// Copyright Replitz Studios

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 5.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevation = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevation = 30.f;
};
