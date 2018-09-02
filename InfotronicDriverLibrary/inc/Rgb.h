/*******************************************************************************************************************************//**
 *
 * @file		Rgb.h
 * @brief		Modulo para el manejo de un LED RGB
 * @date		20/06/2018
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef RGB_H_
#define RGB_H_

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include <stdint.h>

/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/
#define RGB_RED_LED		0
#define RGB_GREEN_LED	1
#define RGB_BLUE_LED	2

/***********************************************************************************************************************************
 *** MACROS
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** TIPO DE DATOS PUBLICOS
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** VARIABLES GLOBALES (extern)
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES
 **********************************************************************************************************************************/
/*******************************************************************************************************************************//**
 * @fn			void Rgb_Init(void)
 * @brief		Inicializa los pines conectados al LED RGB
 * @param		void
 * @return		void
 **********************************************************************************************************************************/
void Rgb_Init(void);

/*******************************************************************************************************************************//**
 * @fn			void Rgb_SetState(uint8_t color, uint8_t state)
 * @brief		Permite encender/apagar cada uno de los tres colores
 * @param[in]	color	RGB_RED_LED / RGB_GREEN_LED	/ RGB_BLUE_LED	2
 * @param[in]	state	0 OFF, !=0 ON
 * @return		void
 **********************************************************************************************************************************/
void Rgb_SetState(uint8_t color, uint8_t state);


/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* RGB_H_ */