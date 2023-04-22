// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayFab/PlayFabGameInstanceSubsystem.h"
#include "OnlineSubsystemSteam.h"
#include "OnlineSubsystemUtils.h"

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

