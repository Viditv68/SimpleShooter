// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <SimpleShooter/ShooterCharacter.h>


void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehaviour != nullptr)
	{
		RunBehaviorTree(AIBehaviour);
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}

}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AShooterAIController::IsDead() const
{
	AShooterCharacter* controlledCharacter =  Cast<AShooterCharacter>(GetPawn());
	if (controlledCharacter != nullptr)
	{
		return controlledCharacter->IsDead();
	}
	return true; 
}

