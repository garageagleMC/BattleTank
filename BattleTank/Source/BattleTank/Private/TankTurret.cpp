// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation = GetRelativeRotation().Yaw + RotationChange;

	UE_LOG(LogTemp, Display, TEXT("%f"), NewRotation);

	SetRelativeRotation(FRotator(0.f, 0.f, NewRotation));
}