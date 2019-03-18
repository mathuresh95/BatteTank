// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include"Engine/World.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*UE_LOG(LogTemp, Warning, TEXT("TICK TICK"));*/
	AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation = FVector(0, 0, 0); //OUT Parameter // intialised just to check
	if (GetSightRayHitLocation(HitLocation))
	{
		/*UE_LOG(LogTemp, Warning, TEXT("HitLocation : %s"), *HitLocation.ToString());*/
		GetControlledTank()->AimAt(HitLocation);

		//if it hits the landscape
		//aim the barrel at the hit spot
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//get world location using cross hair by linetracing

	//Crosshair position in pixels
	int32 ViewportSizeX, ViewPortSizeY;
	GetViewportSize(ViewportSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(CrossHairXLocation*ViewportSizeX, CrossHairYLocation*ViewPortSizeY);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line trace along the look direction and check hit
		GetLookVectorHitLocation(LookDirection,HitLocation);

	}

	return true;
}

	//Deproject the screen position of the crosshair to the world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const
{
	FVector CameraWorldLocation; //not using
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection*LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
	
	
}




ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

