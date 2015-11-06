// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientConfirmPurchase.h"

UPFClientConfirmPurchase::UPFClientConfirmPurchase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FConfirmPurchaseDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientConfirmPurchase* UPFClientConfirmPurchase::ConfirmPurchase(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InOrderId)
{
	UPFClientConfirmPurchase* Proxy = NewObject<UPFClientConfirmPurchase>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.OrderId = InOrderId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientConfirmPurchase::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->ConfirmPurchase(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientConfirmPurchaseResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientConfirmPurchase::OnSuccessCallback(const PlayFab::ClientModels::FConfirmPurchaseResult& Result)
{
	FBPClientConfirmPurchaseResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientConfirmPurchase::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientConfirmPurchaseResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
