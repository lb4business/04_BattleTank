// Copyright 2019 Leonid Burylov

#pragma once
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

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
};
