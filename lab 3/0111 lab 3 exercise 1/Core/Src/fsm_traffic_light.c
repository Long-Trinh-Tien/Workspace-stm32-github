/*
 * fsm_traffic_light.c
 *
 *  Created on: Nov 13, 2022
 *      Author: ASUS
 */


#include "fsm_traffic_light.h"
#include "fsm_7seg_led.h"

static int mainRoadStatus=4;
static int otherRoadStatus=4;
int currentMainRoadTiming=0;
int currentOtherRoadTiming=0;

int bufferTrafficLightCountDown;
//turn light off
void offAllTrafficLight()
{
	HAL_GPIO_WritePin(RED_VER_GPIO_Port, RED_VER_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_VER_GPIO_Port, YELLOW_VER_Pin, 0);
	HAL_GPIO_WritePin(GREEN_VER_GPIO_Port, GREEN_VER_Pin, 0);
	HAL_GPIO_WritePin(RED_HOR_GPIO_Port, RED_HOR_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_HOR_GPIO_Port, YELLOW_HOR_Pin, 0);
	HAL_GPIO_WritePin(GREEN_HOR_GPIO_Port, GREEN_HOR_Pin, 0);
}

void offHORLight()
{
	HAL_GPIO_WritePin(RED_HOR_GPIO_Port, RED_HOR_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_HOR_GPIO_Port, YELLOW_HOR_Pin, 0);
	HAL_GPIO_WritePin(GREEN_HOR_GPIO_Port, GREEN_HOR_Pin, 0);
}

void offVERLight()
{
	HAL_GPIO_WritePin(RED_VER_GPIO_Port, RED_VER_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_VER_GPIO_Port, YELLOW_VER_Pin, 0);
	HAL_GPIO_WritePin(GREEN_VER_GPIO_Port, GREEN_VER_Pin, 0);
}

//count down buffer
void updateBufferFor7SEGvertical()
{
	currentMainRoadTiming--;
	setTimer(1000, 2);
}
void updateBufferFor7SEGhorizontal()
{
	currentOtherRoadTiming--;
	setTimer(1000, 3);
}

//vertical is main road, we works on main road
void fsm_traffic_light()
{
	switch(mainRoadStatus)
	{
	case 1://red
		bufferFor7SEG[0]=currentMainRoadTiming/10;
		bufferFor7SEG[1]=currentMainRoadTiming%10;
		HAL_GPIO_WritePin(RED_VER_GPIO_Port, RED_VER_Pin, 1);
		if(isTimerDone(2))
		{
			updateBufferFor7SEGvertical();
		}
		if(currentMainRoadTiming<=0)
		{
			offVERLight();
			mainRoadStatus=3;
			currentMainRoadTiming=bufferForTrafficLight[2];
		}
		if(mode!=NORMAL_MODE)
		{
			mainRoadStatus=4;
			offAllTrafficLight();
		}

		break;
	case 2://yellow
		bufferFor7SEG[0]=currentMainRoadTiming/10;
		bufferFor7SEG[1]=currentMainRoadTiming%10;
		HAL_GPIO_WritePin(YELLOW_VER_GPIO_Port, YELLOW_VER_Pin, 1);
		if(isTimerDone(2))
		{
			updateBufferFor7SEGvertical();
		}
		if(currentMainRoadTiming<=0)
		{
			offVERLight();
			mainRoadStatus=1;
			currentMainRoadTiming=bufferForTrafficLight[0];
		}
		if(mode!=NORMAL_MODE)
		{
			mainRoadStatus=4;
			offAllTrafficLight();
		}
		break;
	case 3://green
		bufferFor7SEG[0]=currentMainRoadTiming/10;
		bufferFor7SEG[1]=currentMainRoadTiming%10;
		HAL_GPIO_WritePin(GREEN_VER_GPIO_Port, GREEN_VER_Pin, 1);
		if(isTimerDone(2))
		{
			updateBufferFor7SEGvertical();
		}
		if(currentMainRoadTiming<=0)
		{
			offVERLight();
			mainRoadStatus=2;
			currentMainRoadTiming=bufferForTrafficLight[1];
		}
		if(mode!=NORMAL_MODE)
		{
			mainRoadStatus=4;
			offAllTrafficLight();
		}
		break;
	case 4://waiting for normal
		setTimer(1000,2);//count down every 1s
		if(mode==NORMAL_MODE)
		{
			mainRoadStatus=0;//to default
		}
		break;
	default:
		if(mode==NORMAL_MODE)
		{
			currentMainRoadTiming=bufferForTrafficLight[0];
			bufferFor7SEG[0]=currentMainRoadTiming/10;
			bufferFor7SEG[1]=currentMainRoadTiming%10;
			mainRoadStatus=1;//red
		}
		break;
	}

	//other road light
	switch(otherRoadStatus)
	{
	case 1://red
		bufferFor7SEG[2]=currentOtherRoadTiming/10;
		bufferFor7SEG[3]=currentOtherRoadTiming%10;
		HAL_GPIO_WritePin(RED_HOR_GPIO_Port, RED_HOR_Pin, 1);
		if(isTimerDone(3))
		{
			updateBufferFor7SEGhorizontal();
		}
		if(currentOtherRoadTiming<=0)
		{
			offHORLight();
			otherRoadStatus=3;
			currentOtherRoadTiming=bufferForTrafficLight[2];
		}
		if(mode!=NORMAL_MODE)
		{
			otherRoadStatus=4;
			offAllTrafficLight();
		}
		break;
	case 2://yellow
		bufferFor7SEG[2]=currentOtherRoadTiming/10;
		bufferFor7SEG[3]=currentOtherRoadTiming%10;
		HAL_GPIO_WritePin(YELLOW_HOR_GPIO_Port, YELLOW_HOR_Pin, 1);
		if(isTimerDone(3))
		{
			updateBufferFor7SEGhorizontal();
		}
		if(currentOtherRoadTiming<=0)
		{
			offHORLight();
			otherRoadStatus=1;
			currentOtherRoadTiming=bufferForTrafficLight[0];
		}
		if(mode!=NORMAL_MODE)
		{
			otherRoadStatus=4;
			offAllTrafficLight();
		}
		break;
	case 3://green
		bufferFor7SEG[2]=currentOtherRoadTiming/10;
		bufferFor7SEG[3]=currentOtherRoadTiming%10;
		HAL_GPIO_WritePin(GREEN_HOR_GPIO_Port, GREEN_HOR_Pin, 1);
		if(isTimerDone(3))
		{
			updateBufferFor7SEGhorizontal();
		}
		if(currentOtherRoadTiming<=0)
		{
			offHORLight();
			otherRoadStatus=2;
			currentOtherRoadTiming=bufferForTrafficLight[1];
		}
		if(mode!=NORMAL_MODE)
		{
			otherRoadStatus=4;
			offAllTrafficLight();
		}
		break;
	case 4://waiting mode
		setTimer(1000,3);
		if(mode==NORMAL_MODE)
		{
			otherRoadStatus=0;//to default
		}
		break;
	default:
		if(mode==NORMAL_MODE)
		{
			currentOtherRoadTiming=bufferForTrafficLight[2];
			bufferFor7SEG[2]=currentOtherRoadTiming/10;
			bufferFor7SEG[3]=currentOtherRoadTiming%10;
			otherRoadStatus=3;//green
		}
		break;
	}

}
