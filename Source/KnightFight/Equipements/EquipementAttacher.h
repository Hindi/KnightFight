// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "EquipementAttacher.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KNIGHTFIGHT_API UEquipementAttacher : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEquipementAttacher();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	

	UPROPERTY(EditAnywhere)
	AActor* equipement;

	UPROPERTY(EditAnywhere)
	FString socketName;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* skeletalMesh;
	
};
