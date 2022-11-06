/*
 * ledMatrix.h
 *
 *  Created on: Oct 30, 2022
 *      Author: ASUS
 */

#ifndef INC_LEDMATRIX_H_
#define INC_LEDMATRIX_H_

#include "main.h"
#define NUMBER_OF_LED_MATRIX 8
static GPIO_TypeDef *ledMatrixControlPort[NUMBER_OF_LED_MATRIX] = {
		ENM0_GPIO_Port,
		ENM1_GPIO_Port,
		ENM2_GPIO_Port,
		ENM3_GPIO_Port,
		ENM4_GPIO_Port,
		ENM5_GPIO_Port,
		ENM6_GPIO_Port,
		ENM7_GPIO_Port
};

static uint16_t ledMatrixControlPin[NUMBER_OF_LED_MATRIX] = {
		ENM0_Pin,
		ENM1_Pin,
		ENM2_Pin,
		ENM3_Pin,
		ENM4_Pin,
		ENM5_Pin,
		ENM6_Pin,
		ENM7_Pin
};

static GPIO_TypeDef *ledMatrixRowControlPort[NUMBER_OF_LED_MATRIX] = {
		ROW0_GPIO_Port,
		ROW1_GPIO_Port,
		ROW2_GPIO_Port,
		ROW3_GPIO_Port,
		ROW4_GPIO_Port,
		ROW5_GPIO_Port,
		ROW6_GPIO_Port,
		ROW7_GPIO_Port
};

static uint16_t ledMatrixRowControlPin[NUMBER_OF_LED_MATRIX] = {
		ROW0_Pin,
		ROW1_Pin,
		ROW2_Pin,
		ROW3_Pin,
		ROW4_Pin,
		ROW5_Pin,
		ROW6_Pin,
		ROW7_Pin
};
void updateLEDMatrix (int index );
void offAllRow(void);
void onAllRow(void);
void offAllCol(void);
void onAllCol(void);
void updateRowIn(int col);
#endif /* INC_LEDMATRIX_H_ */
