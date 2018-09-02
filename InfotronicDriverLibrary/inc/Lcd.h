/*******************************************************************************************************************************//**
 *
 * @file		Lcd.h
 * @brief		Módulo para manejo del LCD de caracteres
 * @date		26/09/2013
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/********************************************************************************************************
*** MODULE
********************************************************************************************************/
#ifndef LCD_H_
#define LCD_H_

/********************************************************************************************************
*** INCLUDES
********************************************************************************************************/
#include "Gpio.h"
#include "lpc_types.h"


/********************************************************************************************************
*** DEFINES
********************************************************************************************************/


// Valores para los parámetros de la MACRO: LCD_ENTRYmODEsET(ID, SH)
// Parámetro ID
#define DECREMENT				0x00
#define INCREMENT				0x02
 // Parámetro SH
#define DISPLAY_DO_NOT_SHIFT	0x00
#define DISPLAY_SHIFT			0x01

// Valores para los parámetros de las MACROs: LCD_DISPLAYoNoFFcONTROL(D, C, B) y LCD_CURSORcONTROL(C, B)
// Parámetro D
#define DISPLAY_OFF				0x00
#define DISPLAY_ON				0x04
// Parámetro C
#define CURSOR_OFF				0x00
#define CURSOR_ON				0x02
// Parámetro B
#define BLINK_OFF				0x00
#define BLINK_ON				0x01

// Valores para los parámetros de la MACRO: LCD_SHIFTcURSOR(RL)
// Parámetro RL
#define CURSOR_LEFT				0x00
#define CURSOR_RIGHT			0x04

// Valores para los parámetros de la MACRO: LCD_SHIFTdISPLAY(RL)
// Parámetro RL
#define DISPLAY_LEFT			0x00
#define DISPLAY_RIGHT			0x04

// Valores de Filas (Se comienza a contar desde la Fila 1)
#define LCD_ROW1			(1)
#define LCD_ROW2			(2)
#define LCD_ROW3			(3)
#define LCD_ROW4			(4)

// Valores de Columnas (Se comienza a contar desde la Columna 1)
#define LCD_COLUMN1			(1)
#define LCD_COLUMN2			(2)
#define LCD_COLUMN3			(3)
#define LCD_COLUMN4			(4)
#define LCD_COLUMN5			(5)
#define LCD_COLUMN6			(6)
#define LCD_COLUMN7			(7)
#define LCD_COLUMN8			(8)
#define LCD_COLUMN9			(9)
#define LCD_COLUMN10		(10)
#define LCD_COLUMN11		(11)
#define LCD_COLUMN12		(12)
#define LCD_COLUMN13		(13)
#define LCD_COLUMN14		(14)
#define LCD_COLUMN15		(15)
#define LCD_COLUMN16		(16)
#define LCD_COLUMN17		(17)
#define LCD_COLUMN18		(18)
#define LCD_COLUMN19		(19)
#define LCD_COLUMN20		(20)

// Algunos Valores útiles de filas y columnas
#define LCD_FIRST_ROW		LCD_ROW1
#define LCD_LAST_ROW		LCD_ROW4
#define LCD_FIRST_COLUMN	LCD_COLUMN1
#define LCD_LAST_COLUMN		LCD_COLUMN20

// Caracteres Especiales
#define LCD_VOID                            0
#define LCD_SPECIALcHAR_ARROW_UP			1
#define LCD_SPECIALcHAR_ARROW_DOWN			2
#define LCD_SPECIALcHAR_ARROW_RIGHT			3
#define LCD_SPECIALcHAR_ARROW_LEFT			4
#define LCD_SPECIALcHAR_GRADES				5
#define LCD_SPECIALcHAR_CHECKED				6
#define LCD_SPECIALcHAR_BATTERY_CHARGING	7


/********************************************************************************************************
*** MACROS
********************************************************************************************************/
// Macros para la escritura de los Códigos de Instrucción definidos
/***************************************************************************//**
 * @fn			LCD_CLEARdISPLAY()
 * @brief		Limpia toda la memoria DDRAM. Setea la dirección de la DDRAM en 0.
 * 				Retorna el cursor a la primera posición de la primera línea.
 * 				Entra en el modo incremental (ID = High), y el estado del display no se
 * 				altera (SH permanece igual).
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 0 0 0 0 0 0 1
 * @param[in]	void
 * @return		void
 ******************************************************************************/
