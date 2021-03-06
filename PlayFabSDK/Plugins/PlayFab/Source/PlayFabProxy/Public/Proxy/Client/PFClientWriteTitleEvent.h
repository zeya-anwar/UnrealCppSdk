// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientWriteTitleEvent.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientWriteTitleEvent : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientWriteEventResponseDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientWriteEventResponseDelegate OnFailure;
	
	// Writes a title-based event into PlayStream.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Analytics")
	static UPFClientWriteTitleEvent* WriteTitleEvent(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InEventName, const FDateTime& InTimestamp);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FWriteTitleEventRequest Request;

	PlayFab::UPlayFabClientAPI::FWriteTitleEventDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FWriteEventResponse& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
