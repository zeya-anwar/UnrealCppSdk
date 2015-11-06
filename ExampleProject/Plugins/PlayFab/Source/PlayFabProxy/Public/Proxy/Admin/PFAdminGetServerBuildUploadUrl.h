// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetServerBuildUploadUrl.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetServerBuildUploadUrl : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetServerBuildUploadURLResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetServerBuildUploadURLResultDelegate OnFailure;
	
	// Retrieves the pre-authorized URL for uploading a game server package containing a build (does not enable the build for use - see AddServerBuild)
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Custom Server Management")
	static UPFAdminGetServerBuildUploadUrl* GetServerBuildUploadUrl(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InBuildId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetServerBuildUploadURLRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetServerBuildUploadUrlDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetServerBuildUploadURLResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
