// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientLoginWithAndroidDeviceID.h"

UPFClientLoginWithAndroidDeviceID::UPFClientLoginWithAndroidDeviceID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithAndroidDeviceIDDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLoginWithAndroidDeviceID* UPFClientLoginWithAndroidDeviceID::LoginWithAndroidDeviceID(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InTitleId, const FString& InAndroidDeviceId, const FString& InOS, const FString& InAndroidDevice, const bool& InCreateAccount, const FBPClientGetPlayerCombinedInfoRequestParams& InInfoRequestParameters)
{
	UPFClientLoginWithAndroidDeviceID* Proxy = NewObject<UPFClientLoginWithAndroidDeviceID>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.TitleId = InTitleId;
	Proxy->Request.AndroidDeviceId = InAndroidDeviceId;
	Proxy->Request.OS = InOS;
	Proxy->Request.AndroidDevice = InAndroidDevice;
	Proxy->Request.CreateAccount = InCreateAccount;
	*Proxy->Request.InfoRequestParameters = InInfoRequestParameters.Data;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLoginWithAndroidDeviceID::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LoginWithAndroidDeviceID(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientLoginResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLoginWithAndroidDeviceID::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
	FBPClientLoginResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientLoginWithAndroidDeviceID::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientLoginResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
