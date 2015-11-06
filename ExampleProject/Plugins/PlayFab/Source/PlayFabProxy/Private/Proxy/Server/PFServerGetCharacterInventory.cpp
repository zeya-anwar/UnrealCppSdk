// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerGetCharacterInventory.h"

UPFServerGetCharacterInventory::UPFServerGetCharacterInventory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetCharacterInventoryDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetCharacterInventory* UPFServerGetCharacterInventory::GetCharacterInventory(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InCharacterId, const FString& InCatalogVersion)
{
	UPFServerGetCharacterInventory* Proxy = NewObject<UPFServerGetCharacterInventory>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.CharacterId = InCharacterId;
	Proxy->Request.CatalogVersion = InCatalogVersion;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetCharacterInventory::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetCharacterInventory(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetCharacterInventoryResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetCharacterInventory::OnSuccessCallback(const PlayFab::ServerModels::FGetCharacterInventoryResult& Result)
{
	FBPServerGetCharacterInventoryResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetCharacterInventory::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetCharacterInventoryResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
