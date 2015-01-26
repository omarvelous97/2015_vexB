#include "macros.h"
#include "autonomous.h"
void gyroSet()
{
	SensorValue[gyro]=0;
	//Adjust SensorScale to correct the scaling for your gyro
	SensorScale[gyro] = 0;
	//Adjust SensorFullCount to set the "rollover" point. 3600 sets the rollover point to +/-3600
	SensorFullCount[gyro] = 3600;
}

void gyroCode()
{
			sprintf(string1, "%d", SensorValue[gyro]);
		displayLCDCenteredString(0, string1);

	if(SensorValue[gyro] > tippingpoint)
	{

			setMotors(-127,-127);

	//	setLiftMotors(0);
	}
	else if(SensorValue[gyro] < tippingpoint)
	{

				setMotors(127,127);
		}
		//setLiftMotors(0);
		else
		{
setMotors(0,0);
	}
}
