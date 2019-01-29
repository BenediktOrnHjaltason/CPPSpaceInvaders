// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPSpaceInvadersGameModeBase.h"

ACPPSpaceInvadersGameModeBase::ACPPSpaceInvadersGameModeBase()
{
	StartAmmo = 60;
	CurrentAmmo = StartAmmo;

	//Inkrementeres i spawnfunksjonen under
	CurrentEnemyCount = 0;
}

void ACPPSpaceInvadersGameModeBase::BeginPlay()
{
	UWorld* World = GetWorld();

	if (World)
	{	
		
		float HorizontalIncrement(100.f);
		float VerticalIncrement(-70.f);
		float HorizontalStart(-600.f);
		FVector SpawnLocation(90.f, -600.f, 40.f);

		for (int i=0; i<5; ++i)
		{
			SpawnLocation.X += VerticalIncrement;
			for (int j = 0; j < 11; ++j)
			{
				SpawnLocation.Y += HorizontalIncrement;

				

				World->SpawnActor<APawnEnemy>(EnemyPawn, SpawnLocation, FRotator(0.f, 0.f, 0.f));
				CurrentEnemyCount++;
			}
			SpawnLocation.Y = HorizontalStart;
		

		}

		UE_LOG(LogTemp, Warning, TEXT("EnemyCount is %d"), CurrentEnemyCount)
			StartEnemyCount = CurrentEnemyCount;
	}

}

void ACPPSpaceInvadersGameModeBase::DecrementEnemies()
{
	--CurrentEnemyCount;
	UE_LOG(LogTemp, Warning, TEXT("EnemyCount is now %d"), CurrentEnemyCount)
}

void ACPPSpaceInvadersGameModeBase::DecrementAmmo()
{
	--CurrentAmmo;
}



