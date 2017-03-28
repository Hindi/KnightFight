// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Animation/AnimNotifies/AnimNotify.h"
#include "TestNotify.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API UTestNotify : public UAnimNotify
{
public:
	GENERATED_UCLASS_BODY()

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};


