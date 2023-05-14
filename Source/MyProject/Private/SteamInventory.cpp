// Fill out your copyright notice in the Description page of Project Settings.


#include "SteamInventory.h"

USteamInventory::USteamInventory()
{
	OnSteamInventoryFullUpdateCallback.Register(this, &USteamInventory::OnSteamInventoryFullUpdate);
	OnSteamInventoryResultReadyCallback.Register(this, &USteamInventory::OnSteamInventoryResultReady);
}

USteamInventory::~USteamInventory()
{
	OnSteamInventoryFullUpdateCallback.Unregister();
	OnSteamInventoryResultReadyCallback.Unregister();
}

void USteamInventory::ConsumeCoins(FSteamInventoryResult& ResultHandle, int32 itemID, int32 unQuantity)
{
	SteamInventory()->ConsumeItem(&ResultHandle.Value, FUint64(itemID), unQuantity);
}

void USteamInventory::AddCoins(FSteamInventoryResult& ResultHandle, int32 itemID, int32 unQuantity)
{
	SteamItemDef_t newItems[1];
	uint32 quantities[1];
	newItems[0] = itemID;
	quantities[0] = unQuantity;

	SteamInventory()->GenerateItems(&ResultHandle.Value, newItems, quantities, 1);
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

void USteamInventory::OnSteamInventoryFullUpdate(SteamInventoryFullUpdate_t* pParam)
{
	m_OnSteamInventoryFullUpdate.Broadcast(pParam->m_handle);
}

void USteamInventory::OnSteamInventoryResultReady(SteamInventoryResultReady_t* pParam)
{
	m_OnSteamInventoryResultReady.Broadcast(pParam->m_handle, (ESteamResult)pParam->m_result);
}