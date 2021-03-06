// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGrantCharacterToUser.h"

UPFClientGrantCharacterToUser::UPFClientGrantCharacterToUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGrantCharacterToUserDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGrantCharacterToUser* UPFClientGrantCharacterToUser::GrantCharacterToUser(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InCatalogVersion, const FString& InItemId, const FString& InCharacterName)
{
	UPFClientGrantCharacterToUser* Proxy = NewObject<UPFClientGrantCharacterToUser>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.CatalogVersion = InCatalogVersion;
	Proxy->Request.ItemId = InItemId;
	Proxy->Request.CharacterName = InCharacterName;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGrantCharacterToUser::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GrantCharacterToUser(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGrantCharacterToUserResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGrantCharacterToUser::OnSuccessCallback(const PlayFab::ClientModels::FGrantCharacterToUserResult& Result)
{
	FBPClientGrantCharacterToUserResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGrantCharacterToUser::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGrantCharacterToUserResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
