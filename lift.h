#include "macros.h"
//main lift set
void setLiftMotors(int power)
{
	motor[left_top_lift_motor] = power;
	motor[left_bottom_lift_motor] = power;
	motor[right_top_lift_motor] = power;
	motor[right_bottom_lift_motor] = power;
}
//SET LEFT LIFT MOTORS
void setLeftLiftMotors(int power)
{
	motor[left_top_lift_motor] = power;
	motor[left_bottom_lift_motor] = power;
}
//SET RIGHT LIFT MOTORS
void setRightLiftMotors(int power)
{
	motor[right_top_lift_motor] = power;
	motor[right_bottom_lift_motor] = power;
}


void moveAutonLift(int power, int encoder)
{
	sprintf(string1, "%d", SensorValue[left_lift_encoder]);
		displayLCDCenteredString(0, string1);

	int position = SensorValue[left_lift_encoder];
	int positionFinal = encoder - position;
	if(positionFinal > 0)
	{
		setLiftMotors(power);
		while(SensorValue[left_lift_encoder] <= (position + positionFinal))
		{
		}
		setLiftMotors(15);
	}
	else
	{
		setLiftMotors(-power);
		while(SensorValue[left_lift_encoder] > (position + positionFinal))
		{
		}
		setLiftMotors(15);
	}

}

void lift()
{
	//lift up or down
if(abs(liftJoystick) > DEADZONE)
	{
		 tempLiftVal = liftJoystick;
	}
	//stop lift
	else
	{
		tempLiftVal= 0;
	}
	motor[left_top_lift_motor] = tempLiftVal;
	motor[left_bottom_lift_motor] = tempLiftVal;
	motor[right_top_lift_motor] = tempLiftVal;
	motor[right_bottom_lift_motor] = tempLiftVal;

}
void clawPiston()
{
	if(vexRT[Btn6U])
	{
		if(!shift)
		{
			temp = lastState;
			lastState = on;
			on = temp;
		}
		shift = true;
	}
	else
	{
		shift = false;
	}

	if(on)
	{
		SensorValue[solenoid] = 0;
	}
	else
	{
		SensorValue[solenoid]=1;
	}
}
