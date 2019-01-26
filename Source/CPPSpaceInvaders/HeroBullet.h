// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "HeroBullet.generated.h"

UCLASS()
class CPPSPACEINVADERS_API AHeroBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeroBullet();

	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh = nullptr;

	UPROPERTY(EditAnywhere)
		USceneComponent* SceneComponent = nullptr;

	UPROPERTY(EditAnywhere)
		USphereComponent* SphereCollision = nullptr;




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
