// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGetCharacterLeaderboard.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerGetCharacterLeaderboard : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerGetCharacterLeaderboardResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerGetCharacterLeaderboardResultDelegate OnFailure;
	
	// Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Characters")
	static UPFServerGetCharacterLeaderboard* GetCharacterLeaderboard(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCharacterId, const FString& InCharacterType, const FString& InStatisticName, const int32& InStartPosition, const int32& InMaxResultsCount);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FGetCharacterLeaderboardRequest Request;

	PlayFab::UPlayFabServerAPI::FGetCharacterLeaderboardDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FGetCharacterLeaderboardResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