#define	LCD_CLEARdISPLAY()	LCD_WRiNSTRUCTIONrEGISTER(CLEAR_DISPLAY);

/***************************************************************************//**
 * @fn			LCD_RETURNhOME()
 * @brief		Setea la dirección de la DDRAM en 0. Retorna el cursor a la primera
 * 				posición de la primera línea.
 * 				Retorna el display a su estado original, si este había sido movido.
 * 				El contenido de la DDRAM no se altera.
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 0 0 0 0 0 1 X
 * @param[in]	void
 * @return		void
 ******************************************************************************/
#define	LCD_RETURNhOME()	LCD_WRiNSTRUCTIONrEGISTER(RETURN_HOME);

/***************************************************************************//**
 * @fn			LCD_ENTRYmODEsET()
 * @brief		Setea la dirección en la cual se moverá el cursor y el display.
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 0 0 0 0 1 ID SH
 * @param[in]	ID: Increment / decrement of DDRAM address (cursor or blink)
 * 					- DECREMENT, EL cursor/blink se mueve hacia la izquierda y la
 * 					             dirección de la DDRAM se decrementa en 1.
 * 					- INCREMENT, EL cursor/blink se mueve hacia la derecha y la
 * 					               dirección de la DDRAM se incrementa en 1.
 * 					(Nota: LA CGRAM opera de la misma manera, cuando se lee o
 * 					       escribe a la CGRAM)
 * @param[in]	SH: Shift of entire display
 * 					- DISPLAY_DO_NOT_SHIFT, EL display no se mueve.
 * 					- DISPLAY_SHIFT, Cuando se ejecuta una operación de escritura,
 * 					                 el display se mueve segun I_D. EL cursor/blink
 * 					                 se mueve hacia la izquierda y la dirección de
 * 					                 la DDRAM se decrementa en 1.
 * @return		void
 ******************************************************************************/
#define	LCD_ENTRYmODEsET(ID, SH)	LCD_WRiNSTRUCTIONrEGISTER(ENTRY_MODE_SET | ID | SH)

/***************************************************************************//**
 * @fn			LCD_DISPLAYoNoFFcONTROL()
 * @brief		Controla el estado ON/OFF del display, cursor y parpadeo del cursor.
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 0 0 0 1 D C B
 * @param[in]	D: Display ON/OFF Control Bit
 * 					- DISPLAY_OFF, Display OFF
 * 					- DISPLAY_ON, Display ON
 * @param[in]	C: Cursor ON/OFF Control Bit
 * 					- CURSOR_OFF, Cursor OFF
 * 					- CURSOR_ON, Cursor ON
 * @param[in]	B: Cursor Blink ON/OFF Control Bit
 * 					- BLINK_OFF, Cursor Blink OFF
 * 					- BLINK_ON, Cursor Blink ON
 * @return		void
 ******************************************************************************/
#define	LCD_DISPLAYoNoFFcONTROL(D, C, B)	LCD_WRiNSTRUCTIONrEGISTER(DISPLAY_ON_OFF_CONTROL | D | C | B)

/***************************************************************************//**
 * @fn			LCD_CURSORcONTROL()
 * @brief		Controla el estado ON/OFF del cursor y parpadeo del cursor, dejando
 * 				siempre al display prendido.
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 0 0 0 1 1 C B
 * @param[in]	C: Cursor ON/OFF Control Bit
 * 					- CURSOR_OFF, Cursor OFF
 * 					- CURSOR_ON, Cursor ON
 * @param[in]	B: Cursor Blink ON/OFF Control Bit
 * 					- BLINK_OFF, Cursor Blink OFF
 * 					- BLINK_ON, Cursor Blink ON
 * @return		void
 ******************************************************************************/
#define	LCD_CURSORcONTROL(C, B)	LCD_DISPLAYoNoFFcONTROL(DISPLAY_ON, C, B)

