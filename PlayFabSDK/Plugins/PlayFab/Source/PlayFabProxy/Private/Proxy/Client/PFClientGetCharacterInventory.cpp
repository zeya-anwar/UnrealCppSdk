// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientGetCharacterInventory.h"

UPFClientGetCharacterInventory::UPFClientGetCharacterInventory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetCharacterInventoryDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetCharacterInventory* UPFClientGetCharacterInventory::GetCharacterInventory(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InCharacterId, const FString& InCatalogVersion)
{
	UPFClientGetCharacterInventory* Proxy = NewObject<UPFClientGetCharacterInventory>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.CharacterId = InCharacterId;
	Proxy->Request.CatalogVersion = InCatalogVersion;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetCharacterInventory::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetCharacterInventory(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetCharacterInventoryResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetCharacterInventory::OnSuccessCallback(const PlayFab::ClientModels::FGetCharacterInventoryResult& Result)
{
	FBPClientGetCharacterInventoryResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetCharacterInventory::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetCharacterInventoryResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
