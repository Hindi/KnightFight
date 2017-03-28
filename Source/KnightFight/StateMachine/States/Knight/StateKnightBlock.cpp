// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "StateKnightBlock.h"
#include "Characters/KnightFightCharacter.h"
#include "StateMachine/StateMachineComponent.h"

#include "Engine.h"




void UStateKnightBlock::leave()
{
	animInstance->stopBlock();
}

void UStateKnightBlock::enter()
{
	character->playMontage(animMontage);
}

void UStateKnightBlock::update(float DeltaTime)
{
	if (animInstance->isTimeToLoopBlock())
	{
		character->playMontage(animMontage, "idleStart");
	}

	if (animInstance->blockFinished())
	{
		stateMachine->changeState(TEXT("Idle"));
	}
}

void UStateKnightBlock::pressLightHit()
{
	stateMachine->changeState(TEXT("Combo1"));
}

void UStateKnightBlock::pressFrontKick()
{
	stateMachine->changeState(TEXT("FrontKick"));
}

void UStateKnightBlock::releaseBlock()
{
	character->stopMontage(animMontage);
	character->playMontage(animMontage, "idleEnd");
	stateMachine->changeState(TEXT("Idle"));
}