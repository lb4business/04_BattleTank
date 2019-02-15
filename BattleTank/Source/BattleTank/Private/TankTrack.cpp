// Copyright 2019 Leonid Burylov

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	if (Throttle == 0.0f) { return; }
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	//TODO clamp actual throttle value so player cant over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

