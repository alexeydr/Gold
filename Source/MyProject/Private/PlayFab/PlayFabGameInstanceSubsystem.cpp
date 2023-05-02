// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayFab/PlayFabGameInstanceSubsystem.h"
#include "OnlineSubsystemSteam.h"
#include "OnlineSubsystemUtils.h"
#include "PlayFabJsonObject.h"

FString UPlayFabGameInstanceSubsystem::GetSteamAuthToken()
{
	if (auto* SubsystemPtr = Online::GetSubsystem(GetWorld()))
	{
		if (auto IdentityPtr = SubsystemPtr->GetIdentityInterface())
		{
			return IdentityPtr->GetAuthToken(0);
		}

	}
	return {};
}


void UPlayFabGameInstanceSubsystem::GetVCBalance(UPlayFabJsonObject* JSON)
{
}