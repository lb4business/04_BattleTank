// Copyright 2019 Leonid Burylov

#pragma once
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:


protected:
	//How close can AI tank get to the player
	UPROPERTY(EditDefaultsOnly, Category = Firing) //Category is a section in Blueprint Details
	float AcceptanceRadius = 5000;
};
