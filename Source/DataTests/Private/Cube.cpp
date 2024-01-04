#include "Cube.h"

ACube::ACube() : Color(0,0,0,1), Scale(1.0), bIsCyclingColors(false), PrevColor(0,0,0,0)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACube::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(bIsCyclingColors)
	{
		GetNextColor();
	}

	if(PrevColor != Color)
	{
		UpdateColor();
		PrevColor = Color;
	}
	
	SetActorRelativeScale3D(FVector(Scale, Scale, Scale));
}

void ACube::GetNextColor()
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
