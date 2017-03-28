// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class KNIGHTFIGHT_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool doTrace(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams, FVector startPosition, FVector endPosition);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool tryHit(FHitResult& hit);
	void init(USkeletalMesh* skeletalMeshAsset);

private:
	UPROPERTY(EditAnywhere)
	USkeletalMesh* skeletalMesh;

	USkeletalMeshComponent* meshComponent;

	TArray<USkeletalMeshSocket*> allSockets;
	TArray<FVector> previousPositions;
};
