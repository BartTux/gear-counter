#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

typedef struct {
	char gearName[20];
	int teethCount; 
	float module;
	float toothHeadHeight;
	float toothFootHeight;
	float toothContourAngle;
	float pitchDiameter; 
	float outsideDiameter; 
	float rootDiameter; 
	float baseDiameter; 
	float rollingDiameter;
	float rollingAngle;
} Gear;

typedef struct {
	char* shaftName;
	Gear gear;
} Shaft;

typedef struct {
	Gear gear;
} GearTransmission;

void setToothHeadHeight(float*, float);
void setToothFootHeight(float*, float);
void calculatePitchDiameter(float*, float, int);
void calculateOutsideDiameter(float*, float, float);
void calculateRootDiameter(float*, float, float);
void calculateBaseDiameter(float*, float, float);
float degToRad(float);
void displayResults(Gear*);
void getData(Gear*);

int main(void)
{
	Gear gear;

	getData(&gear);

	setToothHeadHeight(&gear.toothHeadHeight, gear.module);
	setToothFootHeight(&gear.toothFootHeight, gear.module);
	calculatePitchDiameter(&gear.pitchDiameter, gear.module, gear.teethCount);
	calculateOutsideDiameter(&gear.outsideDiameter, gear.pitchDiameter, gear.toothHeadHeight);
	calculateRootDiameter(&gear.rootDiameter, gear.pitchDiameter, gear.toothFootHeight);
	calculateBaseDiameter(&gear.baseDiameter, gear.outsideDiameter, gear.rollingAngle);

	displayResults(&gear);
	system("pause");
}

void setToothHeadHeight(float* tooth_head_height, float module)
{
	*tooth_head_height = module;
}

void setToothFootHeight(float* tooth_foot_height, float module)
{
	*tooth_foot_height = 1.25 * module;
}

void calculatePitchDiameter(float* pitch_diameter, float module, int teeth_count) 
{
	*pitch_diameter = teeth_count * module;
}

void calculateOutsideDiameter(float* outside_diameter, float pitch_diameter, float tooth_head_height) 
{
	*outside_diameter = pitch_diameter + 2 * tooth_head_height;
}

void calculateRootDiameter(float* root_diameter, float pitch_diameter, float tooth_foot_height) 
{
	*root_diameter = pitch_diameter - 2 * tooth_foot_height;
}

void calculateBaseDiameter(float* base_diameter, float outside_diameter, float rolling_angle) 
{
	*base_diameter = outside_diameter * cos(degToRad(rolling_angle));
}

float degToRad(float degrees)
{
	return degrees * M_PI / 180;
}

void getData(Gear* gear)
{
	printf("Your -nth gear name: ");
	scanf_s("%19s", &(gear->gearName), 20);

	printf("Module for gears: ");
	scanf_s("%f", &(gear->module));

	printf("Your -nth gear teeth count: ");
	scanf_s("%d", &(gear->teethCount));

	printf("Rolling angle: ");
	scanf_s("%f", &(gear->rollingAngle));
}

void displayResults(Gear* gear)
{
	printf("\nTooth head height (ha): %f", gear->toothHeadHeight);
	printf("\nTooth foot height (hf): %f", gear->toothFootHeight);
	printf("\nPitch diameter (dp): %f", gear->pitchDiameter);
	printf("\nOutside diameter (da): %f", gear->outsideDiameter);
	printf("\nRoot diameter (df): %f", gear->rootDiameter);
	printf("\nBase diameter (db): %f", gear->baseDiameter);
	printf("\n");
}