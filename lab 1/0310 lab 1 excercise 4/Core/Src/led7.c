/*
 * led7.c
 *
 *  Created on: Oct 4, 2022
 *      Author: ASUS
 */


#include "led7.h"
#include "main.h"


int LED7_HEX[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};//0 = on/reset, 1=off/set

void LED7_WriteByte(int b);

void LED7_WriteByte(int b)//write pin with input number(from the order of LED7_HEX[])
{
  if (((b >> 0) & 0x01) == 1) { A_SET(); } else { A_RESET(); }
  if (((b >> 1) & 0x01) == 1) { B_SET(); } else { B_RESET(); }
  if (((b >> 2) & 0x01) == 1) { C_SET(); } else { C_RESET(); }
  if (((b >> 3) & 0x01) == 1) { D_SET(); } else { D_RESET(); }
  if (((b >> 4) & 0x01) == 1) { E_SET(); } else { E_RESET(); }
  if (((b >> 5) & 0x01) == 1) { F_SET(); } else { F_RESET(); }
  if (((b >> 6) & 0x01) == 1) { G_SET(); } else { G_RESET(); }

}

void display7SEG(int num)
{
  LED7_WriteByte(LED7_HEX[num]);//collect pin state from input number
}

