// Fill out your copyright notice in the Description page of Project Settings.

#include "New_Protagonista.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"
#include "CPP_DisparoActor.h"

// Sets default values
ANew_Protagonista::ANew_Protagonista()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	//Sphere->SetupAttachment(RootComponent);
	//Sphere->SetSphereRadius(200);
	health = 100.0f;
	energy = 100.0f;
}

// Called when the game starts or when spawned
void ANew_Protagonista::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANew_Protagonista::Tick(float DeltaTime)
{
	if (health <= 0.f) 
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANew_Protagonista::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/*
float ANew_Protagonista::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	// Call the base class - this will tell us how much damage to apply  
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		health -= ActualDamage;
		// If the damage depletes our health set our lifespan to zero - which will destroy the actor  
		if (health <= 0.f)
		{
			SetLifeSpan(0.001f);
		}
	}

	return ActualDamage;
}*/