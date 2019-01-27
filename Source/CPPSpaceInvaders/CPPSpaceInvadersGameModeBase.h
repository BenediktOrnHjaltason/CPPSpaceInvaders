// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/World.h"
#include "PawnEnemy.h"
#include "CPPSpaceInvadersGameModeBase.generated.h"


class APawnEnemy;
/**
 * 
 */
UCLASS()
class CPPSPACEINVADERS_API ACPPSpaceInvadersGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
		TSubclassOf<APawnEnemy> EnemyPawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
