///*
// * button.c
// *
// *  Created on: Nov 1, 2022
// *      Author: ASUS
// */
//
//#include "button.h"
//
//#define KEY_PRESS_TIMING	50 //press more than ?
//
//
//int button1_flag=0;
//
//int keyReg0 = NORMAL_STATE;
//int keyReg1 = NORMAL_STATE;
//int keyReg2 = NORMAL_STATE;
//int keyReg3 = NORMAL_STATE;//last valid state (after checking vibration)
//int timerForKeyPressed=KEY_PRESS_TIMING;
//
//int isButton1Pressed()
//{
//	if(button1_flag==1)
//	{
//		button1_flag=0;
//		return 1;
//	}
//	return 0;
//}
//
//void subKeyProcess()
//{
//	//TODO
//	button1_flag=1;
//}
//
//void getKeyInput()//this will go to interrupt
//{
//	//anti-vibration
//	keyReg0=keyReg1;
//	keyReg1=keyReg2;
//	keyReg2=HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
//	//check if key is being pressed for 2s or more
//	if((keyReg0==keyReg1)&&(keyReg1==keyReg2))// keyReg2 is valid when this is true
//	{
//		if(keyReg3!=keyReg2)//check with last valid state
//		{
//			keyReg3=keyReg2;//new state to last state
//			if(keyReg2==PRESSED_STATE)
//			{
//				//TODO
//				subKeyProcess();
//				timerForKeyPressed=KEY_PRESS_TIMING;
//			}
//		}
//		else //active button again if keeping pressing (for every 2s)
//		{
//			timerForKeyPressed--;
//			if(timerForKeyPressed==0)
//			{
//				if(keyReg2==PRESSED_STATE)
//				{
//					//TODO
//					subKeyProcess();
//					timerForKeyPressed=KEY_PRESS_TIMING;
//				}
//
//			}
//		}
//	}
//}
//
//
