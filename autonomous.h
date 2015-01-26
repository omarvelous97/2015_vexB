#include "drive.h"
#include "lift.h"
#include "macros.h"
#include "presetHeights.h"

/*
in order to move the lift
moveAutonLift(int power, int encoder)

in order to make the robot move
if you want it to turn, set either left or right to negative
moveAutonDrive(int left, int right, int position)

in order to make the robot strafe
autonStrafe(int binary,int power, int position)
int binary: 1 to strafe right, 0 to strafe left

in order to actuate the piston
SensorValue[solenoid] = 0;
or
SensorValue[solenoid] = 1;
*/
void autonomousRedSky()
{

		//open claw
setSol(1);
wait1Msec(300);
//lift
moveAutonLift(90,20);
//drive forward
wait1Msec(200);
setMotors(45,45);
wait1Msec(750);
setMotors(0,0);
wait1Msec(200);
//close claw
setSol(0);
wait1Msec(500);
//lift up
moveAutonLift(90,40);
//drive back
wait1Msec(300);
moveAutonDrive(-60,-60,115);
wait1Msec(500);
//turn left
moveAutonDrive(-70,70,305);
wait1Msec(200);
//move forward
moveAutonDrive(35,35,113);
wait1Msec(200);
//lift down
moveAutonLift(70,5);
wait1Msec(300);
//open claw
setSol(1);
wait1Msec(200);
//move back
moveAutonDrive(-25,-25,100);
wait1Msec(200);
autonStrafe(1,90,100);

}
void autonomousRedCheat()
{
moveAutonLift(90,65);
wait1Msec(100);
moveAutonLift(90,10);
wait1Msec(100);
moveAutonDrive(40,40,70);
}
void autonomousBlueSky()
{

	//open claw
setSol(1);
wait1Msec(300);
//lift
moveAutonLift(90,20);
//drive forward
wait1Msec(200);
setMotors(50,50);
wait1Msec(700);
setMotors(0,0);
wait1Msec(200);
//close claw
setSol(0);
wait1Msec(500);
//lift up
moveAutonLift(90,40);
//drive back
wait1Msec(300);
moveAutonDrive(-40,-40,115);
wait1Msec(500);
//turn left
moveAutonDrive(70,-70,315);
wait1Msec(200);
//move forward
moveAutonDrive(35,35,85);
wait1Msec(200);
//lift down
moveAutonLift(70,5);
wait1Msec(300);
//open claw
setSol(1);
wait1Msec(200);
//move back
moveAutonDrive(-25,-25,100);
wait1Msec(200);
autonStrafe(0,70,60);

}
void autonomousBlueCheat()
{
moveAutonLift(60,20);
wait1Msec(300);
moveAutonLift(50,5);
wait1Msec(300);
moveAutonDrive(30,30,400);
	/*
  //score pre-load
	moveAutonLift(127,70);
	// do nothing for 3/10 of a second
	wait1Msec(300);
	//set lift back down
	moveAutonLift(127,10);
	//move forward
	moveAutonDrive(63,63,500);
	*/
}
