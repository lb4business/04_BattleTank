// Copyright 2019 Leonid Burylov

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision")) //hide from designers category Collision in Blueprint inspector
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreePerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevateDegree = 30;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevateDegree = 0;
	
};
