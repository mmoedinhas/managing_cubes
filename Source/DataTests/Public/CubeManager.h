#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CubeManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNewCubeSelected);

class ACube;

USTRUCT(BlueprintType)
struct DATATESTS_API FCubeData
{
	GENERATED_BODY()

	FCubeData(): Scale(1.0), bIsCyclingColors(false) {}

	FCubeData(FText StartingCubeName, FLinearColor StartingColor);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText CubeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin=1, ClampMax=100))
	double Scale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsCyclingColors;

	UPROPERTY()
	FTimerHandle RespawnCubeHandle;

	void GetNewColor();
};

UCLASS()
class DATATESTS_API UCubeManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetCurrentCube(FGuid NewCurrentCubeId);

	UPROPERTY(BlueprintAssignable)
	FOnNewCubeSelected OnNewCubeSelected;

	UFUNCTION(BlueprintCallable, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetCubeData(FGuid CubeId, FCubeData& CubeData);

	UFUNCTION(BlueprintCallable)
	void DestroyCube(ACube* Cube);
	
	void SetCubeNextColor(FGuid CubeId);

	void RegisterNewCube(const ACube* Cube);

protected:
	UPROPERTY(BlueprintReadOnly)
	FGuid CurrentCubeId;

	UPROPERTY(BlueprintReadOnly)
	TMap<FGuid, FCubeData> CubesData;

	UFUNCTION()
	void RespawnCube(FGuid CubeId);
};
