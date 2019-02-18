// Copyright 2019 Leonid Burylov

#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnPosessedTankDeath();

protected:
	virtual void SetPawn(APawn *InPawn) override;
	//How close can AI tank get to the player
	UPROPERTY(EditDefaultsOnly, Category = Firing) //Category is a section in Blueprint Details
	float AcceptanceRadius = 5000;
};
