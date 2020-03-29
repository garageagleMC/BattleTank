// Copyright Replitz Studios

#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CurrentHealth = MaxHealth;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	int DamageToApply = FMath::Clamp<int>(FMath::RoundToInt(DamageAmount), 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0) {
		// die
	}

	return DamageToApply;
}
