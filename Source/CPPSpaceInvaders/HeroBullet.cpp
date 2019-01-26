// Fill out your copyright notice in the Description page of Project Settings.

#include "HeroBullet.h"

// Sets default values
AHeroBullet::AHeroBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));

	RootComponent = SceneComponent;

	SphereCollision->SetupAttachment(SceneComponent);
	FVector SphereCenter{ 0.f, 0.f, 0.f };
	

	//StaticMesh->SetStaticMesh();





}

// Called when the game starts or when spawned
void AHeroBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

