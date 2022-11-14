/*
 * led7.c
 *
 *  Created on: Oct 4, 2022
 *      Author: ASUS
 */


#include "led7.h"
#include "stdint.h"

static GPIO_TypeDef *led7SegPort[7]={
		PB0_GPIO_Port,
		PB1_GPIO_Port,
		PB2_GPIO_Port,
		PB3_GPIO_Port,
		PB4_GPIO_Port,
		PB5_GPIO_Port,
		PB6_GPIO_Port,

};

static uint16_t led7SegPin[7]={
		PB0_Pin,
		PB1_Pin,
		PB2_Pin,
		PB3_Pin,
		PB4_Pin,
		PB5_Pin,
		PB6_Pin,
};

int LED7_HEX[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void LED7_WriteByte(int b);

void LED7_WriteByte(int b)//need upgrade
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


