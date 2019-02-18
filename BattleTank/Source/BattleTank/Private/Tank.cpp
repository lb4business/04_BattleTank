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


void ATank::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = StartingHealth;
}


float ATank::TakeDamage
(
	float DamageAmount,
	struct FDamageEvent const & DamageEvent,
	class AController * EventInstigator,
	AActor * DamageCauser
)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);


	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}

	//UE_LOG(LogTemp, Warning, TEXT("Damage amaunt = %i , DamageToApply = %i"), DamagePoints, DamageToApply);

	return DamageAmount;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}
