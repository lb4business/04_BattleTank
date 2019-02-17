// Copyright 2019 Leonid Burylov

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

//Forward declaraction
class UTankBarrel; 
class UTankTurret;
class AProjectile;

// Holds barrel's parameters and Elevate method 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);

	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector WorldSpaceAim);

	UFUNCTION(BlueprintCallable)
	void Fire();

	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Locked;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;*/

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	//remove as it moving shooting to aiming component
	UPROPERTY(EditAnywhere, Category = Firing) //Category is a section in Blueprint Details
	float LaunchSpeed = 8000; // launch speed in cm/s

	private:
	UPROPERTY(EditDefaultsOnly, Category = Firing) //Category is a section in Blueprint Details
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = Firing) //Category is a section in Blueprint Details
	//UClass* ProjectileBlueprint; // Alternative https://api.unrealengine.com/INT/API/Runtime/CoreUObject/Templates/TSubclassOf/index.html
	TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0;
};
