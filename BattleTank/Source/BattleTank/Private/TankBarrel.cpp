// Copyright 2019 Leonid Burylov

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame
	//Given a max elevation speed and the frame time
	//UE_LOG(LogTemp, Warning, TEXT("Barrel elevate called: %f"), *DegreesPerSecond);
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = FMath::Clamp
	(
		RelativeRotation.Pitch + ElevationChange,
		MinElevateDegree,
		MaxElevateDegree);

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}

