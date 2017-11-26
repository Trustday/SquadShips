// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Enemigo1Pawn.h"
#include "New_Protagonista.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
ACPP_Enemigo1Pawn::ACPP_Enemigo1Pawn(const FObjectInitializer& oi)
{
	PrimaryActorTick.bCanEverTick = true;
	heading = 1;
	health = 1.0f;
	radio_vision = oi.CreateDefaultSubobject<USphereComponent>(this, TEXT("sight"));
	radio_vision->SetupAttachment(RootComponent);
	radio_vision->SetSphereRadius(2500);
	setCurrentForwardSpeed(400.f); 
}



// Called when the game starts or when spawned
void ACPP_Enemigo1Pawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPP_Enemigo1Pawn::Tick(float delta)
{
	Super::Tick(delta);
	ANew_Protagonista* player = Cast<ANew_Protagonista>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (player == NULL)
		return;
	FVector vplayer = player->GetActorLocation() - GetActorLocation();
	float distancia = vplayer.Size();
	if (distancia <= radio_vision->GetScaledSphereRadius())
	{
		vplayer.Normalize();
		AddMovementInput(vplayer, 20 * delta);
		FRotator heading = vplayer.Rotation();
		//heading.Pitch = 0;
		RootComponent->SetWorldRotation(heading);
		OnDeath();
		//UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
}

void ACPP_Enemigo1Pawn::OnDeath_Implementation() {}
//void APawn::MoveIgnoreActorAdd(AActor * ACPP_DisparoActor) {}
