/*
 * global.c
 *
 *  Created on: Nov 1, 2022
 *      Author: ASUS
 */

#include "global.h"

int status = 0;//no initial status


//led function
void offAllLight()
{
	HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, 1);
	HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, 1);
	HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, 1);
}

void startRedLight()
{
	HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, 1);
	HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, 1);
}

void startYellowLight()
{
	HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, 1);
	HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, 0);
	HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, 1);
}

void startGreenLight()
{
	HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, 1);
	HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, 1);
	HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, 0);
}

