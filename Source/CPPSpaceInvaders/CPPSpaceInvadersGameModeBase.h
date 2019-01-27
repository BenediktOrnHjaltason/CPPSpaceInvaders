// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//#include "PawnEnemy.h"
#include "CPPSpaceInvadersGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CPPSPACEINVADERS_API ACPPSpaceInvadersGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


		TSubclassOf<class UPawnEnemy> EnemyPawn;
};
