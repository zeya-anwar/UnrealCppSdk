// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerDeregisterGame.h"

UPFServerDeregisterGame::UPFServerDeregisterGame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FDeregisterGameDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerDeregisterGame* UPFServerDeregisterGame::DeregisterGame(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InLobbyId)
{
	UPFServerDeregisterGame* Proxy = NewObject<UPFServerDeregisterGame>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.LobbyId = InLobbyId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerDeregisterGame::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->DeregisterGame(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerDeregisterGame::OnSuccessCallback(const PlayFab::ServerModels::FDeregisterGameResponse& Result)
{
	OnSuccess.Broadcast();
}

void UPFServerDeregisterGame::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
