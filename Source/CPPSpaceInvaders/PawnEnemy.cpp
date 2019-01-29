// Fill out your copyright notice in the Description page of Project Settings.

// OBS!!!!! Dette er ikke en pawn. Jeg fucka opp da jeg skulle lage den.
// Det er en Actor

#include "PawnEnemy.h"
#include "HeroBullet.h"

class AHeroBullet;

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
	
	

	//Starter på 4 ift at gruppen spawner på midten.
	MoveIncrementer = 4;

	MovementDirection.Y = 100.f;
}

// Called when the game starts or when spawned
void APawnEnemy::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &APawnEnemy::OnOverlapBegin);

	GetWorldTimerManager().SetTimer(MoveTimer, this, &APawnEnemy::MoveAround, 2.f, true);
	
}

// Called every frame
void APawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APawnEnemy::MoveAround()
{	

	switch (MoveIncrementer)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	

		SetActorLocation(GetActorLocation() + MovementDirection);
		++MoveIncrementer;
	
		break;
	
	case 7:
	
		SetActorLocation(GetActorLocation() + FVector(-70.f, 0.f, 0.f));
		
	
		MovementDirection.Y *= -1;
		MoveIncrementer = 1;
		break;
	}
}

void APawnEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(AHeroBullet::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap kjorer"))
		this->Destroy();
		OtherActor->Destroy();
	}
}
