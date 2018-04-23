// Copyright Jose Lloret 2018

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class APawn;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 1000.0f;

public:
	virtual void Tick(float DeltaTime) override;

private:
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossedTankDeath();
};
