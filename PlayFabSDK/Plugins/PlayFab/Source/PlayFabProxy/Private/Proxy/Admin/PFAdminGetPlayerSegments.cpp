// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetPlayerSegments.h"

UPFAdminGetPlayerSegments::UPFAdminGetPlayerSegments(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetPlayerSegmentsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetPlayerSegments* UPFAdminGetPlayerSegments::GetPlayerSegments(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId)
{
	UPFAdminGetPlayerSegments* Proxy = NewObject<UPFAdminGetPlayerSegments>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetPlayerSegments::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetPlayerSegments(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetPlayerSegmentsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetPlayerSegments::OnSuccessCallback(const PlayFab::AdminModels::FGetPlayerSegmentsResult& Result)
{
	FBPAdminGetPlayerSegmentsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetPlayerSegments::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetPlayerSegmentsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
