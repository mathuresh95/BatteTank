// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void RotateTurret(float RelativeSpeed);


private:
	UPROPERTY(EditAnywhere,Category = Setup)
		float MaxDegreesPerSecond = 20.0f;
	/*UPROPERTY(EditAnywhere)
		float MaxRotationDegrees = 10.0f;
	UPROPERTY(EditAnywhere)
		float MinRotationDegrees = 0.0f;*/

};
