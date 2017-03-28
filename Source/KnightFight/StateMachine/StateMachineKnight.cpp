// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "StateMachineKnight.h"


UStateMachineKnight::UStateMachineKnight() : UStateMachineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UStateMachineKnight::BeginPlay()
{
	Super::BeginPlay();

}