// Copyright Replitz Studios

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UTankTrack();

	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float MaxDrivingForce = 30000000.f;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	float CurrentThrottle = 0.f;
};
