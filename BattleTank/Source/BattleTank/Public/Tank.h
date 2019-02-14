// Copyright 2019 Leonid Burylov

#pragma once

#include "CoreMinimal.h"
//#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward declaraction
class UTankBarrel; 
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();	
	
	void AimAt(FVector HitLocation);

	UTankBarrel* Barrel = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent * TankAimingComponent = nullptr;

private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing) //Category is a section in Blueprint Details
	float LaunchSpeed = 100000; // TODO find a sensible default
};
