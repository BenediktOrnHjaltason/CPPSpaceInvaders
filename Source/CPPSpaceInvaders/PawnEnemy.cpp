// Fill out your copyright notice in the Description page of Project Settings.

// OBS!!!!! Dette er ikke en pawn. Jeg fucka opp da jeg skulle lage den.
// Det er en Actor

#include "PawnEnemy.h"

// Sets default values
APawnEnemy::APawnEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = SceneRoot;
	Mesh->SetupAttachment(SceneRoot);
	BoxCollision->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void APawnEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

