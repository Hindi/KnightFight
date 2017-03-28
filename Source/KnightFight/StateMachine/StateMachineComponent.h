// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "StateComponent.h"
#include "StateMachineComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KNIGHTFIGHT_API UStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateMachineComponent();
	//~UStateMachineComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void changeState(FString newState);
	virtual void start(FString firstState);
	virtual void addState(FString name, UStateComponent* state);

	UStateComponent* getCurrentState();

protected:
	UPROPERTY(EditAnywhere)
	TMap<FString, UStateComponent*> stateMap;
	UStateComponent* currentState;
	FString currentStateName;
};
