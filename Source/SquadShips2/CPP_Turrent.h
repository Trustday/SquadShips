// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPP_Turrent.generated.h"

UCLASS()
class SQUADSHIPS2_API ACPP_Turrent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties.
	ACPP_Turrent(const FObjectInitializer& oi);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		class USphereComponent* radio_vision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
		float health;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnDeath();
	void OnDeath_Implementation();

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
