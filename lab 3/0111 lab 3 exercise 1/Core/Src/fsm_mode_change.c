/*
 * fsm_mode_change.c
 *
 *  Created on: Nov 13, 2022
 *      Author: ASUS
 */

#include "fsm_mode_change.h"
#include "fsm_traffic_light.h"
//blink 2Hz
void blink_Red2Hz()
{
	HAL_GPIO_TogglePin(RED_HOR_GPIO_Port, RED_HOR_Pin);
	HAL_GPIO_TogglePin(RED_VER_GPIO_Port, RED_VER_Pin);
}

void blink_Yellow2Hz()
{
	HAL_GPIO_TogglePin(YELLOW_HOR_GPIO_Port, YELLOW_HOR_Pin);
	HAL_GPIO_TogglePin(YELLOW_VER_GPIO_Port, YELLOW_VER_Pin);
}

void blink_Green2Hz()
{
	HAL_GPIO_TogglePin(GREEN_HOR_GPIO_Port, GREEN_HOR_Pin);
	HAL_GPIO_TogglePin(GREEN_VER_GPIO_Port, GREEN_VER_Pin);
}

//update buffer
void updateBufferRed()
{
	bufferFor7SEG[0]=bufferForTrafficLight[0]/10;
	bufferFor7SEG[1]=bufferForTrafficLight[0]%10;
}

void updateBufferYellow()
{
	bufferFor7SEG[0]=bufferForTrafficLight[1]/10;
	bufferFor7SEG[1]=bufferForTrafficLight[1]%10;
}

void updateBufferGreen()
{
	bufferFor7SEG[0]=bufferForTrafficLight[2]/10;
	bufferFor7SEG[1]=bufferForTrafficLight[2]%10;
}

void modeNum(int mode)
{
	bufferFor7SEG[2]=0;
	bufferFor7SEG[3]=mode;
}

//vertical is main road, we works on main road
void fsm_mode_change()
{
	switch(mode)
	{
	case NORMAL_MODE:
		if(isButtonPressed(MODE_BUTTON))
		{
			mode=RED_MODE;
			setTimer(500,0);//2Hz
			offAllTrafficLight();
		}
//			fsm_traffic_light();
		break;
	case RED_MODE:
		modeNum(2);
		//blink 2Hz
		if(isTimerDone(1))
		{
			blink_Red2Hz();
			setTimer(500,0);
		}

		//update value
		if(isButtonPressed(TIME_BUTTON))
		{
			bufferForTrafficLight[0]=(bufferForTrafficLight[0]%99)+1;//1-99
		}
			updateBufferRed();

		//change mode
		if(isButtonPressed(MODE_BUTTON))
		{
			mode=YELLOW_MODE;
			setTimer(500,0);//2Hz
			offAllTrafficLight();
		}

		//return normal
		if(isButtonPressed(SET_VALUE_BUTTON))
		{
			mode=NORMAL_MODE;
			offAllTrafficLight();
		}
		break;
	case YELLOW_MODE:
		modeNum(3);
		//blink 2Hz
		if(isTimerDone(1))
		{
			blink_Yellow2Hz();
			setTimer(500,0);
		}

		//update value
		if(isButtonPressed(TIME_BUTTON))
		{
			bufferForTrafficLight[1]=(bufferForTrafficLight[1]%99)+1;//1-99
		}
			updateBufferYellow();

		//change mode
		if(isButtonPressed(MODE_BUTTON))
		{
			mode=GREEN_MODE;
			setTimer(500,0);//2Hz
			offAllTrafficLight();
		}

		//return normal
		if(isButtonPressed(SET_VALUE_BUTTON))
		{
			mode=NORMAL_MODE;
			offAllTrafficLight();
		}
		break;
	case GREEN_MODE:
		modeNum(4);
		//blink 2Hz
		if(isTimerDone(1))
		{
			blink_Green2Hz();
			setTimer(500,0);
		}

		//update value
		if(isButtonPressed(TIME_BUTTON))
		{
			bufferForTrafficLight[2]=(bufferForTrafficLight[2]%99)+1;//1-99
		}
			updateBufferGreen();

		//change mode
		if(isButtonPressed(MODE_BUTTON))
		{
			mode=NORMAL_MODE;
			offAllTrafficLight();
		}

		//return normal
		if(isButtonPressed(SET_VALUE_BUTTON))
		{
			mode=NORMAL_MODE;
			offAllTrafficLight();
		}
		break;
	default:
		break;
	}
}

