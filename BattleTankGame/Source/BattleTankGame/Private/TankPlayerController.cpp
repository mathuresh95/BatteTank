// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

#define OUT

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
	/*UE_LOG(LogTemp, Warning, TEXT("TICK TICK"));*/
	AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation = FVector(0,0,0); //OUT Parameter // intialised just to check
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation : %s"), *HitLocation.ToString());
		
		//if it hits the landscape
		//aim the barrel at the hit spot
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//get world location using cross hair by linetracing
	HitLocation = FVector(1.0f);
	return true;
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

