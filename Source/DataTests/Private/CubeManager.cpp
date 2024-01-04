#include "CubeManager.h"

#include "Cube.h"

FCubeData::FCubeData(FText StartingCubeName, FLinearColor StartingColor)
	: CubeName(StartingCubeName)
	, Color(StartingColor)
	, Scale(1.0)
	, bIsCyclingColors(false)
{}

void FCubeData::GetNewColor()
{
	int Blue = Color.B * 255;
	int Red = Color.R * 255;
	int Green = Color.G * 255;

	Blue = Blue + 15;
	if(Blue > 255)
	{
		Blue = 0;
		Green = Green + 15;
		if(Green > 255)
		{
			Green = 0;
			Red = Red + 15;
			if(Red > 255)
			{
				Red = 0;
			}
		}
	}

	Color = FLinearColor(Red / 255.0,Green / 255.0,Blue / 255.0);
}

void UCubeManager::SetCurrentCube(FGuid NewCurrentCubeId)
{
	if(NewCurrentCubeId == CurrentCubeId)
	{
		return;
	}
	
	CurrentCubeId = NewCurrentCubeId;
	OnNewCubeSelected.Broadcast();
}

bool UCubeManager::GetCubeData(FGuid CubeId, FCubeData& CubeData)
{
	if(const FCubeData* FoundCubeData = CubesData.Find(CubeId))
	{
		CubeData = *FoundCubeData;
		return true;
	}

	return false;
}

void UCubeManager::DestroyCube(ACube* Cube)
{
	FCubeData* CubeData = CubesData.Find(Cube->GetId());
	if(!CubeData)
	{
		return;
	}

	const FGuid CubeId = Cube->GetId();

	FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &UCubeManager::RespawnCube, CubeId);
	TimerDelegate.BindUFunction(this, "RespawnCube", CubeId);
	GetWorld()->GetTimerManager().SetTimer(
		CubeData->RespawnCubeHandle,
		TimerDelegate,
		5,
		false
		);

	Cube->Destroy();
}

void UCubeManager::SetCubeNextColor(FGuid CubeId)
{
	if(FCubeData* CubeData = CubesData.Find(CubeId))
	{
		CubeData->GetNewColor();
	}
}

void UCubeManager::RegisterNewCube(const ACube* Cube)
{
	if(!CubesData.Find(Cube->GetId()))
	{
		CubesData.Add(Cube->GetId(), FCubeData(Cube->StartingName, Cube->StartingColor));
	}
}

void UCubeManager::RespawnCube(FGuid CubeId)
{
	UE_LOG(LogTemp, Display, TEXT("Respawning Cube %s"), *CubeId.ToString());
}
