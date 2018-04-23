// Copyright Jose Lloret 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * UStaticMeshComponent is created to elevate Tank Barrel in c++
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0.0f;
};
