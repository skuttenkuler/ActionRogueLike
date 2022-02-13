// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SInterface.generated.h"
// purpose -> shared API without specifying (example: treasure chest and dead player both have interact or loot action bound by interface)
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONROGUELIKE_API ISInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
