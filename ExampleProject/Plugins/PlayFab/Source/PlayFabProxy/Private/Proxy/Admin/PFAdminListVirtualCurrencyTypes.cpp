// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminListVirtualCurrencyTypes.h"

UPFAdminListVirtualCurrencyTypes::UPFAdminListVirtualCurrencyTypes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FListVirtualCurrencyTypesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminListVirtualCurrencyTypes* UPFAdminListVirtualCurrencyTypes::ListVirtualCurrencyTypes(UObject* WorldContextObject, class APlayerController* PlayerController )
{
	UPFAdminListVirtualCurrencyTypes* Proxy = NewObject<UPFAdminListVirtualCurrencyTypes>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminListVirtualCurrencyTypes::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->ListVirtualCurrencyTypes(SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminListVirtualCurrencyTypesResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminListVirtualCurrencyTypes::OnSuccessCallback(const PlayFab::AdminModels::FListVirtualCurrencyTypesResult& Result)
{
	FBPAdminListVirtualCurrencyTypesResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminListVirtualCurrencyTypes::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminListVirtualCurrencyTypesResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
