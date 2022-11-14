/*
 * fsm_7seg_led.h
 *
 *  Created on: Nov 13, 2022
 *      Author: ASUS
 */

#ifndef INC_FSM_7SEG_LED_H_
#define INC_FSM_7SEG_LED_H_

#include "global.h"

extern int bufferFor7SEG[4];
extern int bufferForTrafficLight[3];

void fsm_7seg_led();
void OffAllLed();

#endif /* INC_FSM_7SEG_LED_H_ */
