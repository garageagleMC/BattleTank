// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward(float Throttle)
{
	UE_LOG(LogTemp, Display, TEXT("Forward throttle at %f"), Throttle);
}