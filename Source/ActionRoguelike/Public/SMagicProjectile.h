// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SMagicProjectile.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASMagicProjectile();

protected:
	//make sure editor can display
	UPROPERTY(VisibleAnywhere);
	USphereComponent* SphereComp; //collision component

	UPROPERTY(VisibleAnywhere);
	UProjectileMovementComponent* MovementComp; //movement component to give velocity

	UPROPERTY(VisibleAnywhere);
	UParticleSystemComponent* EffectComp; //something to show in game world
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
