// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPSpaceInvadersGameModeBase.h"

void ACPPSpaceInvadersGameModeBase::BeginPlay()
{
	UWorld* World = GetWorld();

	if (World)
	{	
		
		float HorizontalIncrement=100.f;
		float VerticalIncrement(70.f);
		FVector StartLocation(90.f, -360.f, 40.f);
		FVector SpawnLocation(90.f, -360.f, 40.f);

		for (int i=0; i<5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				SpawnLocation.Y += VerticalIncrement * j;

				

				World->SpawnActor<APawnEnemy>(EnemyPawn, SpawnLocation, FRotator(0.f, 0.f, 0.f));
			}
		SpawnLocation.Y = StartLocation.Y;
		SpawnLocation.X += VerticalIncrement *(i+1);

		}
	}

}