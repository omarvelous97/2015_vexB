#include "autonomous.h"
//preset height values
static int skyRise= 24;
static int lowPosition=55;
static int mediumPosition = 90;
static int highPosition = 110;
//postion values
//int initRightPosition = 0;
int initLeftPosition = 0;
//int deltaRightPosition = 0;
int deltaLeftPosition = 0;

void moveLiftToPosition(int targetposition)
{
	initLeftPosition = SensorValue[left_lift_encoder];
	//initRightPosition = SensorValue[right_lift_encoder];
	deltaLeftPosition = targetposition - initLeftPosition;
	//if we are moving up
	if(deltaLeftPosition > 0)
	{
		setLiftMotors(127);
		while((SensorValue[left_lift_encoder] < (initLeftPosition + deltaLeftPosition)))
		{

		}
		setLiftMotors(0);
	}
	else

	{
		setLiftMotors(-127);
		while((SensorValue[left_lift_encoder] >= (initLeftPosition + deltaLeftPosition)))
		{
		}
		setLiftMotors(0);
	}
}

void presets()
{
	if(vexRT[Btn7L])
	{
		moveLiftToPosition(skyRise);
	}
	else if(vexRT[Btn7U])
	{
		moveLiftToPosition(lowPosition);
	}
	else if(vexRT[Btn7R])
	{
		moveLiftToPosition(mediumPosition);
	}
	else if(vexRT[Btn7D])
	{
		moveLiftToPosition(highPosition);
	}
}
