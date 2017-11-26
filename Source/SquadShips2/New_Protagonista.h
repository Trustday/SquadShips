// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "New_Protagonista.generated.h"

UCLASS()
class SQUADSHIPS2_API ANew_Protagonista : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANew_Protagonista();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float energy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser);
};
