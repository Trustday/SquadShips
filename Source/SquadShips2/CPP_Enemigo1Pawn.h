// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SquadShips2Pawn.h"
#include "CPP_Enemigo1Pawn.generated.h"

/**
 * 
 */
UCLASS()
class SQUADSHIPS2_API ACPP_Enemigo1Pawn : public ASquadShips2Pawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties.
	ACPP_Enemigo1Pawn(const FObjectInitializer& oi);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		class USphereComponent* radio_vision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
		float health;

	int heading;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float delta) override;


	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnDeath();
	void OnDeath_Implementation();

	//virtual void MyEvent();

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
};
