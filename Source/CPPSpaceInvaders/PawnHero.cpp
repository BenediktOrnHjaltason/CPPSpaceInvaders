// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnHero.h"

// Sets default values
APawnHero::APawnHero()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	RootComponent = BoxCollision;



}

// Called when the game starts or when spawned
void APawnHero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

