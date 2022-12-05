/*
 * buzzer_function.c
 *
 *  Created on: 29 thg 9, 2022
 *      Author: ASUS
 */

#include "buzzer_function.h"
#include "timer_from_me.h"
#include "main.h"
static  int LedOnTime=0, LedOffTime=0;



void Led_On (void)
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);
}
void Led_Off (void)
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);
}

// Time input in second pls
void Led_Setup (int SetTimeOn, int SetTimeOff)
{
	if (delayTime!=0)
	{
		LedOnTime=SetTimeOn*1000/delayTime;
		LedOffTime=SetTimeOff*1000/delayTime;
	}
}


