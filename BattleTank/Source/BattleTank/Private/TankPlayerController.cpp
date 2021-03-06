// Copyright 2019 Leonid Burylov

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}


void ATankPlayerController::SetPawn(APawn *InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PosessedTank = Cast<ATank>(InPawn);
		if (!ensure(PosessedTank)) { return; }

		//Subscribe to tank destroy event
		PosessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossessedTankDeath);
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	AimTowardsCrosshair();
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation; //OUT parameter
	bool BGotHitLocation = GetSightRayHitLocation(HitLocation);

	if (BGotHitLocation) //has a "side-effect" of line-tracing
	{
		//TODO tell a tank to aim at this point
		AimingComponent->AimAt(HitLocation);
	}
}

//Get world location of literace through crosshair, trie if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Screen location: %s"), *(ScreenLocation.ToString()));

	//"De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *(LookDirection.ToString()));
		return GetLookVectorHitLocation(HitLocation, LookDirection);
	}

	//Line-trace along that look direction, and see what we hit (up to max range)
	return false;
}

void ATankPlayerController::OnPossessedTankDeath()
{
	//if (!ensure(GetPawn())) { return; }
	StartSpectatingOnly();
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation, FVector& LookDirection) const
{
	FHitResult HitResult;

	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Camera)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}

	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return (DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection));

}


