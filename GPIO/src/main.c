/*
===============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Copyright (C) 
 Description : main definition
===============================================================================
*/

#include "GPIO.h"
#include "system_LPC17xx.h"

#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;


int main(void) {
	
	SystemInit();

	GPIO_InitPinAsGPIO(PORT_0, PIN_22, DIR_OUT, RES_NONE, NOT_OPEN_DRAIN);

	while(1)
	{
		GPIO_SETpINsTATE(PORT_0, PIN_22, ACTIVE_HIGH, ON);
		GPIO_SETpINsTATE(PORT_0, PIN_22, ACTIVE_HIGH, OFF);
	}
	return 0 ;
}
