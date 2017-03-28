// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachine/States/Knight/StateKnight.h"
#include "StateKnightBlock.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API UStateKnightBlock : public UStateKnight
{
	GENERATED_BODY()

public:
	void pressLightHit();
	void pressFrontKick();
	void releaseBlock();

	void leave() override;
	void enter() override;
	void update(float DeltaTime) override;
};
