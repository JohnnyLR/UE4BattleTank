// Copyright Jose Lloret 2018

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);

		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}
}

void ATankAIController::OnPossedTankDeath()
{
	if (!ensure(GetPawn())) { return; }

	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent)) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if(AimingComponent->GetFiringState() == EFiringState::Locked)
	AimingComponent->Fire();
}
