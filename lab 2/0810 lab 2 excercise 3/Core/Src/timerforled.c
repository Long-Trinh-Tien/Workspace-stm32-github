/*
 * timerforled.c
 *
 *  Created on: 8 thg 10, 2022
 *      Author: ASUS
 */


#include "timerforled.h"
#include "main.h"
#include "stdint.h"

int32_t count1=50;//500ms
int32_t flag1;
void setTimer1(int duration)
{
	count1 = duration;
	flag1=0;
}

int getFlag()
{
	return flag1;
}

void timerRun()
{
	if (count1>0)
	{
		count1--;
	}
	if (count1<=0)
	{
		flag1=1;
	}
}




