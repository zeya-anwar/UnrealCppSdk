// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerUpdateCharacterData.h"

UPFServerUpdateCharacterData::UPFServerUpdateCharacterData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdateCharacterDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerUpdateCharacterData* UPFServerUpdateCharacterData::UpdateCharacterData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InCharacterId, const FString& InData, const TArray<FString>& InKeysToRemove)
{
	UPFServerUpdateCharacterData* Proxy = NewObject<UPFServerUpdateCharacterData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.CharacterId = InCharacterId;
	
	Proxy->Request.KeysToRemove = InKeysToRemove;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerUpdateCharacterData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->UpdateCharacterData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerUpdateCharacterDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerUpdateCharacterData::OnSuccessCallback(const PlayFab::ServerModels::FUpdateCharacterDataResult& Result)
{
	FBPServerUpdateCharacterDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerUpdateCharacterData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerUpdateCharacterDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
