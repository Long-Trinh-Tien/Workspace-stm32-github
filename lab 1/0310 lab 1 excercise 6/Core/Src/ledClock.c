/*
 * ledClock.c
 *
 *  Created on: Oct 6, 2022
 *      Author: ASUS
 */
#include "main.h"
#include "ledClock.h"



int LED12_HEX[] = {0x001, 0x02, 0x04, 0x08, 0x010 ,0x20, 0x40, 0x80,0x100,0x200,0x400,0x800};//turn only 1 led on
int LED12_HEX_OFF = 0x00;

//turn only 1 led on, off the rest led
void LED12_WriteByte(int b)
{
	if (((b >> 0) & 0x01) == 1) { led1On(); } else { led1Off(); }
	if (((b >> 1) & 0x01) == 1) { led2On(); } else { led2Off(); }
	if (((b >> 2) & 0x01) == 1) { led3On(); } else { led3Off(); }
	if (((b >> 3) & 0x01) == 1) { led4On(); } else { led4Off(); }
	if (((b >> 4) & 0x01) == 1) { led5On(); } else { led5Off(); }
	if (((b >> 5) & 0x01) == 1) { led6On(); } else { led6Off(); }
	if (((b >> 6) & 0x01) == 1) { led7On(); } else { led7Off(); }
	if (((b >> 7) & 0x01) == 1) { led8On(); } else { led8Off(); }
	if (((b >> 8) & 0x01) == 1) { led9On(); } else { led9Off(); }
	if (((b >> 9) & 0x01) == 1) { led10On(); } else { led10Off(); }
	if (((b >> 10) & 0x01) == 1) { led11On(); } else { led11Off(); }
	if (((b >> 11) & 0x01) == 1) { led12On(); } else { led12Off(); }
}

void LED12_Number(int num)
{
  LED12_WriteByte(LED12_HEX[num-1]);
}


void clearAllClock(void) //exercise 7
{
	LED12_WriteByte(LED12_HEX_OFF);//off everything
}

// turn 1 led on, keeping other in its state
void LED12_WriteOnByte(int b)
{
	if (((b >> 0) & 0x01) == 1) { led1On(); }
	if (((b >> 1) & 0x01) == 1) { led2On(); }
	if (((b >> 2) & 0x01) == 1) { led3On(); }
	if (((b >> 3) & 0x01) == 1) { led4On(); }
	if (((b >> 4) & 0x01) == 1) { led5On(); }
	if (((b >> 5) & 0x01) == 1) { led6On(); }
	if (((b >> 6) & 0x01) == 1) { led7On(); }
	if (((b >> 7) & 0x01) == 1) { led8On(); }
	if (((b >> 8) & 0x01) == 1) { led9On(); }
	if (((b >> 9) & 0x01) == 1) { led10On(); }
	if (((b >> 10) & 0x01) == 1) { led11On(); }
	if (((b >> 11) & 0x01) == 1) { led12On(); }
}

// turn 1 led off, keeping other in its state
void LED12_WriteOffByte(int b)
{
	if (((b >> 0) & 0x01) == 1) { led1Off(); }
	if (((b >> 1) & 0x01) == 1) { led2Off(); }
	if (((b >> 2) & 0x01) == 1) { led3Off(); }
	if (((b >> 3) & 0x01) == 1) { led4Off(); }
	if (((b >> 4) & 0x01) == 1) { led5Off(); }
	if (((b >> 5) & 0x01) == 1) { led6Off(); }
	if (((b >> 6) & 0x01) == 1) { led7Off(); }
	if (((b >> 7) & 0x01) == 1) { led8Off(); }
	if (((b >> 8) & 0x01) == 1) { led9Off(); }
	if (((b >> 9) & 0x01) == 1) { led10Off(); }
	if (((b >> 10) & 0x01) == 1) { led11Off(); }
	if (((b >> 11) & 0x01) == 1) { led12Off(); }
}
void setNumberOnClock(int num)//excercise 8
{
	  LED12_WriteOnByte(LED12_HEX[num-1]);
}
void clearNumberOnClock(int num)//excercise 9
{
	  LED12_WriteOffByte(LED12_HEX[num-1]);
}
