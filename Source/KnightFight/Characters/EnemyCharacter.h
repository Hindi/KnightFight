// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Characters/KnightFightCharacter.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class KNIGHTFIGHT_API AEnemyCharacter : public AKnightFightCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
