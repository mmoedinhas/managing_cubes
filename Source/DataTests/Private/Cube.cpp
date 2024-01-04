#include "Cube.h"

#include "CubeManager.h"

ACube::ACube() : StartingColor(0,0,0,1), PrevColor(0,0,0,0)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACube::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UCubeManager* CubeManager = GetWorld()->GetSubsystem<UCubeManager>();
	FCubeData CubeData;
	if(!CubeManager->GetCubeData(CubeId, CubeData))
	{
		CubeManager->RegisterNewCube(this);
	}

	if(CubeData.bIsCyclingColors)
	{
		CubeManager->SetCubeNextColor(CubeId);
	}

	if(PrevColor != CubeData.Color)
	{
		UpdateColor();
		PrevColor = CubeData.Color;
	}
	
	SetActorRelativeScale3D(FVector(CubeData.Scale, CubeData.Scale, CubeData.Scale));
}

const FGuid& ACube::GetId() const
{
	return CubeId;
}

void ACube::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetSubsystem<UCubeManager>()->RegisterNewCube(this);
}
