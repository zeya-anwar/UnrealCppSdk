// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminCreateActionsOnPlayersInSegmentTask.h"

UPFAdminCreateActionsOnPlayersInSegmentTask::UPFAdminCreateActionsOnPlayersInSegmentTask(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FCreateActionsOnPlayersInSegmentTaskDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminCreateActionsOnPlayersInSegmentTask* UPFAdminCreateActionsOnPlayersInSegmentTask::CreateActionsOnPlayersInSegmentTask(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InName, const FString& InDescription, const FString& InSchedule, const bool& InIsActive, const FBPAdminActionsOnPlayersInSegmentTaskParameter& InParameter)
{
	UPFAdminCreateActionsOnPlayersInSegmentTask* Proxy = NewObject<UPFAdminCreateActionsOnPlayersInSegmentTask>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Name = InName;
	Proxy->Request.Description = InDescription;
	Proxy->Request.Schedule = InSchedule;
	Proxy->Request.IsActive = InIsActive;
	Proxy->Request.Parameter = InParameter.Data;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminCreateActionsOnPlayersInSegmentTask::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->CreateActionsOnPlayersInSegmentTask(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminCreateTaskResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminCreateActionsOnPlayersInSegmentTask::OnSuccessCallback(const PlayFab::AdminModels::FCreateTaskResult& Result)
{
	FBPAdminCreateTaskResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminCreateActionsOnPlayersInSegmentTask::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminCreateTaskResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
