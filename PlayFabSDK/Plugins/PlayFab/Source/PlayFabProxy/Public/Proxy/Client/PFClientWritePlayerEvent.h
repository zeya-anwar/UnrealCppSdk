// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientWritePlayerEvent.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientWritePlayerEvent : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientWriteEventResponseDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientWriteEventResponseDelegate OnFailure;
	
	// Writes a player-based event into PlayStream.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Analytics")
	static UPFClientWritePlayerEvent* WritePlayerEvent(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InEventName, const FDateTime& InTimestamp);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FWriteClientPlayerEventRequest Request;

	PlayFab::UPlayFabClientAPI::FWritePlayerEventDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FWriteEventResponse& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};