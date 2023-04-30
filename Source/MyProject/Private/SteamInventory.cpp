// Fill out your copyright notice in the Description page of Project Settings.


#include "SteamInventory.h"

USteamInventory::USteamInventory()
{
	OnSteamInventoryFullUpdateCallback.Register(this, &USteamInventory::OnSteamInventoryFullUpdate);
}

USteamInventory::~USteamInventory()
{

	OnSteamInventoryFullUpdateCallback.Unregister();
}


void USteamInventory::OnSteamInventoryFullUpdate(SteamInventoryFullUpdate_t* pParam)
{
	m_OnSteamInventoryFullUpdate.Broadcast(pParam->m_handle);
}

bool USteamInventory::GetResultItems(FSteamInventoryResult ResultHandle, TArray<FSteamItemDetails>& ItemsArray) const
{
	uint32 TmpCount = 0;

	if (SteamInventory()->GetResultItems(ResultHandle, nullptr, &TmpCount))
	{
		TArray<SteamItemDetails_t> TmpArray;
		TmpArray.SetNum(TmpCount);
		bool result = SteamInventory()->GetResultItems(ResultHandle, TmpArray.GetData(), &TmpCount);

		for (int32 i = 0; i < (int32)TmpCount; i++)
		{
			ItemsArray.Add((FSteamItemDetails)TmpArray[i]);
		}

		return result;
	}

	return false;
}
