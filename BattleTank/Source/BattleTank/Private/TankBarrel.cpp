// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond) const
{
	UE_LOG(LogTemp, Display, TEXT("%s's barrel moving at speed %f"), *GetOwner()->GetName(), DegreesPerSecond);
}