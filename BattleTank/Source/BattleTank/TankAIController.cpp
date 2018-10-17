// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller posessing %s"), (*ControlledTank->GetName()));
		if (PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s found player tank"), (*ControlledTank->GetName()));
		}
	}

	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) return nullptr;
	return Cast<ATank>(PlayerPawn);
}



