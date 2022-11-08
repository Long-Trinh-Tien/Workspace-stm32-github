/*
 * button.h
 *
 *  Created on: Nov 1, 2022
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE	GPIO_PIN_SET
#define	PRESSED_STATE	GPIO_PIN_RESET

int isButtonPressed(int index);
int isButtonPressed1s(int index);
//int isButtonPressed3s(int index);

void startAllButton();
void getKeyInput(void);

#endif /* INC_BUTTON_H_ */
