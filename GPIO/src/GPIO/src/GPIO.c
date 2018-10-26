/*****************************************************************************************************//**
*
* @file		GPIO.c
* @brief	Módulo para manejo de Entradas y Salidas de Propósito General (GPIO: General Purpose IO).
* 			Este módulo es un complemento al desarrollado por NXP como librería y que esta incluido en
* 			este proyecto (lpc17xx_gpio.c y lpc17xx_gpio.h)
* @version	1.00
* @date		XX/XX/XXXX
* @author	Daniel J. López Amado (DJLA)
*
*
*********************************************************************************************************
*** REVISION HISTORY
*
********************************************************************************************************/

/********************************************************************************************************
*** INCLUDES
********************************************************************************************************/
#include "gpio.h"
#include "my_types.h"


/********************************************************************************************************
*** PRIVATE DEFINES
********************************************************************************************************/


/********************************************************************************************************
*** PRIVATE MACROS
********************************************************************************************************/


/********************************************************************************************************
*** PRIVATE DATA TYPES
********************************************************************************************************/


/********************************************************************************************************
*** PRIVATE TABLES
********************************************************************************************************/


/********************************************************************************************************
*** PUBLIC GLOBAL VARIABLES
********************************************************************************************************/


/********************************************************************************************************
*** PRIVATE GLOBAL VARIABLES
********************************************************************************************************/


/********************************************************************************************************
*** PRIVATE FUNCTION PROTOTYPES
********************************************************************************************************/


/********************************************************************************************************
*** CONFIGURATION ERRORS
********************************************************************************************************/


/*-----------------------------------------------------------------------------------------------------*/


/********************************************************************************************************
*** PUBLIC FUNCTIONS
********************************************************************************************************/
/***************************************************************************//**
 * @fn			GPIO_InitPinAsGIPO()
 * @brief		Inicializa el Pin pasado como parámetro como entrada o salida
 *              y configura la resistencia asociada y el modo de salida
 * @param[in]	portNum		Número de Puerto: Debe ser uno de los siguientes:
 *                          - PORT_0
 *                          - PORT_1
 *                          - PORT_2
 *                          - PORT_3
 * @param[in]	pinNum		Número de Pin: Debe ser uno de los siguientes:
 *                          - Desde PIN_0 hasta PIN_31
 * @param[in] 	dir 		Dirección del Pin: Debe ser uno de los tipos
 *                          definidos en la enumeración PIN_DIRECTION
 * @param[in] 	resMode 	Modo de la Resistencia: Debe ser uno de los tipos
 *                          definidos en la enumeración PIN_RES_MODE
 * @param[in] 	odMode 		Modo de la Salida: Debe ser uno de los tipos
 *                          definidos en la enumeración PIN_OD_MODE
 * @return 		void
 ******************************************************************************/
void GPIO_InitPinAsGPIO(uint8_t portNum, uint8_t pinNum, PIN_DIRECTION dir, PIN_RES_MODE resMode, PIN_OD_MODE odMode)
{

	GPIO_SetOpenDrainMode( portNum, pinNum, odMode);
	GPIO_SetResistorMode ( portNum, pinNum, resMode);

	*(uint32_t) * pPincon1 = (uint32_t *)&LPC_PINCON->PINSEL0;
	*(uint32_t) * pPincon2= (uint32_t *)&LPC_GPIO0;

	if(DIR_IN == dir)
	{
		*(uint32_t *)(pPincon + portNum)->FIODIR &=~ (0x01 << pinNum);
	}
	else
	{
		*(uint32_t *)(pPincon + portNum)->FIODIR |= (0x01 << pinNum);
	}


	portNum= 2 * portNum;

		if(pinNum > 15)
		{
			pinNum-=16;
			portNum++;
		}

	*(uint32_t *)(pPincon + portNum) &=~(0x03UL << pinNum * 2);








}

/***************************************************************************//**
 * @fn			GPIO_InitPinNotAsGPIO()
 * @brief		Inicializa el Pin pasado como parámetro como entrada o salida
 *              y configura la resistencia asociada y el modo de salida
 * @param[in]	portNum		Número de Puerto: Debe ser uno de los siguientes:
 *                          - PORT_0
 *                          - PORT_1
 *                          - PORT_2
 *                          - PORT_3
 * @param[in]	pinNum		Número de Pin: Debe ser uno de los siguientes:
 *                          - Desde PIN_0 hasta PIN_31
 * @param[in] 	func 		Función del Pin: Debe ser uno de los tipos
 *                          definidos en la enumeración PIN_FUNCTION
 * @param[in] 	resMode 	Modo de la Resistencia: Debe ser uno de los tipos
 *                          definidos en la enumeración PIN_RES_MODE
 * @param[in] 	odMode 		Modo de la Salida: Debe ser uno de los tipos
 *                          definidos en la enumeración PIN_OD_MODE
 * @return 		void
 ******************************************************************************/
