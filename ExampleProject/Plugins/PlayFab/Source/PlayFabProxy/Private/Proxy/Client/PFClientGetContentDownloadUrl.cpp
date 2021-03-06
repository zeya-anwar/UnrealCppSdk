// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetContentDownloadUrl.h"

UPFClientGetContentDownloadUrl::UPFClientGetContentDownloadUrl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetContentDownloadUrlDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetContentDownloadUrl* UPFClientGetContentDownloadUrl::GetContentDownloadUrl(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InKey, const FString& InHttpMethod, const bool& InThruCDN)
{
	UPFClientGetContentDownloadUrl* Proxy = NewObject<UPFClientGetContentDownloadUrl>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Key = InKey;
	Proxy->Request.HttpMethod = InHttpMethod;
	Proxy->Request.ThruCDN = InThruCDN;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetContentDownloadUrl::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetContentDownloadUrl(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetContentDownloadUrlResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetContentDownloadUrl::OnSuccessCallback(const PlayFab::ClientModels::FGetContentDownloadUrlResult& Result)
{
	FBPClientGetContentDownloadUrlResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetContentDownloadUrl::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetContentDownloadUrlResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
