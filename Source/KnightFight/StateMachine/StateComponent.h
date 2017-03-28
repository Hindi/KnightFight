// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "StateComponent.generated.h"

class UStateMachineComponent;
UCLASS(abstract, ClassGroup = (Custom))
class KNIGHTFIGHT_API UStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateComponent();

	void init(UStateMachineComponent* machine);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void leave() { check(0 && "You must override this"); }
	virtual void enter() { check(0 && "You must override this"); }
	virtual void update(float DeltaTime) { check(0 && "You must override this"); }
	
protected:
	UStateMachineComponent* stateMachine;
};
