// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminUpdatePolicy.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminUpdatePolicy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminUpdatePolicyResponseDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminUpdatePolicyResponseDelegate OnFailure;
	
	// Changes a policy for a title
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Authentication")
	static UPFAdminUpdatePolicy* UpdatePolicy(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPolicyName, const TArray<FBPAdminPermissionStatement>& InStatements, const bool& InOverwritePolicy);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FUpdatePolicyRequest Request;

	PlayFab::UPlayFabAdminAPI::FUpdatePolicyDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FUpdatePolicyResponse& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};