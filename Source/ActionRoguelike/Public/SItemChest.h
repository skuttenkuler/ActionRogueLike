// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SItemChest.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASItemChest : public AActor, public ISGameplayInterface // add interface
{
	GENERATED_BODY()
	void Interact_Implementation(APawn* InvestigatorPawn);//implement interface
	
	
public:
	//Lid Pitch
	UPROPERTY(EditAnywhere)
	float TargetPitch;
	// Sets default values for this actor's properties
	ASItemChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Base and Lid
	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* LidMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
