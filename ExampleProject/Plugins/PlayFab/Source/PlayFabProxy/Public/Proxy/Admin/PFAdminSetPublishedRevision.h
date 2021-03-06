// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminSetPublishedRevision.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminSetPublishedRevision : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Sets the currently published revision of a title Cloud Script
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Server-Side Cloud Script")
	static UPFAdminSetPublishedRevision* SetPublishedRevision(UObject* WorldContextObject, class APlayerController* PlayerController, const int32& InVersion, const int32& InRevision);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FSetPublishedRevisionRequest Request;

	PlayFab::UPlayFabAdminAPI::FSetPublishedRevisionDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FSetPublishedRevisionResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
