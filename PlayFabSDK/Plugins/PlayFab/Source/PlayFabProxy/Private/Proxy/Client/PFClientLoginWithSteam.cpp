// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientLoginWithSteam.h"

UPFClientLoginWithSteam::UPFClientLoginWithSteam(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithSteamDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLoginWithSteam* UPFClientLoginWithSteam::LoginWithSteam(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InTitleId, const FString& InSteamTicket, const bool& InCreateAccount, const FBPClientGetPlayerCombinedInfoRequestParams& InInfoRequestParameters)
{
	UPFClientLoginWithSteam* Proxy = NewObject<UPFClientLoginWithSteam>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.TitleId = InTitleId;
	Proxy->Request.SteamTicket = InSteamTicket;
	Proxy->Request.CreateAccount = InCreateAccount;
	*Proxy->Request.InfoRequestParameters = InInfoRequestParameters.Data;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLoginWithSteam::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LoginWithSteam(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientLoginResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLoginWithSteam::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
	FBPClientLoginResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientLoginWithSteam::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientLoginResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
