// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "StateIdleKnight.h"
#include "StateMachine/StateMachineComponent.h"





void UStateIdleKnight::leave()
{

}

void UStateIdleKnight::enter()
{
}

void UStateIdleKnight::update(float DeltaTime)
{

}

void UStateIdleKnight::useLightHit()
{
	stateMachine->changeState(TEXT("Combo1"));
}

void UStateIdleKnight::useFrontKick()
{
	stateMachine->changeState(TEXT("FrontKick"));
}

void UStateIdleKnight::useBlock()
{
	stateMachine->changeState(TEXT("Block"));
}