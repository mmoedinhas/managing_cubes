#include "CubeManager.h"

void UCubeManager::SetCurrentCube(ACube* NewCurrentCube)
{
	if(NewCurrentCube == CurrentCube)
	{
		return;
	}
	
	CurrentCube = NewCurrentCube;
	OnNewCubeSelected.Broadcast();
}
