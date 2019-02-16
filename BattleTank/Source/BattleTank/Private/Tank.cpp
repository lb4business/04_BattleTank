// Copyright 2019 Leonid Burylov

#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto TankTame = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s KISA Tank C++ Construct"), *TankTame);

	//No need to protect poiners as added on construction
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Moving component"));
}


void ATank::BeginPlay()
{
	Super::BeginPlay(); //Needed for BP Begin Play to run

	auto TankTame = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s KISA Tank C++ BeginPlay"), *TankTame);
}


void ATank::AimAt(FVector HitLocation)
{
	//auto OurTankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s"), *OurTankName, *HitLocation.ToString());

	if (!ensure(TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }

	bool BIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (BIsReloaded)
	{
		auto BarrelLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto BarrelRotation = Barrel->GetSocketRotation(FName("Projectile"));
		//Spawn a projectile at the socket location of the barrel
		AProjectile *Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, BarrelLocation, BarrelRotation);

		if (!Projectile)
		{
			auto OurTankName = GetName();
			//UE_LOG(LogTemp, Warning, TEXT("Projectile is not assigned for tank: %s"), *OurTankName);
			return;
		}

		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

