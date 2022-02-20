// Fill out your copyright notice in the Description page of Project Settings.


#include "SInteractionComponent.h"
#include "SGameplayInterface.h"

// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
//COLLISION QUERY FOR INTERACTION
void USInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery((ECC_WorldDynamic));//make sure our the object type we are querying for is of World Dynamic

	AActor* MyOwner = GetOwner();//get origin(player)
	FVector	End,EyeLocation;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation,EyeRotation);

	End = EyeLocation + (EyeRotation.Vector() * 1000);
	
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit,EyeLocation, End, ObjectQueryParams);

	//get the actor we want this to be uhtilized on 
	AActor* HitActor = Hit.GetActor();
	if(HitActor) //only run if this hit actor is not a null
	{
		if(HitActor->Implements<ISGameplayInterface>())
		{
			APawn* MyPawn = Cast<APawn>(MyOwner);//cast our actor to pawn
			ISGameplayInterface::Execute_Interact(HitActor,MyPawn);
		}
	}
}