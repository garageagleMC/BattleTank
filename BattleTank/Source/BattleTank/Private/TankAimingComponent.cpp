// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector WorldAimLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector LaunchVelocity(0.f);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FCollisionResponseParams ResponseParams = FCollisionResponseParams();
	TArray<AActor*> ActorsToIgnore = { Cast<AActor>(Barrel) };

	if (UGameplayStatics::SuggestProjectileVelocity
		(
		this,
		LaunchVelocity,
		StartLocation,
		WorldAimLocation,
		LaunchSpeed,
		false,
		0.f,
		0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		ResponseParams,
		ActorsToIgnore,
		false
		)
	)
	{
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Display, TEXT("%s aiming at %s"), *GetOwner()->GetName(), *AimDirection.ToString());
	}

}