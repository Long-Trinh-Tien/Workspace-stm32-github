/*
 * ledClock.h
 *
 *  Created on: Oct 6, 2022
 *      Author: ASUS
 */

#ifndef INC_LEDCLOCK_H_
#define INC_LEDCLOCK_H_
#include "main.h"

#define led1On() HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, 1);
#define led1Off() HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, 0);
#define led2On() HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
#define led2Off() HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 0);
#define led3On() HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, 1);
#define led3Off() HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, 0);
#define led4On() HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, 1);
#define led4Off() HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, 0);
#define led5On() HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, 1);
#define led5Off() HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, 0);
#define led6On() HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, 1);
#define led6Off() HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, 0);
#define led7On() HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, 1);
#define led7Off() HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, 0);
#define led8On() HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, 1);
#define led8Off() HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, 0);
#define led9On() HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, 1);
#define led9Off() HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, 0);
#define led10On() HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, 1);
#define led10Off() HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, 0);
#define led11On() HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, 1);
#define led11Off() HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, 0);
#define led12On() HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, 1);
#define led12Off() HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, 0);

void LED12_Number(int num);
void clearAllClock(void);//excercise 7
void setNumberOnClock(int num);//excercise 8
void clearNumberOnClock(int num);//excercise 9
#endif /* INC_LEDCLOCK_H_ */
