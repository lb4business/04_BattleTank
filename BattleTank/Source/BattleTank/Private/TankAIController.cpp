// Copyright 2019 Leonid Burylov

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetControlledTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player tank: %s"), *(PlayerTank->GetName()));
	}
}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//TODO tell a tank to aim at this point
	ATank* PlayerTank = GetPlayerTank();

	if (PlayerTank != nullptr)
	{
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //What tank are we controlling? TANK is a child of PAWN, so we use Cast to get Tank from Pawn
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

