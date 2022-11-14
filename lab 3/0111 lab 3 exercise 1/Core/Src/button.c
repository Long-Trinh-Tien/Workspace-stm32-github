/*
 * button.c
 *
 *  Created on: Nov 1, 2022
 *      Author: ASUS
 */

#include "button.h"
#include "global.h"

#define KEY_PRESS_TIMING	100 //press more than 3s
#define NUM_OF_BUTTON		3

//pin and port
const GPIO_TypeDef *buttonPort[NUM_OF_BUTTON]={MODE_GPIO_Port,TIME_GPIO_Port,SET_VALUE_GPIO_Port};//list of button's port
const uint16_t buttonPin[NUM_OF_BUTTON]={MODE_Pin,TIME_Pin,SET_VALUE_Pin};

//flag
int button_flag[NUM_OF_BUTTON];
int is_button_pressing_flag[NUM_OF_BUTTON];
//int is_button_pressing3s_flag[NUM_OF_BUTTON];

//key and timer
int keyReg[4][NUM_OF_BUTTON];//3 is last valid state (after checking vibration)
int timerForKeyPressed[NUM_OF_BUTTON];
int keyPressingTimeInSecond[NUM_OF_BUTTON];


//all keyReg is at normal state
void startAllButton()
{
	for (int i=0;i<=3;i++)
	{
		for (int z=0;z<NUM_OF_BUTTON;z++)
		{
			keyReg[i][z]=NORMAL_STATE;
			button_flag[z]=0;
			is_button_pressing_flag[z]=0;
			timerForKeyPressed[z]=KEY_PRESS_TIMING;
			keyPressingTimeInSecond[z]=0;
		}
	}
}

//check if button is pressed
int isButtonPressed(int index)
{
	if(button_flag[index]==1)
	{
		button_flag[index]=0;
		return 1;
	}
	return 0;
}

//check if button is pressed for more than 1s
int isButtonPressed1s(int index)
{
	if(is_button_pressing_flag[index]==1)
	{
		is_button_pressing_flag[index]=0;
		return 1;
	}
	return 0;
}


void subKeyProcess(int index)
{
	//TODO
	button_flag[index]=1;
}

void subKeyPressingProcess(int index)
{
	//TODO
	is_button_pressing_flag[index]=1;
}


void getKeyInput()//this will go to interrupt
{
	//anti-vibration
	for(int k=0;k<NUM_OF_BUTTON;k++)
	{
	keyReg[0][k]=keyReg[1][k];
	keyReg[1][k]=keyReg[2][k];
	keyReg[2][k]=HAL_GPIO_ReadPin(buttonPort[k], buttonPin[k]);
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
				timerForKeyPressed[k]=KEY_PRESS_TIMING;
			}
		}
		else //active button again if keeping pressing (for every 2s)
		{
			timerForKeyPressed[k]--;
			if(timerForKeyPressed[k]==0)
			{
				if(keyReg[2][k]==PRESSED_STATE)
				{
					//TODO
					subKeyPressingProcess(k);
					timerForKeyPressed[k]=KEY_PRESS_TIMING;
				}

			}
		}
	}
	}
}