/***************************************************************************//**
 * @fn			LCD_SHIFTcURSOR()
 * @brief		Mueve el cursor una posición según RL.
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 0 0 1 0 RL X X
 * @param[in]	RL: Right / Left
 * 					- CURSOR_LEFT, EL cursor se mueve hacia la izquierda.
 * 					- CURSOR_RIGHT, EL cursor se mueve hacia la derecha.
 * @return		void
 ******************************************************************************/
#define	LCD_SHIFTcURSOR(RL)	LCD_WRiNSTRUCTIONrEGISTER(SHIFT_CURSOR | RL)

/***************************************************************************//**
 * @fn			LCD_SHIFTdISPLAY()
 * @brief		Mueve el display una posición según RL.
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 0 0 1 1 RL X X
 * @param[in]	RL: Right / Left
 * 					- DISPLAY_LEFT, EL display se mueve hacia la izquierda.
 * 					- DISPLAY_RIGHT, EL display se mueve hacia la derecha.
 * @return		void
 ******************************************************************************/
#define	LCD_SHIFTdISPLAY(RL)	LCD_WRiNSTRUCTIONrEGISTER(SHIFT_DISPLAY | RL)

/***************************************************************************//**
 * @fn			LCD_FUNCTIONsET()
 * @brief		Setea el tipo de interface, la cantidad de líneas del display
 * 				y el tamaño de los caracteres.
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 0 1 DL N F X X
 * @param[in]	DL: Interface Data Length Control Bit
 * 					- DL_4BITS, 4-bit bus mode with MPU
 * 					- DL_8BITS, 8-bit bus mode with MPU
 * @param[in]	N: Display Line Number Control Bit
 * 					- N_1LINE, 1-line display mode
 * 					- N_2LINE, 2-line display mode
 * @param[in]	F: Display Font Type Control Bit
 * 					- F_5x8, 5x8 dots format display mode
 * 					- F_5x11, 5x11 dots format display mode
 * @return		void
 ******************************************************************************/
#define	LCD_FUNCTIONsET(DL, N, F)	LCD_WRiNSTRUCTIONrEGISTER(FUNCTION_SET | DL | N | F)

/***************************************************************************//**
 * @fn			LCD_CGRAMaDDRESSsET()
 * @brief		Carga la dirección de la CGRAM en el Address Counter (AC)
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 0 1 AC5 AC4 AC3 AC2 AC1 AC0
 * @param[in]	ADD: Dirección de la memoria
 * @return		void
 ******************************************************************************/
#define	LCD_CGRAMaDDRESSsET(ADD)	LCD_WRiNSTRUCTIONrEGISTER(CGRAM_ADDRESS_SET | ADD)

/***************************************************************************//**
 * @fn			LCD_CGRAMaDDRESSsET()
 * @brief		Carga la dirección de la CGRAM en el Address Counter (AC)
 * 				El dato está formado por la siguiente palabra:
 * 				DB7:DB0 = 1 AC6 AC5 AC4 AC3 AC2 AC1 AC0
 * @param[in]	ADD: Dirección de la memoria
 * @return		void
 ******************************************************************************/
#define	LCD_DDRAMaDDRESSsET(ADD)	LCD_WRiNSTRUCTIONrEGISTER(DDRAM_ADDRESS_SET | ADD)

/***************************************************************************//**
 * @fn			LCD_WRdATArEGISTER()
 * @brief		Escribe 1 byte de datos en la memoria del LCD. La memoria
 *              puede ser la DDRAM o la CGRAM y debe seleccionarse con una
 *              instrucción previa (DDRAM address set, CGRAM address set).
 *              Después de cada operación de escritura la dirección es
 *              incrementada/decrementada automáticamente según el "entry mode"
 * @param[in]	data: Dato a escribir en la memoria DDRAM/CGRAM
 * @return		void
 ******************************************************************************/
#define LCD_WRdATArEGISTER(data)		Lcd_WrLcdRegister(DATA_REGISTER, data)

