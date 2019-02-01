// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "TimerManager.h"
#include "PawnHero.generated.h"

class AHeroBullet;
class ACPPSpaceInvadersGameModeBase;

UCLASS()
class CPPSPACEINVADERS_API APawnHero : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnHero();

	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollision{ nullptr };

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh{ nullptr };

	USceneComponent* SceneRoot{ nullptr };

	UPROPERTY(EditAnywhere)
	UFloatingPawnMovement* MovementComponent;

	UPROPERTY(EditAnywhere)
		USceneComponent* BulletSpawnLocation {nullptr};

	UPROPERTY(EditAnywhere, Category="Spawning")
		TSubclassOf<AHeroBullet> BulletToSpawn;

	ACPPSpaceInvadersGameModeBase* GameModeRef;

	//For � gi siste kula tid til � treffe m�l f�r test
	FTimerHandle WinConditionTimer;

private:
	void Shoot();

	void Move(float AxisValue);

	void CheckWinCondition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
