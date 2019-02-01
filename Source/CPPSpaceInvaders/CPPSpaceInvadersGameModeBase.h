// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/World.h"
#include "PawnEnemy.h"
#include "Components/TextRenderComponent.h"
#include "TimerManager.h"
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

		ACPPSpaceInvadersGameModeBase();

		UPROPERTY(EditAnywhere)
		TSubclassOf<APawnEnemy> EnemyPawn;

		UPROPERTY(BlueprintReadOnly)
			int CurrentAmmo;

		UPROPERTY(BlueprintReadOnly)
			int StartAmmo;

		UPROPERTY(BlueprintReadOnly)
			int CurrentEnemyCount;

		UPROPERTY(BlueprintReadOnly)
			int StartEnemyCount;

		UTextRenderComponent* ScreenText = nullptr;


		//For at testen som går etter hvert skudd skal gi kula tid til å treffe fienden
		FTimerHandle WinConditionTimer;


		UFUNCTION(BlueprintImplementableEvent)
		void TextHUDLoose();

		UFUNCTION(BlueprintImplementableEvent)
			void TextHUDWin();


		void DecrementEnemies();

		void DecrementAmmo();

		void CheckWinConditions();

		UFUNCTION(BlueprintImplementableEvent)
		void BlueprintTimer();

		int GetAmmo() { return CurrentAmmo; }



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
