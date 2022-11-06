/*
 * led7.c
 *
 *  Created on: Oct 4, 2022
 *      Author: ASUS
 */


#include "led7.h"
#include "stdint.h"

static GPIO_TypeDef *led7SegPort[7]={
//		SEG0_GPIO_Port,
//		SEG1_GPIO_Port,
//		SEG2_GPIO_Port,
//		SEG3_GPIO_Port,
//		SEG4_GPIO_Port,
//		SEG5_GPIO_Port,
//		SEG6_GPIO_Port
};

static uint16_t led7SegPin[7]={
//		SEG0_Pin,
//		SEG1_Pin,
//		SEG2_Pin,
//		SEG3_Pin,
//		SEG4_Pin,
//		SEG5_Pin,
//		SEG6_Pin
};

int LED7_HEX[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void LED7_WriteByte(int b);

void LED7_WriteByte(int b)
{

	for (int i=0;i<=6;i++)
	{
		if (((b>>i)&0x01)==1)
		{
			HAL_GPIO_WritePin(led7SegPort[i], led7SegPin[i], GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(led7SegPort[i], led7SegPin[i], GPIO_PIN_RESET);
		}
	}
}

void display7SEG(int num)
{
  LED7_WriteByte(LED7_HEX[num]);
}

//fsm cho led 7 doan
//void update7SEG ( int index )
//  {
//		switch (index)
//		{
//		case 0:
//			realFlag=0;
//			setTimer1(delayEachLed); //flag = 0 here
//			OffAllLed();
//			display7SEG(led_buffer[index]);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);//EN0 On
//			break;
//		case 1:
//			realFlag=0;
//			setTimer1(delayEachLed); //flag = 0 here
//			OffAllLed();
//			display7SEG(led_buffer[index]);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//EN1 On
//			break;
//		case 2:
//			realFlag=0;
//			setTimer1(delayEachLed); //flag = 0 here
//			OffAllLed();
//			display7SEG(led_buffer[index]);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//EN2 On
//			break;
//		case 3:
//			realFlag=0;
//			setTimer1(delayEachLed); //flag = 0 here
//			OffAllLed();
//			display7SEG(led_buffer[index]);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//EN3 On
//			break;
//		default:
//			break;
//		}
//  }
