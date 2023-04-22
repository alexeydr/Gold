// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayFabGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UPlayFabGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
	FString GetSteamAuthToken();
	
};
