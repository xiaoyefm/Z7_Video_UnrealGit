// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeOne.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ACubeOne::ACubeOne()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphereRadius = 100.f;

	MyMeshCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Cube"));
	MyMeshCube->SetSimulatePhysics(true);
	MyMeshCube->SetupAttachment(RootComponent);

	MyCollision = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere"));
	MyCollision->InitSphereRadius(sphereRadius);
	RootComponent = MyCollision;

	MyCollision->OnComponentBeginOverlap.AddDynamic(this, &ACubeOne::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ACubeOne::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeOne::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeOne::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
}

