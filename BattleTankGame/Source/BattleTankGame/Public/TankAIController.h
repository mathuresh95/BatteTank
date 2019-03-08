// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	ATank* ControlledTank = nullptr;
	ATank* PlayerTank = nullptr;

	virtual void BeginPlay() override;

	
};