// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminAddVirtualCurrencyTypes.h"

UPFAdminAddVirtualCurrencyTypes::UPFAdminAddVirtualCurrencyTypes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FAddVirtualCurrencyTypesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminAddVirtualCurrencyTypes* UPFAdminAddVirtualCurrencyTypes::AddVirtualCurrencyTypes(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FBPAdminVirtualCurrencyData>& InVirtualCurrencies)
{
	UPFAdminAddVirtualCurrencyTypes* Proxy = NewObject<UPFAdminAddVirtualCurrencyTypes>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	for (const FBPAdminVirtualCurrencyData& elem : InVirtualCurrencies)
	{
		Proxy->Request.VirtualCurrencies.Add(elem.Data);
	}

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminAddVirtualCurrencyTypes::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->AddVirtualCurrencyTypes(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminAddVirtualCurrencyTypes::OnSuccessCallback(const PlayFab::AdminModels::FBlankResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminAddVirtualCurrencyTypes::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
