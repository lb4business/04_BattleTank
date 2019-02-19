// Copyright 2019 Leonid Burylov

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/**
Track is used to set maximum driving force
 */
UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = ("Collision")) //hide from designers category Collision in Blueprint inspector
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	//Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000.0f; //assume 40T tank and 1g acceleration

private:
	UTankTrack();

	//virtual void BeginPlay() override;

	TArray< ASprungWheel*> GetWheels() const;

	void ApplySidewaysForce();

	void DriveTrack(float CurrentThrottle);

	//float CurrentThrottle;

	//UFUNCTION()
	//void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
