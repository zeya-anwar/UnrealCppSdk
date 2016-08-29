// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerAddPlayerTag.h"

UPFServerAddPlayerTag::UPFServerAddPlayerTag(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FAddPlayerTagDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerAddPlayerTag* UPFServerAddPlayerTag::AddPlayerTag(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InTagName)
{
	UPFServerAddPlayerTag* Proxy = NewObject<UPFServerAddPlayerTag>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.TagName = InTagName;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerAddPlayerTag::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->AddPlayerTag(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerAddPlayerTag::OnSuccessCallback(const PlayFab::ServerModels::FAddPlayerTagResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFServerAddPlayerTag::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}