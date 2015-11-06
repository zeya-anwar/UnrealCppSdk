// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientLinkFacebookAccount.h"

UPFClientLinkFacebookAccount::UPFClientLinkFacebookAccount(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLinkFacebookAccountDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLinkFacebookAccount* UPFClientLinkFacebookAccount::LinkFacebookAccount(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InAccessToken, const bool& InForceLink)
{
	UPFClientLinkFacebookAccount* Proxy = NewObject<UPFClientLinkFacebookAccount>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.AccessToken = InAccessToken;
	Proxy->Request.ForceLink = InForceLink;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLinkFacebookAccount::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LinkFacebookAccount(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLinkFacebookAccount::OnSuccessCallback(const PlayFab::ClientModels::FLinkFacebookAccountResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientLinkFacebookAccount::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
