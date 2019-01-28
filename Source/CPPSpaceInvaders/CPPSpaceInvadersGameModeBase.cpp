// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPSpaceInvadersGameModeBase.h"

void ACPPSpaceInvadersGameModeBase::BeginPlay()
{
	UWorld* World = GetWorld();

	if (World)
	{	
		
		float HorizontalIncrement(100.f);
		float VerticalIncrement(-70.f);
		float HorizontalStart(-350.f);
		FVector SpawnLocation(90.f, -360.f, 40.f);

		for (int i=0; i<5; ++i)
		{
			SpawnLocation.X += VerticalIncrement;
			for (int j = 0; j < 11; ++j)
			{
				SpawnLocation.Y += HorizontalIncrement;

				UE_LOG(LogTemp, Warning, TEXT("Inside spawning loops"))

				World->SpawnActor<APawnEnemy>(EnemyPawn, SpawnLocation, FRotator(0.f, 0.f, 0.f));
			}
			SpawnLocation.Y = HorizontalStart;
		

		}
	}

}