// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	/*if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller missing"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing %s"), *ControlledTank->GetName());
	}*/
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Player Tank %s"), *PlayerTank->GetName());
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}
