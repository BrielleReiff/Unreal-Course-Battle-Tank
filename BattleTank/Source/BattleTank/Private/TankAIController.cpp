// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank) {
        UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank."));
    }
    else
    {
        UE_LOG(LogTemp, Warning,
               TEXT("AIController found player: %s"),
               *PlayerTank->GetName());
    }
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (GetPlayerTank())
    {
        // TODO: Move towards player

        // Aim at player
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
        // Fire if ready
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    return Cast<ATank>(PlayerPawn);
}
