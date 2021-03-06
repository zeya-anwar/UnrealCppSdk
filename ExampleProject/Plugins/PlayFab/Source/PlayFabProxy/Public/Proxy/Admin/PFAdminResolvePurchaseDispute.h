// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminResolvePurchaseDispute.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminResolvePurchaseDispute : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminResolvePurchaseDisputeResponseDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminResolvePurchaseDisputeResponseDelegate OnFailure;
	
	// Attempts to resolve a dispute with the original order's payment provider.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Player Data Management")
	static UPFAdminResolvePurchaseDispute* ResolvePurchaseDispute(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InOrderId, const FString& InReason);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FResolvePurchaseDisputeRequest Request;

	PlayFab::UPlayFabAdminAPI::FResolvePurchaseDisputeDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FResolvePurchaseDisputeResponse& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
