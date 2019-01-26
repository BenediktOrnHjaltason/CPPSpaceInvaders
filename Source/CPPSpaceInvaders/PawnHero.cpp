// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnHero.h"

// Sets default values
APawnHero::APawnHero()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

	StaticMesh->SetupAttachment(SceneRoot);

	

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

	InputComponent->BindAxis("MoveSideways", this, &APawnHero::Move);
	
}

void APawnHero::Move(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}