// Copyright 2019 Leonid Burylov

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup") //with this macro we dont need to Definition of the method
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

	virtual void SetPawn(APawn *InPawn) override;

private:
	//relative position of crosshair
	UPROPERTY(EditAnywhere) //PROPERTY is a programmed cut-and-paste, happens BEFORE the code is compiled
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere) //PROPERTY is a programmed cut-and-paste, happens BEFORE the code is compiled
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere) //PROPERTY is a programmed cut-and-paste, happens BEFORE the code is compiled
	float LineTraceRange = 1000000.f;

	//Start the tank moving the barrel so that a shot would hit where 
	//crosshair intersects world.
	void AimTowardsCrosshair();

	//Return OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UFUNCTION()
	void OnPossessedTankDeath();

	//Get
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector& HitLocation, FVector& LookDirection) const;
};
