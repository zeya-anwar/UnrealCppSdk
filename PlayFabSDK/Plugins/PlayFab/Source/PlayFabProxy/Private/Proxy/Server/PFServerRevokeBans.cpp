// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerRevokeBans.h"

UPFServerRevokeBans::UPFServerRevokeBans(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FRevokeBansDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerRevokeBans* UPFServerRevokeBans::RevokeBans(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FString>& InBanIds)
{
	UPFServerRevokeBans* Proxy = NewObject<UPFServerRevokeBans>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.BanIds = InBanIds;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerRevokeBans::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->RevokeBans(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerRevokeBansResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerRevokeBans::OnSuccessCallback(const PlayFab::ServerModels::FRevokeBansResult& Result)
{
	FBPServerRevokeBansResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerRevokeBans::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerRevokeBansResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
