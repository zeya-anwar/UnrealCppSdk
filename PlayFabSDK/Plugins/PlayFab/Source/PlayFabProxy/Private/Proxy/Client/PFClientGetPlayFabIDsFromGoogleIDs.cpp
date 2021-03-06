// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetPlayFabIDsFromGoogleIDs.h"

UPFClientGetPlayFabIDsFromGoogleIDs::UPFClientGetPlayFabIDsFromGoogleIDs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayFabIDsFromGoogleIDsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetPlayFabIDsFromGoogleIDs* UPFClientGetPlayFabIDsFromGoogleIDs::GetPlayFabIDsFromGoogleIDs(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FString>& InGoogleIDs)
{
	UPFClientGetPlayFabIDsFromGoogleIDs* Proxy = NewObject<UPFClientGetPlayFabIDsFromGoogleIDs>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.GoogleIDs = InGoogleIDs;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetPlayFabIDsFromGoogleIDs::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetPlayFabIDsFromGoogleIDs(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetPlayFabIDsFromGoogleIDsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetPlayFabIDsFromGoogleIDs::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayFabIDsFromGoogleIDsResult& Result)
{
	FBPClientGetPlayFabIDsFromGoogleIDsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetPlayFabIDsFromGoogleIDs::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetPlayFabIDsFromGoogleIDsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
