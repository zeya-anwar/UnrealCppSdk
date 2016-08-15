// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientLoginWithGameCenter.h"

UPFClientLoginWithGameCenter::UPFClientLoginWithGameCenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithGameCenterDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLoginWithGameCenter* UPFClientLoginWithGameCenter::LoginWithGameCenter(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InTitleId, const FString& InPlayerId, const bool& InCreateAccount, const FBPClientGetPlayerCombinedInfoRequestParams& InInfoRequestParameters)
{
	UPFClientLoginWithGameCenter* Proxy = NewObject<UPFClientLoginWithGameCenter>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.TitleId = InTitleId;
	Proxy->Request.PlayerId = InPlayerId;
	Proxy->Request.CreateAccount = InCreateAccount;
	*Proxy->Request.InfoRequestParameters = InInfoRequestParameters.Data;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLoginWithGameCenter::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LoginWithGameCenter(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientLoginResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLoginWithGameCenter::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
	FBPClientLoginResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientLoginWithGameCenter::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientLoginResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
