// Fill out your copyright notice in the Description page of Project Settings.

#include "HeroBullet.h"

// Sets default values
AHeroBullet::AHeroBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));

	RootComponent = StaticMesh;
	
	SphereCollision->SetupAttachment(StaticMesh);

	ProjectileMovement->ProjectileGravityScale = 0;
	ProjectileMovement->InitialSpeed = BulletInitialSpeed;
	ProjectileMovement->MaxSpeed = BulletMaxSpeed;
}

// Called when the game starts or when spawned
void AHeroBullet::BeginPlay()
{
	Super::BeginPlay();

		FTimerHandle MemberTimerHandle;
        GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AHeroBullet::DestroyBullet, 3.0f, false);
		
}

// Called every frame
void AHeroBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHeroBullet::DestroyBullet()
{
	this->Destroy();
}
