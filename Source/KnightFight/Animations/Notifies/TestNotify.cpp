// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "TestNotify.h"
#include "Engine.h"

UTestNotify::UTestNotify(const FObjectInitializer& ObjectInitializer)
{

}

void UTestNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Animation Hit Notifying!"));
	}
}


