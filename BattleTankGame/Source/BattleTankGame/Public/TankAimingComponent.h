// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward declaration
class UTankBarrel; 
//Parameters for barrel properties and elevate method

UCLASS(meta=(BlueprintSpawnableComponent) )
class BATTLETANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation,float LaunchSpeed);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	// TODO set turrent referene

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	

private:	
	// Called every frame
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
		
};
