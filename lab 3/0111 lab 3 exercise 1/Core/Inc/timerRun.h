/*
 * timerforled.h
 *
 *  Created on: 8 thg 10, 2022
 *      Author: ASUS
 */

#ifndef INC_TIMERFORLED_H_
#define INC_TIMERFORLED_H_

#include "main.h"
#include "stdint.h"//to use int32_t
//timer 1 use for blink led 2hz
//timer 2 use for change led 7segment
//timer 3 use for vertical light change
//timer 4 use for horizontal light change

void setTimer(int duration,int num_of_timer);
int isTimerDone(int num_of_timer);


//void setTimer1(int duration);
//int isTimer1Done();
//void setTimer2(int duration);
//int isTimer2Done();
//void setTimer3(int duration);
//int isTimer3Done();
//void setTimer4(int duration);
//int isTimer4Done();


void timerRun(void);//set flag

#endif /* INC_TIMERFORLED_H_ */
