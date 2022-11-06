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
#include "fsm_button_function.h"

#define DO_NOTHING_TIMING	10000//10S do nothing

//state of finite state machine
#define	RESET		0
#define	INC			1
#define	DEC			2
#define AUTO_DEC	11
#define INC_1S		12
#define DEC_1S		13

//init
void startEveryThing();

extern int buttonStatus;

#endif /* INC_GLOBAL_H_ */
