#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#pragma warning(disable:4828)
#pragma warning(disable:4265)
#endif

#define SDK_VER TEXT("Steamv153")

#include "ThirdParty/Steamworks/Steamv153/sdk/public/steam/steam_api.h"

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include "SteamInventory.generated.h"

UENUM(BlueprintType)
enum class ESteamItemFlags_ : uint8
{
	NoTrade = 0,
	ItemRemoved = 8,
	ItemConsumed = 9,
};
USTRUCT(BlueprintType)
struct MYPROJECT_API FUint64
{
	GENERATED_BODY()

		uint64 Value;

	operator uint64() { return Value; }
	operator uint64() const { return Value; }

	FUint64() :
		Value(0) {}
	FUint64(uint64 value) :
		Value(value) {}
};

USTRUCT(BlueprintType)
struct MYPROJECT_API FInt32
{
	GENERATED_BODY()

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int32 Value;

	operator int32() { return Value; }
	operator int32() const { return Value; }

	FInt32() :
		Value(0) {}
	FInt32(int32 InValue) :
		Value(InValue) {}
};


USTRUCT(BlueprintType)
struct MYPROJECT_API FSteamInventoryResult : public FInt32
{
	GENERATED_BODY()
		using FInt32::FInt32;
};

USTRUCT(BlueprintType)
struct MYPROJECT_API FSteamItemInstanceID : public FUint64
{
	GENERATED_BODY()
		using FUint64::FUint64;
};

USTRUCT(BlueprintType)
struct MYPROJECT_API FSteamItemDef : public FInt32
{
	GENERATED_BODY()
		using FInt32::FInt32;
};

USTRUCT(BlueprintType)
struct MYPROJECT_API FSteamItemDetails
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite)
		FSteamItemInstanceID ItemID;

	UPROPERTY(BlueprintReadWrite)
		FSteamItemDef Definition;

	UPROPERTY(BlueprintReadWrite)
		int32 Quantity;

	UPROPERTY(BlueprintReadWrite)
		TArray<ESteamItemFlags_> Flags;

	FSteamItemDetails() {}
	FSteamItemDetails(FSteamItemInstanceID instance, FSteamItemDef itemdef, int32 quantity, const TArray<ESteamItemFlags_>& flags) :
		ItemID(instance), Definition(itemdef), Quantity(quantity), Flags(flags) {}
	FSteamItemDetails(const SteamItemDetails_t& details)
	{
		ItemID = details.m_itemId;
		Definition = details.m_iDefinition;
		Quantity = details.m_unQuantity;
		if (details.m_unFlags & 1 << (int32)ESteamItemFlags_::NoTrade)
		{
			Flags.Add(ESteamItemFlags_::NoTrade);
		}
		if (details.m_unFlags & 1 << (int32)ESteamItemFlags_::ItemRemoved)
		{
			Flags.Add(ESteamItemFlags_::ItemRemoved);
		}
		if (details.m_unFlags & 1 << (int32)ESteamItemFlags_::ItemConsumed)
		{
			Flags.Add(ESteamItemFlags_::ItemConsumed);
		}
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteamInventoryFullUpdateDelegate, FSteamInventoryResult, ResultHandle);

UCLASS()
class MYPROJECT_API USteamInventory : public UObject
{
	GENERATED_BODY()

public:
	USteamInventory();
	~USteamInventory();


	UFUNCTION(BlueprintPure, Category = "SteamBridgeCore", meta = (DisplayName = "Steam Inventory", CompactNodeTitle = "SteamInventory"))
	static USteamInventory* GetSteamInventory() { return USteamInventory::StaticClass()->GetDefaultObject<USteamInventory>(); }

	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "SteamBridgeCore|Inventory")
	bool GetAllItems(FSteamInventoryResult& ResultHandle) const { return SteamInventory()->GetAllItems(&ResultHandle.Value); }

	UFUNCTION(BlueprintCallable, Category = "SteamBridgeCore|Inventory")
	void DestroyResult(FSteamInventoryResult ResultHandle) { SteamInventory()->DestroyResult(ResultHandle); }

	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "SteamBridgeCore|Inventory")
	bool GetResultItems(FSteamInventoryResult ResultHandle, TArray<FSteamItemDetails>& ItemsArray) const;

	UPROPERTY(BlueprintAssignable, Category = "SteamBridgeCore|Inventory", meta = (DisplayName = "OnSteamInventoryFullUpdate"))
	FOnSteamInventoryFullUpdateDelegate m_OnSteamInventoryFullUpdate;

private:

	STEAM_CALLBACK_MANUAL(USteamInventory, OnSteamInventoryFullUpdate, SteamInventoryFullUpdate_t, OnSteamInventoryFullUpdateCallback);

};