// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachine/StateMachineComponent.h"
#include "Animations/KnightAnimInstance.h"
#include "StateMachineKnight.generated.h"


/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API UStateMachineKnight : public UStateMachineComponent
{
	GENERATED_BODY()
	
public:
	UStateMachineKnight();

protected:
	virtual void BeginPlay() override;
	
	
};
