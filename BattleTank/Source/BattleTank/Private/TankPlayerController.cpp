// Copyright 2019 Leonid Burylov

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //What tank are we controlling? TANK is a child of PAWN, so we use Cast to get Tank from Pawn
}


