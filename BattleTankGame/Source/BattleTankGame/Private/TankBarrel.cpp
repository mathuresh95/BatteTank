// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include"Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//move barrel thr right amount this frame
	//give a max elevation speed and fthe frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch+ElevationChange; //unclamped elevation
	float Elevation = FMath::Clamp <float> (RawNewElevation, MinElevationInDegress, MaxElevationInDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));



	auto Time = GetWorld()->DeltaTimeSeconds;
	UE_LOG(LogTemp,Warning,TEXT("%f Elevate is being called and the raw elevation is %f"),Time,RawNewElevation)
	
}