// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachine/StateComponent.h"
#include "StateKnight.h"
#include "StateIdleKnight.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API UStateIdleKnight : public UStateKnight
{
	GENERATED_BODY()
	
	
public:
	void pressLightHit();
	void pressFrontKick();
	void pressBlock();

	void leave() override;
	void enter() override;
	void update(float DeltaTime) override;
};
