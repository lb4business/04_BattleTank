// Copyright 2019 Leonid Burylov

#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//auto TankTame = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s KISA Tank C++ Construct"), *TankTame);

	//No need to protect poiners as added on construction
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Moving component"));
}


