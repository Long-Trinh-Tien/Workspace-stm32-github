/*
 * fsm_manual.c
 *
 *  Created on: 2 thg 11, 2022
 *      Author: ASUS
 */

#include "fsm_manual.h"



void fsm_manual_run()
{
	switch(status)
	{
		case MAN_RED:
			startRedLight();
			if(isButton1Pressed(0))
			{
				status=MAN_GREEN;
				setTimer1(3000);//3s for manual
			}
			if(isTimer1Done())
			{
				status=AUTO_RED;
				setTimer1(RED_TIMING);
			}
			break;
		case MAN_YELLOW:
			startYellowLight();
			if(isButton1Pressed(0))
			{
				status=MAN_RED;
				setTimer1(3000);//3s for manual
			}

			if(isTimer1Done())
			{
			status=AUTO_YELLOW;
			setTimer1(YELLOW_TIMING);
			}
			break;
		case MAN_GREEN:
			startGreenLight();
			if(isButton1Pressed(0))
			{
				status=MAN_YELLOW;
				setTimer1(3000);//3s for manual
			}

			if(isTimer1Done())
			{
			status=AUTO_GREEN;
			setTimer1(GREEN_TIMING);
			}
			break;
		default:
			break;
	}
}



