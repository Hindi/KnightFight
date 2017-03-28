// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachine/States/Knight/StateKnight.h"
#include "StateKnightCombo2.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API UStateKnightCombo2 : public UStateKnight
{
	GENERATED_BODY()

public:
	void pressLightHit();

	void leave() override;
	void enter() override;
	void update(float DeltaTime) override;

private:
	bool shouldContinueCombo;
};
