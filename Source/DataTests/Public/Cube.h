#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cube.generated.h"

UCLASS()
class DATATESTS_API ACube : public AActor
{
	GENERATED_BODY()

	ACube();

public:
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin=1, ClampMax=100))
	double Scale;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateColor();

private:
	UPROPERTY()
	FLinearColor PrevColor;
};
