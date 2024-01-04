#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CubeManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNewCubeSelected);

class ACube;

UCLASS()
class DATATESTS_API UCubeManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetCurrentCube(ACube* NewCurrentCube);

	UPROPERTY(BlueprintAssignable)
	FOnNewCubeSelected OnNewCubeSelected;

protected:
	UPROPERTY(BlueprintReadOnly)
	ACube* CurrentCube;
};