void GPIO_InitPinNotAsGPIO(uint8_t portNum, uint8_t pinNum, PIN_FUNCTION func, PIN_RES_MODE resMode, PIN_OD_MODE odMode)
{
	GPIO_SetPinFunc(portNum, pinNum, func);
	GPIO_SetResistorMode ( portNum, pinNum, resMode);
	GPIO_SetOpenDrainMode( portNum, pinNum, odMode);

}

/***************************************************************************//**
 * @fn			GPIO_SetPinFunc()
 * @brief		Setea la Función del Pin pasado como parámetro
 * @param[in]	portNum		Número de Puerto: Debe ser uno de los siguientes:
 *                          - PORT_0
 *                          - PORT_1
 *                          - PORT_2
 *                          - PORT_3
 * @param[in]	pinNum		Número de Pin: Debe ser uno de los siguientes:
 *                          - Desde PIN_0 hasta PIN_31
 * @param[in] 	func 		Funcion: Debe ser uno de los tipos definidos en
 *                          la enumeración PIN_FUNCTION
 * @return 		void
 ******************************************************************************/
void GPIO_SetPinFunc(uint8_t portNum, uint8_t pinNum, PIN_FUNCTION func)
{

	*(uint32_t) * pPincon =(uint32_t *)&LPC_PINCON->PINSEL0;
	portNum=portNum * 2
	if(pinNum > 15)
	{
		pinNum-=16;
		portNum++
	}

	*(uint32_t *)(pPincon + portNum) &=~(0x03UL << pinNum);
	*(uint32_t *)(pPincon + portNum) |=(func << pinNum)

}

/***************************************************************************//**
 * @fn			GPIO_SetResistorMode()
 * @brief		Setea el Modo de la resistencia asociada al Pin
 *				Nota: Los pines P0[27] a P0[30] no pueden ser seteados ya que
 *				no tiene resistencia de pull-up o pull-donw.
 * @param[in]	portNum		Número de Puerto: Debe ser uno de los siguientes:
 *                          - PORT_0
 *                          - PORT_1
 *                          - PORT_2
 *                          - PORT_3
 * @param[in]	pinNum		Número de Pin: Debe ser uno de los siguientes:
 *                          - Desde PIN_0 hasta PIN_31
 * @param[in] 	resMode 	Modo de la Resistencia: Debe ser uno de los tipos
 *                          definidos en la enumeración PIN_RES_MODE
 * @return 		void
 ******************************************************************************/
void GPIO_SetResistorMode ( uint8_t portNum, uint8_t pinNum, PIN_RES_MODE resMode)
{
	if(portNum == PORT_0 && (pinNum >= PIN_27 && pinNum <= PIN_28))
		return;
	(uint32_t) * pPincon = (uint32_t *)&LPC_PINCON->PINMODE0;
		portNum=portNum * 2
		if(pinNum > 15)
		{
			pinNum-=16;
			portNum++
		}

		*(uint32_t *)(pPincon + portNum) &=~(0x03UL << pinNum);
		*(uint32_t *)(pPincon + portNum) |=(resMode << pinNum);

}

/***************************************************************************//**
 * @fn			GPIO_SetOpenDrainMode()
 * @brief		Setea el Modo de la Salida asociada al  Pin
 *				Nota: Los pines P0[27] y P0[28] no pueden ser seteados ya que
 *				son siempre open-drain
  * @param[in]	portNum		Número de Puerto: Debe ser uno de los siguientes:
 *                          - PORT_0
 *                          - PORT_1
 *                          - PORT_2
 *                          - PORT_3
 * @param[in]	pinNum		Número de Pin: Debe ser uno de los siguientes:
 *                          - Desde PIN_0 hasta PIN_31
 * @param[in] 	odMode 	Modo de la Salida: Debe ser uno de los tipos
 *                          definidos en la enumeración PIN_OD_MODE
 * @return 		void
 ******************************************************************************/
void GPIO_SetOpenDrainMode( uint8_t portNum, uint8_t pinNum, PIN_OD_MODE odMode)
{
	uint32_t *pPinCon = (uint32_t *)&LPC_PINCON->PINMODE_OD0;

	// Para los Pines P0[27] y P0[28] retorna sin setear nada.
	if(portNum == PORT_0 && (pinNum >= PIN_27 && pinNum <= PIN_28))
		return;

	if (odMode == OPEN_DRAIN)
	{
		*(uint32_t *)(pPinCon + portNum) |= (0x01UL << pinNum);
	}
	else
	{
		*(uint32_t *)(pPinCon + portNum) &= ~(0x01UL << pinNum);
	}
}


/********************************************************************************************************
*** PRIVATE FUNCTIONS
********************************************************************************************************/


/*-----------------------------------------------------------------------------------------------------*/
