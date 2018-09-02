/*******************************************************************************************************************************//**
 *
 * @file		Keyboard.h
 * @brief		Módulo para el manejo de un Teclado
 * @date		22/05/2016
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/
/* Defines utilizados para el parametro seleccionar el driver a utilizar en la funcion Keyboard_Init()
 * Se puede utilizar mas de un driver simultanemante
 * */
#define STANDARD_KEYBOARD	(1U << 0)	/* Teclado estandar */
#define MATRIX_KEYBOARD		(1U << 1)	/* Teclado matricial */

/* Define que utiliza la funcion Keyboard_GetKey() para indicar que no se presiono ninguna tecla */
#define NO_KEY	-1

/***********************************************************************************************************************************
 *** MACROS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES (extern)
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES
 **********************************************************************************************************************************/
/*******************************************************************************************************************************//**
 * @fn			bool Keyboard_Init(uint8_t driverSelected)
 * @brief		Inicializa el módulo del Teclado. Permite al usuario seleccionar que teclado utilizar.
 * 				Ejemplo de utilizacion:
 * 				Keyboard_Init(STANDARD_KEYBOARD) => Selecciona el teclado estandar
 * 				Keyboard_Init(MATRIX_KEYBOARD)	 => Selecciona el teclado matricial
 * 				Keyboard_Init(STANDARD_KEYBOARD | MATRIX_KEYBOARD)	=> Selecciona el teclado estandar + el matricial
 * @param[in]	driverSelected:	Utilizar los defines publicados para tal fin (Ej: STANDARD_KEYBOARD, MATRIX_KEYBOARD)
 * @return		true si la inicialización fue satisfactoria, false si no lo fue.
 * @note		El módulo esta preparado para trabajar como máximo con 32 teclas. La sumatoria de las teclas de cada teclado
 *              seleccionado no puede superar este valor. La limitación radica en como estan implementadas las fucniones.
 **********************************************************************************************************************************/
bool Keyboard_Init(uint8_t driverSelected);

/*******************************************************************************************************************************//**
 * @fn			int8_t Keyboard_GetKey(void)
 * @brief		Retorna la última tecla que fue presionada desde el ultimo llamado a esta funcion.
 * @param		void
 * @return		Si no hubo tecla presionada retorna NO_KEY (-1). Si hubo, retorna el número de tecla presionada (0 a 31).
 * @note        Importante: Si el usuario selecciona un solo tipo de teclado y el mismo tiene por ejemplo 5 teclas, el retorno
 *              ira desde 0 hasta 4. Si el usuario selecciona dos tipos de teclados y por ejemplo el primero tiene 5 teclas y el
 *              segundo 10, el retorno ira desde 0 hasta 14, siendo desde 0 a 4 las teclas correspondientes al primer teclado y
 *              desde 5 hasta 14 las del segundo.
 **********************************************************************************************************************************/
int8_t Keyboard_GetKey(void);

/*******************************************************************************************************************************//**
 * @fn			void Keyboard_Update(void)
 * @brief		Funcion que debe ser llamada periodicamente cada 5 milisegundos para el correcto funcionamiento del modulo.
 * @param		void
 * @return		void
 **********************************************************************************************************************************/
void Keyboard_Update(void);

/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* KEYBOARD_H_ */


