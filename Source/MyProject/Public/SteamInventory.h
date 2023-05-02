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
enum class ESteamResult : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	OK = 1 UMETA(DisplayName = "OK"),
	Fail = 2 UMETA(DisplayName = "Fail"),
	NoConnection = 3 UMETA(DisplayName = "NoConnection"),
	InvalidPassword = 5 UMETA(DisplayName = "InvalidPassword"),
	LoggedInElsewhere = 6 UMETA(DisplayName = "LoggedInElsewhere"),
	InvalidProtocolVer = 7 UMETA(DisplayName = "InvalidProtocolVer"),
	InvalidParam = 8 UMETA(DisplayName = "InvalidParam"),
	FileNotFound = 9 UMETA(DisplayName = "FileNotFound"),
	Busy = 10 UMETA(DisplayName = "Busy"),
	InvalidState = 11 UMETA(DisplayName = "InvalidState"),
	InvalidName = 12 UMETA(DisplayName = "InvalidName"),
	InvalidEmail = 13 UMETA(DisplayName = "InvalidEmail"),
	DuplicateName = 14 UMETA(DisplayName = "DuplicateName"),
	AccessDenied = 15 UMETA(DisplayName = "AccessDenied"),
	Timeout = 16 UMETA(DisplayName = "Timeout"),
	Banned = 17 UMETA(DisplayName = "Banned"),
	AccountNotFound = 18 UMETA(DisplayName = "AccountNotFound"),
	InvalidSteamID = 19 UMETA(DisplayName = "InvalidSteamID"),
	ServiceUnavailable = 20 UMETA(DisplayName = "ServiceUnavailable"),
	NotLoggedOn = 21 UMETA(DisplayName = "NotLoggedOn"),
	Pending = 22 UMETA(DisplayName = "Pending"),
	EncryptionFailure = 23 UMETA(DisplayName = "EncryptionFailure"),
	InsufficientPrivilege = 24 UMETA(DisplayName = "InsufficientPrivilege"),
	LimitExceeded = 25 UMETA(DisplayName = "LimitExceeded"),
	Revoked = 26 UMETA(DisplayName = "Revoked"),
	Expired = 27 UMETA(DisplayName = "Expired"),
	AlreadyRedeemed = 28 UMETA(DisplayName = "AlreadyRedeemed"),
	DuplicateRequest = 29 UMETA(DisplayName = "DuplicateRequest"),
	AlreadyOwned = 30 UMETA(DisplayName = "AlreadyOwned"),
	IPNotFound = 31 UMETA(DisplayName = "IPNotFound"),
	PersistFailed = 32 UMETA(DisplayName = "PersistFailed"),
	LockingFailed = 33 UMETA(DisplayName = "LockingFailed"),
	LogonSessionReplaced = 34 UMETA(DisplayName = "LogonSessionReplaced"),
	ConnectFailed = 35 UMETA(DisplayName = "ConnectFailed"),
	HandshakeFailed = 36 UMETA(DisplayName = "HandshakeFailed"),
	IOFailure = 37 UMETA(DisplayName = "IOFailure"),
	RemoteDisconnect = 38 UMETA(DisplayName = "RemoteDisconnect"),
	ShoppingCartNotFound = 39 UMETA(DisplayName = "ShoppingCartNotFound"),
	Blocked = 40 UMETA(DisplayName = "Blocked"),
	Ignored = 41 UMETA(DisplayName = "Ignored"),
	NoMatch = 42 UMETA(DisplayName = "NoMatch"),
	AccountDisabled = 43 UMETA(DisplayName = "AccountDisabled"),
	ServiceReadOnly = 44 UMETA(DisplayName = "ServiceReadOnly"),
	AccountNotFeatured = 45 UMETA(DisplayName = "AccountNotFeatured"),
	AdministratorOK = 46 UMETA(DisplayName = "AdministratorOK"),
	ContentVersion = 47 UMETA(DisplayName = "ContentVersion"),
	TryAnotherCM = 48 UMETA(DisplayName = "TryAnotherCM"),
	PasswordRequiredToKickSession = 49 UMETA(DisplayName = "PasswordRequiredToKickSession"),
	AlreadyLoggedInElsewhere = 50 UMETA(DisplayName = "AlreadyLoggedInElsewhere"),
	Suspended = 51 UMETA(DisplayName = "Suspended"),
	Cancelled = 52 UMETA(DisplayName = "Cancelled"),
	DataCorruption = 53 UMETA(DisplayName = "DataCorruption"),
	DiskFull = 54 UMETA(DisplayName = "DiskFull"),
	RemoteCallFailed = 55 UMETA(DisplayName = "RemoteCallFailed"),
	PasswordUnset = 56 UMETA(DisplayName = "PasswordUnset"),
	ExternalAccountUnlinked = 57 UMETA(DisplayName = "ExternalAccountUnlinked"),
	PSNTicketInvalid = 58 UMETA(DisplayName = "PSNTicketInvalid"),
	ExternalAccountAlreadyLinked = 59 UMETA(DisplayName = "ExternalAccountAlreadyLinked"),
	RemoteFileConflict = 60 UMETA(DisplayName = "RemoteFileConflict"),
	IllegalPassword = 61 UMETA(DisplayName = "IllegalPassword"),
	SameAsPreviousValue = 62 UMETA(DisplayName = "SameAsPreviousValue"),
	AccountLogonDenied = 63 UMETA(DisplayName = "AccountLogonDenied"),
	CannotUseOldPassword = 64 UMETA(DisplayName = "CannotUseOldPassword"),
	InvalidLoginAuthCode = 65 UMETA(DisplayName = "InvalidLoginAuthCode"),
	AccountLogonDeniedNoMail = 66 UMETA(DisplayName = "AccountLogonDeniedNoMail"),
	HardwareNotCapableOfIPT = 67 UMETA(DisplayName = "HardwareNotCapableOfIPT"),
	IPTInitError = 68 UMETA(DisplayName = "IPTInitError"),
	ParentalControlRestricted = 69 UMETA(DisplayName = "ParentalControlRestricted"),
	FacebookQueryError = 70 UMETA(DisplayName = "FacebookQueryError"),
	ExpiredLoginAuthCode = 71 UMETA(DisplayName = "ExpiredLoginAuthCode"),
	IPLoginRestrictionFailed = 72 UMETA(DisplayName = "IPLoginRestrictionFailed"),
	AccountLockedDown = 73 UMETA(DisplayName = "AccountLockedDown"),
	AccountLogonDeniedVerifiedEmailRequired = 74 UMETA(DisplayName = "AccountLogonDeniedVerifiedEmailRequired"),
	NoMatchingURL = 75 UMETA(DisplayName = "NoMatchingURL"),
	BadResponse = 76 UMETA(DisplayName = "BadResponse"),
	RequirePasswordReEntry = 77 UMETA(DisplayName = "RequirePasswordReEntry"),
	ValueOutOfRange = 78 UMETA(DisplayName = "ValueOutOfRange"),
	UnexpectedError = 79 UMETA(DisplayName = "UnexpectedError"),
	Disabled = 80 UMETA(DisplayName = "Disabled"),
	InvalidCEGSubmission = 81 UMETA(DisplayName = "InvalidCEGSubmission"),
	RestrictedDevice = 82 UMETA(DisplayName = "RestrictedDevice"),
	RegionLocked = 83 UMETA(DisplayName = "RegionLocked"),
	RateLimitExceeded = 84 UMETA(DisplayName = "RateLimitExceeded"),
	AccountLoginDeniedNeedTwoFactor = 85 UMETA(DisplayName = "AccountLoginDeniedNeedTwoFactor"),
	ItemDeleted = 86 UMETA(DisplayName = "ItemDeleted"),
	AccountLoginDeniedThrottle = 87 UMETA(DisplayName = "AccountLoginDeniedThrottle"),
	TwoFactorCodeMismatch = 88 UMETA(DisplayName = "TwoFactorCodeMismatch"),
	TwoFactorActivationCodeMismatch = 89 UMETA(DisplayName = "TwoFactorActivationCodeMismatch"),
	AccountAssociatedToMultiplePartners = 90 UMETA(DisplayName = "AccountAssociatedToMultiplePartners"),
	NotModified = 91 UMETA(DisplayName = "NotModified"),
	NoMobileDevice = 92 UMETA(DisplayName = "NoMobileDevice"),
	TimeNotSynced = 93 UMETA(DisplayName = "TimeNotSynced"),
	SmsCodeFailed = 94 UMETA(DisplayName = "SmsCodeFailed"),
	AccountLimitExceeded = 95 UMETA(DisplayName = "AccountLimitExceeded"),
	AccountActivityLimitExceeded = 96 UMETA(DisplayName = "AccountActivityLimitExceeded"),
	PhoneActivityLimitExceeded = 97 UMETA(DisplayName = "PhoneActivityLimitExceeded"),
	RefundToWallet = 98 UMETA(DisplayName = "RefundToWallet"),
	EmailSendFailure = 99 UMETA(DisplayName = "EmailSendFailure"),
	NotSettled = 100 UMETA(DisplayName = "NotSettled"),
	NeedCaptcha = 101 UMETA(DisplayName = "NeedCaptcha"),
	GSLTDenied = 102 UMETA(DisplayName = "GSLTDenied"),
	GSOwnerDenied = 103 UMETA(DisplayName = "GSOwnerDenied"),
	InvalidItemType = 104 UMETA(DisplayName = "InvalidItemType"),
	IPBanned = 105 UMETA(DisplayName = "IPBanned"),
	GSLTExpired = 106 UMETA(DisplayName = "GSLTExpired"),
	InsufficientFunds = 107 UMETA(DisplayName = "InsufficientFunds"),
	TooManyPending = 108 UMETA(DisplayName = "TooManyPending")
};

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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSteamInventoryResultReadyDelegate, FSteamInventoryResult, ResultHandle, ESteamResult, Result);
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

	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "SteamBridgeCore|Inventory")
	void ConsumeCoins(FSteamInventoryResult& ResultHandle, int32 itemID, int32 unQuantity);

	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "SteamBridgeCore|Inventory")
	void AddCoins(FSteamInventoryResult& ResultHandle, int32 itemID, int32 unQuantity);

	UPROPERTY(BlueprintAssignable, Category = "SteamBridgeCore|Inventory", meta = (DisplayName = "OnSteamInventoryFullUpdate"))
	FOnSteamInventoryFullUpdateDelegate m_OnSteamInventoryFullUpdate;

	UPROPERTY(BlueprintAssignable, Category = "SteamBridgeCore|Inventory", meta = (DisplayName = "OnSteamInventoryResultReady"))
	FOnSteamInventoryResultReadyDelegate m_OnSteamInventoryResultReady;

private:

	STEAM_CALLBACK_MANUAL(USteamInventory, OnSteamInventoryFullUpdate, SteamInventoryFullUpdate_t, OnSteamInventoryFullUpdateCallback);
	STEAM_CALLBACK_MANUAL(USteamInventory, OnSteamInventoryResultReady, SteamInventoryResultReady_t, OnSteamInventoryResultReadyCallback);

};