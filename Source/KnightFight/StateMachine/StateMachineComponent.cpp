// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "StateMachineComponent.h"


// Sets default values for this component's properties
UStateMachineComponent::UStateMachineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}
/*
UStateMachineComponent::~UStateMachineComponent()
{
	for (auto& pair : stateMap)
	{
		delete(pair.Value);
	}
}*/

void UStateMachineComponent::changeState(FString newStateName)
{
	currentState->leave();
	start(newStateName);
}

void UStateMachineComponent::start(FString newStateName)
{
	currentStateName = newStateName;
	if (stateMap.Contains(newStateName))
	{
		currentState = stateMap[newStateName];
		currentState->enter();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("There is no state registered with the name %s"), *newStateName);
	}
}

UStateComponent* UStateMachineComponent::getCurrentState()
{
	return currentState;
}

// Called when the game starts
void UStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UStateMachineComponent::addState(FString name, UStateComponent* state)
{
	stateMap.Add(name, state);
}


// Called every frame
void UStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(currentState)
		currentState->update(DeltaTime);
}

