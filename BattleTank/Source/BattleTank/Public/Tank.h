// Copyright 2019 Leonid Burylov

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward declaraction
class UTankBarrel; 
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable)
	void Fire();	
	
	void AimAt(FVector HitLocation);

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent * TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent * TankMovementComponent = nullptr;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = Firing) //Category is a section in Blueprint Details
	float LaunchSpeed = 8000; // launch speed in cm/s

	UPROPERTY(EditDefaultsOnly, Category = Firing) //Category is a section in Blueprint Details
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = Firing) //Category is a section in Blueprint Details
	//UClass* ProjectileBlueprint; // Alternative https://api.unrealengine.com/INT/API/Runtime/CoreUObject/Templates/TSubclassOf/index.html
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local barrel reference 
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