/***************************************************************************//**
 * @fn			LCD_WRiNSTRUCTIONrEGISTER()
 * @brief		Escribe 1 byte al registro IR (Instruction Register).
 * 		        Existe un conjunto predeterminado de Códigos de Instrucción,
 * 		        y los mismos est{an definidos en las hojas de datos del LCD.
 * @param[in]	data: Código de Instrucción. Uno de los valores de la enumeración
 *              INSTRUCTION_CODE
 * @return		void
 ******************************************************************************/
#define LCD_WRiNSTRUCTIONrEGISTER(data)	Lcd_WrLcdRegister(INSTRUCTION_REGISTER, data)

// Macro para FORZAR la deshabilitación de la alimentación del LCD en caso de emergencia
/***************************************************************************//**
 * @fn			CLR_LCD_VcTRL()
 * @brief		Deshabilita la alimentacón del LCD. Simplemente le quita la
 *              alimentación. Debe usarse solo en caso de ser necesario quitar
 *              la alimentación sin pérdidas de tiempo. Para otros casos se
 *              debe utilizar la función LCD_Off()
 * @param[in]	void
 * @return		void
 ******************************************************************************/
#define CLR_LCD_VcTRL()


/********************************************************************************************************
*** DATA TYPES
********************************************************************************************************/
// Enumeraciones
/**
 * @brief INSTRUCTION_CODE:	Define los Códigos de Instrucción que pueden ser escritos en el LCD.
 *                          Los mismos están especificados en las Hojas de Datos.
 */
typedef enum
{
	CLEAR_DISPLAY 			= 0x01,
	RETURN_HOME 			= 0x02,
	ENTRY_MODE_SET 			= 0x04,
	DISPLAY_ON_OFF_CONTROL 	= 0x08,
	SHIFT_CURSOR			= 0x10,
	SHIFT_DISPLAY			= 0x18,
	FUNCTION_SET			= 0x20,
	CGRAM_ADDRESS_SET		= 0x40,
	DDRAM_ADDRESS_SET		= 0x80
}INSTRUCTION_CODE;

/**
 * @brief REGISTER_SELECT: Define el tipo de dato a escribir en el LCD
 */
typedef enum {INSTRUCTION_REGISTER = 0, DATA_REGISTER = 1} REGISTER_SELECT;

/**
 * @brief WRITErEAD_SELECT:	Define el tipo de operación (LECTURA O ESCRITURA)
 */
typedef enum {WRITE_OPERATION = 0, READ_OPERATION = 1} WRITErEAD_SELECT;

/**
 * @brief TEXT_JUST: Define el tipo de justificación del Texto (Izquierda o Derecha)
 */
typedef enum {LEFT_TEXT, RIGHT_TEXT} TEXT_JUST;

// Estructuras de Datos
/**
 * @brief LCD_POSITION_TypeDef:	Estructura de Datos que define una coordenada (x, y)
 * El mínimo valor de "x" o "y" es uno.
 */
typedef struct
{
	uint8_t x;
	uint8_t y;
}LCD_POSITION_TypeDef;


/********************************************************************************************************
*** PUBLIC GLOBAL VARIABLES
********************************************************************************************************/


/********************************************************************************************************
*** PUBLIC FUNCTION PROTOTYPES
********************************************************************************************************/
/*******************************************************************************************************************************//**
 * @fn			void Lcd_Init(void)
 * @brief		Inicializa los pines conectados al LCD y dispara el comienzo de la rutina de Inicialización de Software del LCD
 *              que trabaja en conjunto con el Lcd_Update()
 * @param		void
 * @return		void
 **********************************************************************************************************************************/
void Lcd_Init(void);

/*******************************************************************************************************************************//**
 * @fn			void Lcd_Update(void)
 * @brief		Debe ser invocacda cada 10 milisegundos.
 *         	    Es parte del proceso de Inicialización de Software del LCD. Gestiona el tiempo de espera necesario para las distintas
 *              partes de la inicialización, la cual está detallada en las Hojas de Datos del LCD.
 * @param		void
 * @return		void
 **********************************************************************************************************************************/
void Lcd_Update(void);

/*******************************************************************************************************************************//**
 * @fn			void Lcd_SetCursorPosition(uint8_t x, uint8_t y)
 * @brief		Posiciona el Cursor en el lugar determinado por los parámetros
 * @param[in]	x:  Número de Columna (Mínimo Valor 1)
 * @param[in]	y:  Número de Fila (Mínimo Valor 1)
 * @return		void
 **********************************************************************************************************************************/
