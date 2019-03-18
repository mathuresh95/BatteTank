// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maximum driving force and to apply forces to driving the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category = Input)
	void SetThrottle(float Throttle);

	//Max force per tank in new newtons
	UPROPERTY(EditAnywhere)
	float TrackMaxDrivingForce = 400000.00f; //tank is 40 ton with 1g acceleration
	
};
