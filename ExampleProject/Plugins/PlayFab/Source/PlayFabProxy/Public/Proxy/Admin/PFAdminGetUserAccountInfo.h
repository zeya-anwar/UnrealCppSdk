// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetUserAccountInfo.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetUserAccountInfo : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminLookupUserAccountInfoResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminLookupUserAccountInfoResultDelegate OnFailure;
	
	// Retrieves the relevant details for a specified user, based upon a match against a supplied unique identifier
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Account Management")
	static UPFAdminGetUserAccountInfo* GetUserAccountInfo(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InEmail, const FString& InUsername, const FString& InTitleDisplayName);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FLookupUserAccountInfoRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetUserAccountInfoDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FLookupUserAccountInfoResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
