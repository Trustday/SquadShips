// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_DisparoActor.h"
#include "New_Protagonista.h"
#include "GameFramework/PlayerController.h"


// Sets default values
ACPP_DisparoActor::ACPP_DisparoActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_DisparoActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_DisparoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
void ACPP_DisparoActor::InflictDamage()
{
	ANew_Protagonista* PlayerController = ANew_Protagonista::ANew_Protagonista();
	if (PlayerController != nullptr)
	{
		// Perform a trace @See LineTraceSingle  
		FHitResult TraceResult(ForceInit);
		//TraceHitForward(PlayerController, TraceResult);

		// If the trace return an actor, inflict some damage to that actor  
		AActor* ImpactActor = TraceResult.GetActor();
		if ((ImpactActor != nullptr) && (ImpactActor != this))
		{
			// Create a damage event  
			TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
			FDamageEvent DamageEvent(ValidDamageTypeClass);

			const float DamageAmount = 60.0f;
			ImpactActor->TakeDamage(DamageAmount, DamageEvent, PlayerController, this);
		}
	}
}
*/