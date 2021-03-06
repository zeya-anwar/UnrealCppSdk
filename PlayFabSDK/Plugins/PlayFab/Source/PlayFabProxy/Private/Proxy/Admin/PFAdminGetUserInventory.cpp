// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetUserInventory.h"

UPFAdminGetUserInventory::UPFAdminGetUserInventory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetUserInventoryDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetUserInventory* UPFAdminGetUserInventory::GetUserInventory(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId)
{
	UPFAdminGetUserInventory* Proxy = NewObject<UPFAdminGetUserInventory>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetUserInventory::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetUserInventory(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetUserInventoryResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetUserInventory::OnSuccessCallback(const PlayFab::AdminModels::FGetUserInventoryResult& Result)
{
	FBPAdminGetUserInventoryResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetUserInventory::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetUserInventoryResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
