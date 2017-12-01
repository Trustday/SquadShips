// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Turrent.h"
#include "New_Protagonista.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"



// Sets default values
ACPP_Turrent::ACPP_Turrent(const FObjectInitializer& oi)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	radio_vision = oi.CreateDefaultSubobject<USphereComponent>(this, TEXT("sight"));
	radio_vision->SetupAttachment(RootComponent);
	radio_vision->SetSphereRadius(15000);
}

// Called when the game starts or when spawned
void ACPP_Turrent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Turrent::Tick(float delta)
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
		//AddMovementInput(vplayer, 20 * delta);
		FRotator heading = vplayer.Rotation();
		heading.Pitch = 0;
		RootComponent->SetWorldRotation(heading);
		OnDeath();
		//UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}

}

void ACPP_Turrent::OnDeath_Implementation() {}

/* Called to bind functionality to input
void ACPP_Turrent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}*/

