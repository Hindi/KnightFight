// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachine/States/Knight/StateKnight.h"
#include "StateKnightFrontKick.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API UStateKnightFrontKick : public UStateKnight
{
	GENERATED_BODY()

public:
	void useLightHit();

	void leave() override;
	void enter() override;
	void update(float DeltaTime) override;

private:
	bool shouldContinueCombo;
};
