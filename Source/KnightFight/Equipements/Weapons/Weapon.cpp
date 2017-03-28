// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "Weapon.h"

#include "Engine.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapon::init(USkeletalMesh* skeletalMeshAsset)
{
	skeletalMesh = skeletalMeshAsset;
	meshComponent->SetSkeletalMesh(skeletalMeshAsset);
	allSockets = skeletalMesh->GetActiveSocketList();

	for (int i(0); i < allSockets.Num(); ++i)
	{
		USkeletalMeshSocket* socket = allSockets[i];
		FVector position;
		FString nameString = "HitSocket" + FString::FromInt(i);
		FName name = *nameString;
		position = meshComponent->GetSocketLocation(name);
		/*socket->GetSocketPositionWithOffset(position, meshComponent, offset, rotator);
		position += offset;*/
		previousPositions.Add(position);
	}
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AWeapon::tryHit(FHitResult& hit)
{
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	bool hitSomething = false;

	for (int i(0); i < allSockets.Num(); ++i)
	{
		USkeletalMeshSocket* socket = allSockets[i];
		FVector position;
		FString nameString = "HitSocket" + FString::FromInt(i);
		FName name = *nameString;
		position = meshComponent->GetSocketLocation(name);

		hitSomething = doTrace(&hit, &RV_TraceParams, position, previousPositions[i]) && hit.BoneName.ToString() != "None";
		if (hitSomething)
		{
			FString toPrint = hit.BoneName.ToString();
			UE_LOG(LogTemp, Warning, TEXT("%s"), *toPrint);
		}

		previousPositions[i] = position;
	}
	return hitSomething;
}

bool AWeapon::doTrace(FHitResult* hit, FCollisionQueryParams* rV_TraceParams, FVector startPosition, FVector endPosition)
{
	rV_TraceParams->bTraceComplex = true;
	rV_TraceParams->bTraceAsyncScene = true;
	rV_TraceParams->bReturnPhysicalMaterial = true;
	rV_TraceParams->AddIgnoredActor(GetOwner());

	//  do the line trace
	bool didTrace = GetWorld()->LineTraceSingleByChannel(
		*hit,        //result
		startPosition,        //start
		endPosition,        //end
		ECC_Pawn,    //collision channel
		*rV_TraceParams
	);

	DrawDebugLine(GetWorld(), startPosition, endPosition,
		FColor(255, 0, 0),
		true, -10000, 0,
		1);

	return didTrace;
}