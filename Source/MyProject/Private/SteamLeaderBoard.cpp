// Fill out your copyright notice in the Description page of Project Settings.


#include "SteamLeaderBoard.h"
#include "PlayFabJsonObject.h"
#include "PlayFabJsonValue.h"

void USteamLeaderBoard::AddGlobalPoints(int Points)
{
	FClientUpdatePlayerStatisticsRequest request;
	TArray<UPlayFabJsonObject*> Statistics;
	UPlayFabJsonObject* Json = NewObject<UPlayFabJsonObject>();
	Json->SetField("GlobalPoints", UPlayFabJsonValue::ConstructJsonValueNumber(this, 10));
	request.Statistics.Add(Json);
	UPlayFabClientAPI::UpdatePlayerStatistics(request, OnAddPointsSuccess, OnAddPointsFailure, nullptr);
}