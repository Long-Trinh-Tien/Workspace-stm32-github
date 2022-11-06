/*
 * timerforled.c
 *
 *  Created on: 8 thg 10, 2022
 *      Author: ASUS
 */


#include "timerRun.h"

#define TICK	10//10ms interrupt
int32_t count1=0/TICK;
int32_t count2=0/TICK;
int32_t count3=0/TICK;
int flag1=0;
int flag2=0;
int flag3=0;

void setTimer1(int duration)
{
	count1 = duration/TICK;
}

void setTimer2(int duration)
{
	count2 = duration/TICK;
}

void setTimer3(int duration)
{
	count3 = duration/TICK;
}

int isTimer1Done()
{
	if (flag1==1)
	{
		flag1=0;
		return 1;
	}
		return 0;
}

int isTimer2Done()
{
	if (flag2==1)
	{
		flag2=0;
		return 1;
	}
		return 0;
}

int isTimer3Done()
{
	if (flag3==1)
	{
		flag3=0;
		return 1;
	}
		return 0;
}

void timerRun()
{
	//timer1
	if (count1>0)
	{
		count1--;
	}
	if (count1<=0)
	{
		flag1=1;
	}

	//timer2
	if (count2>0)
	{
		count2--;
	}
	if (count2<=0)
	{
		flag2=1;
	}

	//timer3
	if (count3>0)
	{
		count3--;
	}
	if (count3<=0)
	{
		flag3=1;
	}
}




