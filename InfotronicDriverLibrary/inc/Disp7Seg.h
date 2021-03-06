/*******************************************************************************************************************************//**
 *
 * @file		Disp7Seg.h
 * @brief		Módulo para manejo de un Display de 7 segmentos conformado por "N" Digitos.
 * @date		21/05/2016
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef DISP7SEG_H_
#define DISP7SEG_H_


/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/


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
 * @fn			void Disp7Seg_Init(void)
 * @brief		Inicializa los pines asociados al Display. Deja el Display Apagado
 * @param		void
 * @return		void
 **********************************************************************************************************************************/
void Disp7Seg_Init(void);

/*******************************************************************************************************************************//**
 * @fn			void Disp7Seg_ShowValue(uint32_t value)
 * @brief		Muestra en el display el valor pasado como parametro
 * @param[in]	value:	Valor a ser mostrado
 * @return		void
 **********************************************************************************************************************************/
void Disp7Seg_ShowValue(uint32_t value);

/*******************************************************************************************************************************//**
 * @fn			void Disp7Seg_ShowPattern(uint8_t digNum, uint8_t pattern)
 * @brief		Muestra un patron en el digito pasado como parametro
 * @param[in]	digNum:	 Número de digito en el cual se quiere mostrar el patron o código
 * @param[in]	pattern: Patron o código a ser mostrado: bit0 representa el segmento A, bit1 el B y asi siguiendo (0: off, 1: on)
 * @return		void
 **********************************************************************************************************************************/
void Disp7Seg_ShowPattern(uint8_t digNum, uint8_t pattern);

/*******************************************************************************************************************************//**
 * @fn			void Disp7Seg_DecimalPoint(uint8_t digNum, bool state)
 * @brief		Cambia el estado del punto decimal del digito pasado como parámetro
 * @param[in]	digNum:	 Número de digito en el cual se quiere mostrar el punto decimal
 * @param[in]	state:	 true: enciende el punto decimal, false: apaga el punto decimal
 * @return		void
 **********************************************************************************************************************************/
void Disp7Seg_DecimalPoint(uint8_t digNum, bool state);

/*******************************************************************************************************************************//**
 * @fn			void Disp7Seg_Update(void)
 * @brief		Debe ser invocada periodicamenete con una frecuencia aproximada de 50Hz * Cantidad de Digitos
 * @param		void
 * @return		void
 **********************************************************************************************************************************/
void Disp7Seg_Update(void);

/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* DISP7SEG_H_ */

