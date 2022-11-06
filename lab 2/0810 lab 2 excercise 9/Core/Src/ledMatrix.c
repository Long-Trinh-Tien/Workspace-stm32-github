/*
 * ledMatrix.c
 *
 *  Created on: Oct 30, 2022
 *      Author: ASUS
 */

#include "ledMatrix.h"
#include "main.h"

uint8_t matrix_buffer[8] = {0x00,0x78,0x14,0x12,0x12,0x14,0x78,0x00};//A characters
uint8_t sub_matrix_buffer[8]={0x78,0x14,0x12,0x12,0x14,0x78,0x00,0x00};

void shiftLeftMatrixUpdate()
{
	for (int s=0;s<=7;s++)
	{
		sub_matrix_buffer[s]=matrix_buffer[(s+1)%7];
	}
	for (int s=0;s<=7;s++)
	{
		matrix_buffer[s]=sub_matrix_buffer[s];
	}
}

void updateRowIn(int col)//update row in col ?
{

	for (int row=0;row<=7;row++)
	{
		if(((matrix_buffer[col]>>row)&0x01)==1)
		{
			HAL_GPIO_WritePin(ledMatrixRowControlPort[row], ledMatrixRowControlPin[row], 0);
		}
		else
		{
			HAL_GPIO_WritePin(ledMatrixRowControlPort[row], ledMatrixRowControlPin[row], 1);
		}
	}
}

void updateCol(void)
{
	for(int col=0;col<=7;col++)
	{
		updateRowIn(col);
		HAL_GPIO_WritePin(ledMatrixControlPort[col], ledMatrixControlPin[col], 0);
		HAL_Delay(50);
		offAllCol();
	}

}


//void updateLEDMatrix (int index )
//{
//	switch (index)
//	{
//		case 0:
//
//			break;
//
//		case 1:
//			break;
//
//		case 2:
//			break;
//
//		case 3:
//			break;
//
//		case 4:
//			break;
//
//		case 5:
//
//			break;
//
//		case 6:
//			break;
//
//		case 7:
//			break;
//
//		default:
//			break;
//	}
//}

void offAllRow(void)
{
	for (int i=0;i<=7;i++)
	{
		HAL_GPIO_WritePin(ledMatrixRowControlPort[i], ledMatrixRowControlPin[i], 1);
	}
}

void onAllRow(void)
{
	for (int i=0;i<=7;i++)
	{
		HAL_GPIO_WritePin(ledMatrixRowControlPort[i], ledMatrixRowControlPin[i], 0);
	}
}

void onAllCol(void)
{
	for (int i=0;i<=7;i++)
	{
		HAL_GPIO_WritePin(ledMatrixControlPort[i], ledMatrixControlPin[i], 0);
	}
}

void offAllCol(void)
{
	for (int i=0;i<=7;i++)
	{
		HAL_GPIO_WritePin(ledMatrixControlPort[i], ledMatrixControlPin[i], 1);
	}
}

