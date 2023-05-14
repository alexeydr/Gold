// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "PlayFabClientAPI.h"
#include "GetGlobalPointsLeaderboard.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGetGlobalPointsLeaderboard);

UCLASS()
class MYPROJECT_API UGetGlobalPointsLeaderboard : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY()
		UPlayFabClientAPI::FDelegateOnSuccessGetLeaderboard OnAddPointsSuccess;

	UPROPERTY()
		UPlayFabClientAPI::FDelegateOnFailurePlayFabError OnAddPointsFailure;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"))
		static UGetGlobalPointsLeaderboard* GetGlobalPoints(const UObject* WorldContextObject);

protected:

	void OnSuccess(FClientGetLeaderboardResult result, UObject* customData);

	virtual void Activate() override;


};
