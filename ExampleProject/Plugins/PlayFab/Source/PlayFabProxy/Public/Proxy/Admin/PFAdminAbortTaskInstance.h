// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminAbortTaskInstance.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminAbortTaskInstance : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Abort an ongoing task instance.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|ScheduledTask")
	static UPFAdminAbortTaskInstance* AbortTaskInstance(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTaskInstanceId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FAbortTaskInstanceRequest Request;

	PlayFab::UPlayFabAdminAPI::FAbortTaskInstanceDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FEmptyResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
