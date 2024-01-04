#include "Cube.h"

ACube::ACube() : Color(0,0,0,1), Scale(1.0), PrevColor(0,0,0,0) 
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACube::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(PrevColor != Color)
	{
		UpdateColor();
		PrevColor = Color;
	}

	SetActorLocation(Position);
	SetActorRotation(Rotation);
	SetActorRelativeScale3D(FVector(Scale, Scale, Scale));
}
