/*
 * timerforled.c
 *
 *  Created on: 8 thg 10, 2022
 *      Author: ASUS
 */


#include "timerRun.h"
#define NUM_OF_TIMER	4
#define TICK	10//10ms interrupt
int32_t count[NUM_OF_TIMER];
//int32_t count1=0/TICK;
//int32_t count2=0/TICK;
//int32_t count3=0/TICK;
//int32_t count4=0/TICK;
int flag[NUM_OF_TIMER];
//int flag1=0;
//int flag2=0;
//int flag3=0;
//int flag4=0;

void startAllTimer()
{
	for (int i=0;i<NUM_OF_TIMER;i++)
	{
		count[i]=0;
		flag[i]=0;
	}
}

void setTimer(int duration,int num_of_timer)
{
	count[num_of_timer]=duration/TICK;
}
//void setTimer1(int duration)
//{
//	count1 = duration/TICK;
//}
//
//void setTimer2(int duration)
//{
//	count2 = duration/TICK;
//}
//
//void setTimer3(int duration)
//{
//	count3 = duration/TICK;
//}
//
//void setTimer4(int duration)
//{
//	count4 = duration/TICK;
//}

int isTimerDone(int num_of_timer)
{
	if(flag[num_of_timer]==1)
	{
		flag[num_of_timer]=0;
		return 1;
	}
		return 0;
}

//int isTimer1Done()
//{
//	if (flag1==1)
//	{
//		flag1=0;
//		return 1;
//	}
//		return 0;
//}
//
//int isTimer2Done()
//{
//	if (flag2==1)
//	{
//		flag2=0;
//		return 1;
//	}
//		return 0;
//}
//
//int isTimer3Done()
//{
//	if (flag3==1)
//	{
//		flag3=0;
//		return 1;
//	}
//		return 0;
//}
//
//int isTimer4Done()
//{
//	if (flag4==1)
//	{
//		flag4=0;
//		return 1;
//	}
//		return 0;
//}

void timerRun()
{
	for(int timer=0;timer<NUM_OF_TIMER;timer++)
	{
		if(count[timer]>0)
		{
			count[timer]--;
		}
		if(count[timer]<=0)
		{
			flag[timer]=1;
		}
	}

//	//timer1
//	if (count1>0)
//	{
//		count1--;
//	}
//	if (count1<=0)
//	{
//		flag1=1;
//	}
//
//	//timer2
//	if (count2>0)
//	{
//		count2--;
//	}
//	if (count2<=0)
//	{
//		flag2=1;
//	}
//
//	//timer3
//	if (count3>0)
//	{
//		count3--;
//	}
//	if (count3<=0)
//	{
//		flag3=1;
//	}
//
//	//timer4
//	if (count4>0)
//	{
//		count4--;
//	}
//	if (count4<=0)
//	{
//		flag4=1;
//	}
}




