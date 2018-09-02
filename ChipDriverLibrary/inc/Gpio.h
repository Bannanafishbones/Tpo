/*******************************************************************************************************************************//**
 *
 * @file		Gpio.h
 * @brief		Módulo para manejo de Entradas y Salidas de Propósito General (GPIO: General Purpose IO).
 * @date		21/05/2016
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include <lpc_types.h>
#include "Pin.h"

/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS PUBLICOS
 **********************************************************************************************************************************/
typedef enum {DIR_IN = 0, DIR_OUT = 1} GpioDir_e;
#define PARAM_GPIODIR(value) ((value == DIR_IN) || (value == DIR_OUT))

typedef enum {LOW = 0, HIGH = 1} GpioValue_e;
#define PARAM_GPIOVALUE(value) ((value == LOW) || (value == HIGH))

typedef enum {NEGATIVE = 0, POSITIVE = 1} GpioLogic_e;
#define PARAM_GPIOLOGIC(value) ((value == NEGATIVE) || (value == POSITIVE))

typedef enum {IO_OFF = 0, IO_ON = 1} IOState_e;

typedef struct
{
	uint32_t port     : 3;
	uint32_t pin	  : 5;
	uint32_t resMode  : 2;
	uint32_t odMode	  : 1;
	uint32_t logic    : 1;
	uint32_t dir      : 1;
	uint32_t reserved : 3;
} Gpio_t;

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES (extern)
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES
 **********************************************************************************************************************************/

/*******************************************************************************************************************************//**
 * @fn			void Gpio_Init(Gpio_t gpio)
 * @brief		Configura un pin de un puerto segun la estrucutura pasada como parametro.
 * @param[in]	gpio:		Estructura de datos donde se encuentra la configuración del pin
 * @return		void
 **********************************************************************************************************************************/
void Gpio_Init(Gpio_t gpio);

/*******************************************************************************************************************************//**
 * @fn			void Gpio_SetDir(uint8_t port, uint8_t pin, GpioDir_e dir)
 * @brief		Configura un pin de un puerto en entrada o salida.
 * @param[in]	port:		Número de Puerto. Debe ser uno de los siguientes: PORT_0, PORT_1, PORT_2, PORT_3, PORT_4.
 * @param[in]	pin:		Número de Pin. Debe ser uno de los siguientes: Desde PIN_0 hasta PIN_31.
 * @param[in]	dir:		Dirección del Pin. Debe ser uno de los siguientes: DIR_IN o DIR_OUT.
 * @return		void
 **********************************************************************************************************************************/
void Gpio_SetDir(uint8_t port, uint8_t pin, GpioDir_e dir);

/*******************************************************************************************************************************//**
 * @fn			void Gpio_SetPin(uint8_t port, uint8_t pin)
 * @brief		Pone un pin de un puerto en estado alto.
 * @param[in]	port:		Número de Puerto. Debe ser uno de los siguientes: PORT_0, PORT_1, PORT_2, PORT_3, PORT_4.
 * @param[in]	pin:		Número de Pin. Debe ser uno de los siguientes: Desde PIN_0 hasta PIN_31.
 * @return		void
 **********************************************************************************************************************************/
void Gpio_SetPin(uint8_t port, uint8_t pin);

/*******************************************************************************************************************************//**
 * @fn			void Gpio_ClrPin(uint8_t port, uint8_t pin)
 * @brief		Pone un pin de un puerto en estado bajo.
 * @param[in]	port:		Número de Puerto. Debe ser uno de los siguientes: PORT_0, PORT_1, PORT_2, PORT_3, PORT_4.
 * @param[in]	pin:		Número de Pin. Debe ser uno de los siguientes: Desde PIN_0 hasta PIN_31.
 * @return		void
 **********************************************************************************************************************************/
void Gpio_ClrPin(uint8_t port, uint8_t pin);

/*******************************************************************************************************************************//**
 * @fn			void Gpio_SetPinValue(uint8_t port, uint8_t pin, GpioValue_e pinValue)
 * @brief		Pone un pin de un puerto en el estado pasado como parametro.
 * @param[in]	port:		Número de Puerto. Debe ser uno de los siguientes: PORT_0, PORT_1, PORT_2, PORT_3, PORT_4.
 * @param[in]	pin:		Número de Pin. Debe ser uno de los siguientes: Desde PIN_0 hasta PIN_31.
 * @param[in]	pinValue:	Valor del Pin. Debe ser uno de los siguientes: LOW o HIGH.
 * @return		void
 **********************************************************************************************************************************/
void Gpio_SetPinValue(uint8_t port, uint8_t pin, GpioValue_e pinValue);

/*******************************************************************************************************************************//**
 * @fn			GpioValue_e Gpio_GetPinValue(uint8_t port, uint8_t pin)
 * @brief		Retorna el valor de un pin de un puerto.
 * @param[in]	port:		Número de Puerto. Debe ser uno de los siguientes: PORT_0, PORT_1, PORT_2, PORT_3, PORT_4.
 * @param[in]	pin:		Número de Pin. Debe ser uno de los siguientes: Desde PIN_0 hasta PIN_31.
 * @return		valor del pin (LOW, HIGH)
 **********************************************************************************************************************************/
GpioValue_e Gpio_GetPinValue(uint8_t port, uint8_t pin);

/*******************************************************************************************************************************//**
 * @fn			void Gpio_TurnOn(Gpio_t gpio)
 * @brief		Enciende un pin de un puerto. La funcion tiene en cuenta la logica del pin configurada.
 *              Si es logica positiva pone el pin en estado HIGH y si es logica negativa lo pone en estado LOW.
 * @param[in]	gpio:		Estructura de datos donde se encuentra la configuración del pin
 * @return		void
 **********************************************************************************************************************************/
void Gpio_TurnOn(Gpio_t gpio);

/*******************************************************************************************************************************//**
 * @fn			void Gpio_TurnOff(Gpio_t gpio)
 * @brief		Apaga un pin de un puerto. La funcion tiene en cuenta la logica del pin configurada.
 *              Si es logica positiva pone el pin en estado LOW y si es logica negativa lo pone en estado HIGH.
 * @param[in]	gpio:		Estructura de datos donde se encuentra la configuración del pin
 * @return		void
 **********************************************************************************************************************************/
void Gpio_TurnOff(Gpio_t gpio);

/*******************************************************************************************************************************//**
 * @fn			IOState_e Gpio_GetPinState(Gpio_t gpio)
 * @brief		Retorna el estado del pin teniendo en cuenta la logica del pin configurada.
 * @param[in]	gpio:		Estructura de datos donde se encuentra la configuración del pin
 * @return		Estado del pin (IO_OFF / IO_ON)
 **********************************************************************************************************************************/
IOState_e Gpio_GetPinState(Gpio_t gpio);

/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* GPIO_H_ */


