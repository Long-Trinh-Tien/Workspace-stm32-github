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

//state of finite state machine
//#define	INIT		1
//#define	AUTO_RED	2
//#define	AUTO_GREEN	3
//#define	AUTO_YELLOW	4
//
//
//#define MAN_RED		12
//#define MAN_YELLOW	13
//#define MAN_GREEN	14
//
//
//#define RED_TIMING		500
//#define	YELLOW_TIMING	200
//#define	GREEN_TIMING	300

#define	MODE_BUTTON			0
#define	TIME_BUTTON			1
#define	SET_VALUE_BUTTON	2


extern int status;

#endif /* INC_GLOBAL_H_ */
