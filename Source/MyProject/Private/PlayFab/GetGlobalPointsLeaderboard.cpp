// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayFab/GetGlobalPointsLeaderboard.h"

UGetGlobalPointsLeaderboard* UGetGlobalPointsLeaderboard::GetGlobalPoints(const UObject* WorldContextObject)
{
	UGetGlobalPointsLeaderboard* BlueprintNode = NewObject<UGetGlobalPointsLeaderboard>();
	return BlueprintNode;
}

void UGetGlobalPointsLeaderboard::Activate()
{
	OnAddPointsSuccess.BindUFunction(this, TEXT("OnSuccess"));
	FClientGetLeaderboardRequest request;
	request.StatisticName = "GlobalPoints";
	request.StartPosition = 0;
	request.MaxResultsCount = 10;
	UPlayFabClientAPI::GetLeaderboard(request, OnAddPointsSuccess, OnAddPointsFailure, nullptr);
}

void UGetGlobalPointsLeaderboard::OnSuccess(FClientGetLeaderboardResult result, UObject* customData)
{
	if (true)
	{
		result;
	}
}