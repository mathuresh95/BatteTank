// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not controlling Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlling Tank %s"), *ControlledTank->GetName());
	}
	
}

void ATankPlayerController::Tick(float DeltaTime) 
{
	Super::Tick( DeltaTime );
	UE_LOG(LogTemp, Warning, TEXT("TICK TICK"));
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank)
	{
		return;
	}

	//get world location using cross hair by linetracing
	//if it hits the landscape
	//aim the barrel at the hit spot
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

