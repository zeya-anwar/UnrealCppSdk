// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientLogEvent.h"

UPFClientLogEvent::UPFClientLogEvent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLogEventDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLogEvent* UPFClientLogEvent::LogEvent(UObject* WorldContextObject, class APlayerController* PlayerController , const FDateTime& InTimestamp, const FString& InEventName, const bool& InProfileSetEvent)
{
	UPFClientLogEvent* Proxy = NewObject<UPFClientLogEvent>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	
	Proxy->Request.EventName = InEventName;
	
	Proxy->Request.ProfileSetEvent = InProfileSetEvent;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLogEvent::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LogEvent(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLogEvent::OnSuccessCallback(const PlayFab::ClientModels::FLogEventResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientLogEvent::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
