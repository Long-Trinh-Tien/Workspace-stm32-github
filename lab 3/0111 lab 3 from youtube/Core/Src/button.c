/*
 * button.c
 *
 *  Created on: Nov 1, 2022
 *      Author: ASUS
 */

#include "button.h"
#include "global.h"

#define KEY_PRESS_TIMING	50 //press more than ?
#define NUM_OF_BUTTON		1

const GPIO_TypeDef *buttonPort[NUM_OF_BUTTON]={Button1_GPIO_Port};//list of button's port
const uint16_t buttonPin[NUM_OF_BUTTON]={Button1_Pin};
int button_flag[NUM_OF_BUTTON];
int keyReg[4][NUM_OF_BUTTON];//3 is last valid state (after checking vibration)
int timerForKeyPressed=KEY_PRESS_TIMING;

//all keyReg is at normal state
void startAllButton()
{
	for (int i=0;i<=3;i++)
	{
		for (int z=0;z<NUM_OF_BUTTON;z++)
		{
			keyReg[i][z]=NORMAL_STATE;
			button_flag[z]=0;
		}
	}
}

int isButton1Pressed(int index)
{
	if(button_flag[index]==1)
	{
		button_flag[index]=0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index)
{
	//TODO
	button_flag[index]=1;
}

void getKeyInput()//this will go to interrupt
{
	//anti-vibration
	for(int k=0;k<NUM_OF_BUTTON;k++)
	{
	keyReg[0][k]=keyReg[1][k];
	keyReg[1][k]=keyReg[2][k];
	keyReg[2][k]=HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	//check if key is being pressed for 2s or more
	if((keyReg[0][k]==keyReg[1][k])&&(keyReg[1][k]==keyReg[2][k]))// keyReg2 is valid when this is true
	{
		if(keyReg[3][k]!=keyReg[2][k])//check with last valid state
		{
			keyReg[3][k]=keyReg[2][k];//new state to last state
			if(keyReg[2][k]==PRESSED_STATE)
			{
				//TODO
				subKeyProcess(k);
				timerForKeyPressed=KEY_PRESS_TIMING;
			}
		}
		else //active button again if keeping pressing (for every 2s)
		{
			timerForKeyPressed--;
			if(timerForKeyPressed==0)
			{
				if(keyReg[2][k]==PRESSED_STATE)
				{
					//TODO
					subKeyProcess(k);
					timerForKeyPressed=KEY_PRESS_TIMING;
					}

				}
			}
		}
	}
}

