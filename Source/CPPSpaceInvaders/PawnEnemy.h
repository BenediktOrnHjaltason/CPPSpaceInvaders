// Fill out your copyright notice in the Description page of Project Settings.

// OBS!!!!! Dette er ikke en pawn. Jeg fucka opp da jeg skulle lage den.
// Det er en Actor

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "PawnEnemy.generated.h"

UCLASS()
class CPPSPACEINVADERS_API APawnEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APawnEnemy();

	UPROPERTY(EditAnywhere)
		USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	FTimerHandle MoveTimer;

	//Til Move-funksjonen
	int8 MoveIncrementer;

	//Starter med høyre/positiv x
	FVector MovementDirection;
	   
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveAround();

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult &SweepResult);
	

};
