// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerDeleteSharedGroup.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerDeleteSharedGroup : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Deletes a shared group, freeing up the shared group ID to be reused for a new group
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Shared Group Data")
	static UPFServerDeleteSharedGroup* DeleteSharedGroup(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InSharedGroupId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FDeleteSharedGroupRequest Request;

	PlayFab::UPlayFabServerAPI::FDeleteSharedGroupDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
