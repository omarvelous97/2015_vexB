int DEADZONE = 15;
//gyro
int tippingpoint = 75;

void ResetLiftEncoders()
{
	SensorValue[left_lift_encoder]=0;
}
void resetDriveEncoders()
{
	SensorValue[left_drive_encoder]= 0;
	SensorValue[right_drive_encoder]= 0;
}

void setSol(int number)
{
	if(number == 1)
	{
		Sensorvalue[solenoid]= 1;
}
else
{
	Sensorvalue[solenoid]= 0;
}
}

// drive variables
int up = 0;
int side = 0;
int spin = 0;
string string1;
string string2;
string string3;

//initialize drive channel variables
int verticalDrive= 0;
int strafeDrive = 0;
int turnDrive = 0;


//lift variables
int tempLiftVal = 0;
bool shift = false;
bool on = false;
bool lastState = true;
bool temp = false;
//initialize lift channel name
int liftJoystick= 0;


void updateOI()
{
	//drive channels
	verticalDrive= vexRT[Ch3];
	strafeDrive = vexRT[Ch4];
	turnDrive	= vexRT[Ch1];
	//lift channels
	liftJoystick= vexRT[Ch2];

}
