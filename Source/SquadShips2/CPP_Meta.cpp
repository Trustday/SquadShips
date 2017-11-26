// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Meta.h"
#include "New_Protagonista.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"


// Sets default values
ACPP_Meta::ACPP_Meta(const FObjectInitializer& oi)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	radio_meta = oi.CreateDefaultSubobject<USphereComponent>(this, TEXT("sight"));
	radio_meta->SetupAttachment(RootComponent);
	radio_meta->SetSphereRadius(1000);
}

// Called when the game starts or when spawned
void ACPP_Meta::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ACPP_Meta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ANew_Protagonista* player = Cast<ANew_Protagonista>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (player == NULL)
		return;
	FVector vplayer = player->GetActorLocation() - GetActorLocation();
	float distancia = vplayer.Size();
	if (distancia <= radio_meta->GetScaledSphereRadius())
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
}

// Called to bind functionality to input
void ACPP_Meta::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

