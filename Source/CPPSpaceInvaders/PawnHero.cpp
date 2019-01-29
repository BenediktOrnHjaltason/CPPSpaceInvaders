// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnHero.h"
#include "HeroBullet.h"
#include "Engine/World.h"
#include "CPPSpaceInvadersGameModeBase.h"

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
	BulletSpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnLocation"));

	StaticMesh->SetupAttachment(SceneRoot);
	BulletSpawnLocation->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawned
void APawnHero::BeginPlay()
{
	Super::BeginPlay();
	
	GameModeRef = Cast<ACPPSpaceInvadersGameModeBase>(GetWorld()->GetAuthGameMode());
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
	InputComponent->BindAction("Shoot", IE_Pressed, this, &APawnHero::Shoot);
	
}

void APawnHero::Shoot()
{
	if (BulletSpawnLocation && GameModeRef->GetAmmo() > 0)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			//FVector SpawnLocation = BulletSpawnLocation->GetComponentLocation();

			FVector SpawnLocation = BulletSpawnLocation->GetComponentLocation();
			UE_LOG(LogTemp, Warning, TEXT("SpawnLocation gotten: %s"), *SpawnLocation.ToString())

			World->SpawnActor<AHeroBullet>(BulletToSpawn, SpawnLocation, FRotator(0.f,0.f,0.f));

			GameModeRef->DecrementAmmo();
		}
	}
}

void APawnHero::Move(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}