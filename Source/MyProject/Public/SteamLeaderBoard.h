// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayFabClientAPI.h"
#include "SteamLeaderBoard.generated.h"

UCLASS()
class MYPROJECT_API USteamLeaderBoard : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Steam Leaderboard", CompactNodeTitle = "SteamLeaderboard"))
	static USteamLeaderBoard* GetSteamLeaderboard() { return USteamLeaderBoard::StaticClass()->GetDefaultObject<USteamLeaderBoard>(); }

	UFUNCTION(BlueprintCallable)
	void AddGlobalPoints(int Points);

	UPROPERTY()
		UPlayFabClientAPI::FDelegateOnSuccessUpdatePlayerStatistics OnAddPointsSuccess;

	UPROPERTY()
		UPlayFabClientAPI::FDelegateOnFailurePlayFabError OnAddPointsFailure;

};
