/*
 * fsm_automatic.c
 *
 *  Created on: Nov 1, 2022
 *      Author: ASUS
 */

#include "fsm_automatic.h"



void fsm_automatic_run()
{
	switch(status)
	{
	case INIT:
		//TODO
		offAllLight();
		status=AUTO_RED;
		setTimer1(RED_TIMING);
		break;
	case AUTO_RED:
		//TODO
		startRedLight();

		if(isTimer1Done())
		{
		status=AUTO_GREEN;
		setTimer1(GREEN_TIMING);
		}

		if(isButton1Pressed(0))
		{
			status=MAN_RED;
			setTimer1(3000);//3s for manual
		}

		break;
	case AUTO_YELLOW:
		//TODO
		startYellowLight();

		if(isTimer1Done())
		{
		status=AUTO_RED;
		setTimer1(RED_TIMING);
		}

		if(isButton1Pressed(0))
		{
			status=MAN_YELLOW;
			setTimer1(3000);//3s for manual
		}
		break;
	case AUTO_GREEN:
		//TODO
		startGreenLight();
		if(isTimer1Done())
		{
		status=AUTO_YELLOW;
		setTimer1(YELLOW_TIMING);
		}

		if(isButton1Pressed(0))
		{
			status=MAN_GREEN;
			setTimer1(3000);//3s for manual
		}
		break;
	default:
		break;
	}
}



