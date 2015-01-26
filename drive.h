#include "macros.h"
//SET LEFT DRIVE MOTORS
void setLeftMotors(int left)
{
	motor[left_forward_drive_motor] = left;
	motor[left_back_bottom_drive_motor] = left;
	motor[left_back_top_drive_motor] = left;
}
//SET RIGHT DRIVE MOTORS
void setRightMotors(int right)
{
	motor[right_forward_drive_motor] = right;
	motor[right_back_bottom_drive_motor] = right;
	motor[right_back_top_drive_motor] = right;
}

//SET ALL DRIVE MOTORS
void setMotors(int left, int right)
{
	//left motors
	motor[left_forward_drive_motor] = left;
	motor[left_back_bottom_drive_motor] = left;
	motor[left_back_top_drive_motor] = left;
	//right motors
	motor[right_forward_drive_motor] = right;
	motor[right_back_bottom_drive_motor] = right;
	motor[right_back_top_drive_motor] = right;
}
//SET STRAFE LEFT MOTORS
void strafeLeft(int power)
{
	//left
	motor[left_forward_drive_motor] = -power;
	motor[left_back_bottom_drive_motor] = power;
	motor[left_back_top_drive_motor] = power;
	//right
	motor[right_forward_drive_motor] = power;
	motor[right_back_bottom_drive_motor] = -power;
	motor[right_back_top_drive_motor] = -power;

}
//SET STRAFE RIGHT MOTORS
void strafeRight(int power)
{
	//right
	motor[right_forward_drive_motor] = -power;
	motor[right_back_bottom_drive_motor] = power;
	motor[right_back_top_drive_motor] = power;
	//left
	motor[left_forward_drive_motor] = power;
	motor[left_back_bottom_drive_motor] = -power;
	motor[left_back_top_drive_motor] = -power;
}

void moveAutonDrive(int left, int right, int position)
{
	resetDriveEncoders();
	//setMotors to power values
	setLeftMotors(left);
	setRightMotors(right);

	while(abs(SensorValue[left_drive_encoder]) < position || abs(SensorValue[right_drive_encoder]) < position)
	{
		if(abs(SensorValue[left_drive_encoder]) >= position)
		{
			setLeftMotors(0);
		}
		if(abs(SensorValue[right_drive_encoder]) >= position)
		{
			setRightMotors(0);
		}
	}
	setMotors(0,0);
}

void autonStrafe(int binary,int power, int position)
{
	resetDriveEncoders();
	if(binary!=1)
	{
		strafeLeft(power);
	}
	else
	{
		strafeRight(power);
	}

	while(abs(SensorValue[left_drive_encoder]) < position || abs(SensorValue[right_drive_encoder]) < position)
	{
		if(abs(SensorValue[left_drive_encoder]) >= position)
		{
			setLeftMotors(0);
		}
		if(abs(SensorValue[right_drive_encoder]) >= position)
		{
			setRightMotors(0);
		}
	}
	setMotors(0,0);

}


void drive()
{
	//move in Y
	if (abs(verticalDrive) > DEADZONE)
	{
		up = verticalDrive;
	}
	//Stop in Y
	else
	{
		up = 0;
	}
	//strafe left or right
	if (abs(strafeDrive) > DEADZONE)
	{
		side = strafeDrive;
	}
	else
	{
		side = 0;
	}
	//turn run to the left or right
	if(abs(turnDrive) > DEADZONE)
	{
		spin = turnDrive;
	}
	else
	{
		spin = 0;
	}
	//set motors
	motor[left_forward_drive_motor] = up + side + spin ;
	motor[left_back_top_drive_motor] = up -side + spin;
	motor[left_back_bottom_drive_motor] = up - side + spin;
	motor[right_forward_drive_motor] =  up - side - spin;
	motor[right_back_top_drive_motor] = up + side - spin;
	motor[right_back_bottom_drive_motor] = up + side - spin ;
}
