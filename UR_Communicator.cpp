#include "UR_Communicator.h"
#include <Arduino.h>



/*UR_Communicator::UR_Communicator()
{
}


UR_Communicator::~UR_Communicator()
{
}*/

void UR_Communicator::init()
{
	Serial.begin(115200);
}

bool UR_Communicator::read(Axis & axis)
{
	
	if (Serial.available() > 4)
	{
		int8_t temp = Serial.read();
		axis.x = temp;
	
		char divider = Serial.read();
		if (divider != '-')
		{
			String error;
			error=Serial.readString();
			return 0;
		}
		temp = Serial.read();
		axis.y = temp;
	    divider = Serial.read();
		if (divider != '-')
		{
			String error;
			error=Serial.readString();
			return 0;
		}
		temp = Serial.read();
		axis.z = temp;
	    /*divider = Serial.read();
		if (divider != '-')
		{
			String error;
			error=Serial.readString();
			return 0;
		}*/

		return true;
	}
	return false;
}