void Lcd_SetCursorPosition(uint8_t x, uint8_t y);

/*******************************************************************************************************************************//**
 * @fn			void Lcd_WrLcdRegister(REGISTER_SELECT rs, uint8_t data)
 * @brief		Escribe 1 byte al registro IR (Instruction Register), ó bien escribe 1 byte de datos en la memoria del LCD, segun
 *              se indica en el parámetro rs
 * @param[in]	rs:  Selecciona el destino del dato
 * 				 - INSTRUCTION_REGISTER: Escribe en el registro IR
 * 				 - DATA_REGISTER: Escribe en la memoria del LCD (DDRAM ó CGRAM)
 * @param[in]	data: Dato a escribir en el registro IR o en la memoria de datos.
 * @return		void
 **********************************************************************************************************************************/
void Lcd_WrLcdRegister(REGISTER_SELECT rs, uint8_t data);

/*******************************************************************************************************************************//**
 * @fn			int Lcd_printf(const char *format, ... )
 * @brief		Versión de prinft para LCD: Escribe una cadena en el LCD a partir de la posición en la cual se encuentra el cursor.
 *              La cadena puede contener especificadores de formato como por ejemplo: %d, %c, %s
 * @param[in]	format: Cadena de texto (puede contener %d, %c, %s, etc...)
 * @param[in]	...:    Parámetros variables, uno por cada especificador de  formato que se haya usado dentro de la Cadena "format"
 * @return		Cantidad de caracteres que se han escrito. Un valor negativo indica que ha ocurrido un error.
 **********************************************************************************************************************************/
int Lcd_printf(const char *format, ... );

/*******************************************************************************************************************************//**
 * @fn			int Lcd_puts(const char *string)
 * @brief		Versión de puts para LCD. Escribe una cadena en el LCD a partir de la posición en la cual se encuentra el cursor.
 *              Nota: Al final de la cadena NO adiciona un salto de linea ('\n')
 * @param[in]	string: Cadena de texto
 * @return		Éxito: Valor no negativo. Error: retorna el caracter EOF
 **********************************************************************************************************************************/
int Lcd_puts(const char *string);

/*******************************************************************************************************************************//**
 * @fn			int Lcd_putchar(char character)
 * @brief		Versión de putchar para LCD. Escribe un caracter en el LCD en la posición en la cual se encuentra el cursor.
 *              Nota: No esta implementado los caracteres especiales como retorno de linea (\r), salto de linea (\n), tabulación (\t), etc.
 * @param[in]	character: Caracter a escribir
 * @return		Éxito: retorna el caracter escrito. Error: retorna el caracter EOF
 **********************************************************************************************************************************/
int Lcd_putchar(char character);

/*******************************************************************************************************************************//**
 * @fn			void Lcd_outtextxy(uint8_t x, uint8_t y, const char *string)
 * @brief		Versión de outtextxt para LCD: Esta función es usada para mostrar una cadena de caracteres en una posición específica.
 *              El tipo de justificación del texto con respecto a la posición del cursor esta dado por lo que se haya configurado
 *              previamente mediante la función LCD_settextjustify()
 * @param[in]	x, y: Posición a partir de la cual se escribe
 * @param[in]	string: Puntero al texto a mostrar
 * @return		void
 **********************************************************************************************************************************/
void Lcd_outtextxy(uint8_t x, uint8_t y, const char *string);

/*******************************************************************************************************************************//**
 * @fn			void Lcd_settextjustify (TEXT_JUST textJust)
 * @brief		Versión de settextjustify para LCD: Esta función es usada para especificar el método en el cual el texto es colocado en la
 *              pantalla, mediante la función LCD_outtextxt(), con relación a la posición del cursor.
 * @param[in]	textJust: Indica el tipo de justificación del texto
 * @return		void
 **********************************************************************************************************************************/
void Lcd_settextjustify (TEXT_JUST textJust);


/********************************************************************************************************
*** MODULE END
********************************************************************************************************/

#endif
