// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FBPSteamWorkshopItemDetails;
class UObject;
struct FBPSteamWorkshopID;
class USteamWSRequestUGCDetailsCallbackProxy;
#ifdef ADVANCEDSTEAMSESSIONS_SteamWSRequestUGCDetailsCallbackProxy_generated_h
#error "SteamWSRequestUGCDetailsCallbackProxy.generated.h already included, missing '#pragma once' in SteamWSRequestUGCDetailsCallbackProxy.h"
#endif
#define ADVANCEDSTEAMSESSIONS_SteamWSRequestUGCDetailsCallbackProxy_generated_h

#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_50_DELEGATE \
struct _Script_AdvancedSteamSessions_eventBlueprintWorkshopDetailsDelegate_Parms \
{ \
	FBPSteamWorkshopItemDetails WorkShopDetails; \
}; \
static inline void FBlueprintWorkshopDetailsDelegate_DelegateWrapper(const FMulticastScriptDelegate& BlueprintWorkshopDetailsDelegate, FBPSteamWorkshopItemDetails const& WorkShopDetails) \
{ \
	_Script_AdvancedSteamSessions_eventBlueprintWorkshopDetailsDelegate_Parms Parms; \
	Parms.WorkShopDetails=WorkShopDetails; \
	BlueprintWorkshopDetailsDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_SPARSE_DATA
#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetWorkshopItemDetails);


#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetWorkshopItemDetails);


#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSteamWSRequestUGCDetailsCallbackProxy(); \
	friend struct Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(USteamWSRequestUGCDetailsCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSteamSessions"), ADVANCEDSTEAMSESSIONS_API) \
	DECLARE_SERIALIZER(USteamWSRequestUGCDetailsCallbackProxy)


#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_INCLASS \
private: \
	static void StaticRegisterNativesUSteamWSRequestUGCDetailsCallbackProxy(); \
	friend struct Z_Construct_UClass_USteamWSRequestUGCDetailsCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(USteamWSRequestUGCDetailsCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSteamSessions"), ADVANCEDSTEAMSESSIONS_API) \
	DECLARE_SERIALIZER(USteamWSRequestUGCDetailsCallbackProxy)


#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSTEAMSESSIONS_API USteamWSRequestUGCDetailsCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USteamWSRequestUGCDetailsCallbackProxy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSTEAMSESSIONS_API, USteamWSRequestUGCDetailsCallbackProxy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USteamWSRequestUGCDetailsCallbackProxy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSTEAMSESSIONS_API USteamWSRequestUGCDetailsCallbackProxy(USteamWSRequestUGCDetailsCallbackProxy&&); \
	ADVANCEDSTEAMSESSIONS_API USteamWSRequestUGCDetailsCallbackProxy(const USteamWSRequestUGCDetailsCallbackProxy&); \
public:


#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSTEAMSESSIONS_API USteamWSRequestUGCDetailsCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSTEAMSESSIONS_API USteamWSRequestUGCDetailsCallbackProxy(USteamWSRequestUGCDetailsCallbackProxy&&); \
	ADVANCEDSTEAMSESSIONS_API USteamWSRequestUGCDetailsCallbackProxy(const USteamWSRequestUGCDetailsCallbackProxy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSTEAMSESSIONS_API, USteamWSRequestUGCDetailsCallbackProxy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USteamWSRequestUGCDetailsCallbackProxy); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USteamWSRequestUGCDetailsCallbackProxy)


#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_PRIVATE_PROPERTY_OFFSET
#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_52_PROLOG
#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_PRIVATE_PROPERTY_OFFSET \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_SPARSE_DATA \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_RPC_WRAPPERS \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_INCLASS \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_PRIVATE_PROPERTY_OFFSET \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_SPARSE_DATA \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_INCLASS_NO_PURE_DECLS \
	Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h_55_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SteamWSRequestUGCDetailsCallbackProxy."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDSTEAMSESSIONS_API UClass* StaticClass<class USteamWSRequestUGCDetailsCallbackProxy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Gold_Plugins_AdvancedSessions_AdvancedSteamSessions_Source_AdvancedSteamSessions_Classes_SteamWSRequestUGCDetailsCallbackProxy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
