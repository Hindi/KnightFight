// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimNotifies/AnimNotify.h"
#include "EndOfBlockNotify.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API UEndOfBlockNotify : public UAnimNotify
{
	GENERATED_BODY()
	
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	
};
