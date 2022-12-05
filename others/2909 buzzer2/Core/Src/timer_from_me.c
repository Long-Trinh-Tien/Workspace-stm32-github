/*
 * timer_from_me.c
 *
 *  Created on: 29 thg 9, 2022
 *      Author: ASUS
 */


#include "timer_from_me.h"
#include "buzzer_function.h"
const int delayTime = 10;
int u32systemStatus;
int count6s=6000/delayTime;
int countHalfSec=500/delayTime;
int count1s=1000/delayTime;
int count5s=5000/delayTime;
int Led_flag=0;
void Update_System_Status (void)
{
	u32systemStatus = (u32systemStatus+1)%4;//we have 4 status for buzzer
}
void timer6s()
{
	if( count6s>0)
		{
			count6s--;
		}
		if (count6s==0)
		{
			Update_System_Status();//tang status len 1 don vi
			count6s=6000/delayTime;
			if (u32systemStatus+3==3)
			{
				Led_Off();//tat den ngay sau khi het case 3
			}
		}
}

void timerHalfSec()
{
	if( countHalfSec>0)
	{
		countHalfSec--;
	}
	if (countHalfSec==0)
	{
		countHalfSec=500/delayTime;
		Led_flag=1;
	}
}

void timer1s()
{
	if( count1s>0)
	{
		count1s--;
	}
	if (count1s==0)
	{
		count1s=1000/delayTime;
		Led_flag=1;
	}
}

void timer5s()
{
	if( count5s>0)
	{
		count5s--;
	}
	if (count5s==0)
	{
		count5s=5000/delayTime;
		Led_flag=1;
	}
}

void Timer_For_Buzzer()
{
	timer6s();
	switch (u32systemStatus)
	{
	case 0:
		timerHalfSec();
		break;
	case 1:
		timer1s();
		break;
	case 2:
		timer5s();
		break;

	case 3:
		countHalfSec=500/delayTime;//wait for case 0
		break;
	default:
		break;
	}
}
