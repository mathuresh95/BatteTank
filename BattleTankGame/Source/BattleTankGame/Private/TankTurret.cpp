// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	float RotationChange = RelativeSpeed * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	float RawRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RawRotation, 0));
	//UE_LOG(LogTemp, Warning, TEXT("Turret Test"));
}
