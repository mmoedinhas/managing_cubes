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
	UPROPERTY(BlueprintReadWrite)
	ACube* CurrentCube;

	UPROPERTY(BlueprintAssignable)
	FOnNewCubeSelected OnNewCubeSelected;
	
};
