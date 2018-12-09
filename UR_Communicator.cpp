#include "UR_Communicator.h"
#include <Arduino.h>

void UR_Communicator::init()
{
	Serial.begin(115200);
}

bool UR_Communicator::read(Axis & axis)
{
	
	if (Serial.available() > 4)
	{
		String temp = Serial.readString();
		if (temp[1] != '-'&& temp[3] != '-')
		{
			return false;
		}
		axis.x = temp[0];
		axis.y = temp[2];
		axis.z = temp[4];
		return true;
	}
	return false;
}

/*int8_t UR_Communicator::get_axis()
{
	String temp_axis = Serial.readStringUntil('-');
	if (Serial.available() > 0)
	{
		Serial.read();
	}
	return temp_axis[0];
	/*int Temps[3];
	int i = 0;
	for (auto item : temp_axis)
	{
		switch (item)
		{
		case '1':
			Temps[i] = 1;
			break;
		case '2':
			Temps[i] = 2;
			break;
		case '3':
			Temps[i] = 3;
			break;
		case '4':
			Temps[i] = 4;
			break;
		case '5':
			Temps[i] = 5;
			break;
		case '6':
			Temps[i] = 6;
			break;
		case '7':
			Temps[i] = 7;
			break;
		case '8':
			Temps[i] = 8;
			break;
		case '9':
			Temps[i] = 9;
			break;
		case '0':
			Temps[i] = 0;
			break;
		default:
			break;
		}
		i++;
	}
	Serial1.println(temp_axis);
	int8_t result = Temps[0] * 100 + Temps[1] * 10 + Temps[2];
	return result;*/
	




