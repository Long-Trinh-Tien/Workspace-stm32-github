/*
 * led7.c
 *
 *  Created on: Oct 4, 2022
 *      Author: ASUS
 */


#include "led7.h"
#include "main.h"
#include "stdint.h"

static GPIO_TypeDef *led7SegPort[7]={
		SEG0_GPIO_Port,
		SEG1_GPIO_Port,
		SEG2_GPIO_Port,
		SEG3_GPIO_Port,
		SEG4_GPIO_Port,
		SEG5_GPIO_Port,
		SEG6_GPIO_Port
};

static uint16_t led7SegPin[7]={
		SEG0_Pin,
		SEG1_Pin,
		SEG2_Pin,
		SEG3_Pin,
		SEG4_Pin,
		SEG5_Pin,
		SEG6_Pin
};

int LED7_HEX[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void LED7_WriteByte(int b);

void LED7_WriteByte(int b)
{
//  if (((b >> 0) & 0x01) == 1) { A_SET(); } else { A_RESET(); }
//  if (((b >> 1) & 0x01) == 1) { B_SET(); } else { B_RESET(); }
//  if (((b >> 2) & 0x01) == 1) { C_SET(); } else { C_RESET(); }
//  if (((b >> 3) & 0x01) == 1) { D_SET(); } else { D_RESET(); }
//  if (((b >> 4) & 0x01) == 1) { E_SET(); } else { E_RESET(); }
//  if (((b >> 5) & 0x01) == 1) { F_SET(); } else { F_RESET(); }
//  if (((b >> 6) & 0x01) == 1) { G_SET(); } else { G_RESET(); }

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

