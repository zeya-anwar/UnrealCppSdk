// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientLoginWithCustomID.h"

UPFClientLoginWithCustomID::UPFClientLoginWithCustomID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLoginWithCustomID* UPFClientLoginWithCustomID::LoginWithCustomID(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InTitleId, const FString& InCustomId, const bool& InCreateAccount, const FBPClientGetPlayerCombinedInfoRequestParams& InInfoRequestParameters)
{
	UPFClientLoginWithCustomID* Proxy = NewObject<UPFClientLoginWithCustomID>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.TitleId = InTitleId;
	Proxy->Request.CustomId = InCustomId;
	Proxy->Request.CreateAccount = InCreateAccount;
	Proxy->Request.InfoRequestParameters = InInfoRequestParameters;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLoginWithCustomID::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LoginWithCustomID(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientLoginResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLoginWithCustomID::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
	FBPClientLoginResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientLoginWithCustomID::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientLoginResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
