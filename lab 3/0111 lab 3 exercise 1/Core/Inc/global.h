/*
 * global.h
 *
 *  Created on: Nov 1, 2022
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timerRun.h"
#include "button.h"
#include "main.h"
#include "stdint.h"
#include "led7.h"
#include "fsm_mode_change.h"
#include "fsm_7seg_led.h"
#include "fsm_traffic_light.h"


#define	MODE_BUTTON			0
#define	TIME_BUTTON			1
#define	SET_VALUE_BUTTON	2

#define NORMAL_MODE			10
#define RED_MODE			11
#define	YELLOW_MODE			12
#define GREEN_MODE			13

#define MODE_LED			20
#define MODE_LED_2			21
#define SET_VALUE_LED		22
#define SET_VALUE_LED_2		23

#define	RED_LIGHT			30
#define	YELLOW_LIGHT		31
#define	GREEN_LIGHT			32

extern int mode;
extern int led7SEGindex;

#endif /* INC_GLOBAL_H_ */
