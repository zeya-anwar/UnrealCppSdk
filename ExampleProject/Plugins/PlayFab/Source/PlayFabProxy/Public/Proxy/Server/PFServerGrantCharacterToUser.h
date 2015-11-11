// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGrantCharacterToUser.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerGrantCharacterToUser : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerGrantCharacterToUserResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerGrantCharacterToUserResultDelegate OnFailure;
	
	// Grants the specified character type to the user.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Characters")
	static UPFServerGrantCharacterToUser* GrantCharacterToUser(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InCharacterName, const FString& InCharacterType);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FGrantCharacterToUserRequest Request;

	PlayFab::UPlayFabServerAPI::FGrantCharacterToUserDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FGrantCharacterToUserResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};