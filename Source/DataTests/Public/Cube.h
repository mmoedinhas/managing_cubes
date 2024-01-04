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

	const FGuid& GetId() const;

	UPROPERTY(EditAnywhere)
	FText StartingName;
	
	UPROPERTY(EditAnywhere)
	FLinearColor StartingColor;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGuid CubeId;
	
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateColor();
	
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	FLinearColor PrevColor;
};
