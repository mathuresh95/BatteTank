// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *
 */
UCLASS(meta = (BlueprintSpawnableComponent))/*,hidecategories = "Collision"*/
class BATTLETANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed); //-1 is max downward movement and vice versa


private:
	UPROPERTY(EditAnywhere,Category = Setup)
		float MaxDegreesPerSecond = 5.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationInDegrees = 40.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationInDegress = 0.0f;
		

};
