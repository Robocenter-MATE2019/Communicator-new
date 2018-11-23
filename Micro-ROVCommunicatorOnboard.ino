/*
 Name:		Micro_ROVCommunicatorOnboard.ino
 Created:	20.11.2018 17:29:51
 Author:	User
*/
#include "UR_Communicator.h"
#include <stdint.h>
#include "Motors.h"

BrushlessMotor BLMotor(9);

UR_Communicator comm;

void setup()
{
	BLMotor.init();
	delay(5000);
	comm.init();
}
void loop()
{
	Axis axis;
	if (comm.read(axis))
	{
		BLMotor.set_power(axis.z);
	}
}