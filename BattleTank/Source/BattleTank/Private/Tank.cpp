// Copyright 2019 Leonid Burylov

#include "Tank.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//No need to protect poiners as added on construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation)
{
	//auto OurTankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s"), *OurTankName, *HitLocation.ToString());

	if (TankAimingComponent != nullptr)
	{
		TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	}
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

