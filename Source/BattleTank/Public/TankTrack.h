// Copyright Jose Lloret 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * UStaticMeshComponent is created to throttle Tank Track in c++
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UTankTrack();

	// Max force per track
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000.0f;

	// Set a throttle between -1 to 1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

protected:
	virtual void BeginPlay() override;

private:
	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	float CurrentThrottle = 0.0f;
};
