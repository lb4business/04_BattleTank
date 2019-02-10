// Copyright 2019 Leonid Burylov

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("Player controller begin play"));
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //What tank are we controlling? TANK is a child of PAWN, so we use Cast to get Tank from Pawn
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//Get world location of linetrace through crosshair
	//If it hits the landscape
		//tell controlled tank to aim at this point

}


