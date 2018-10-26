/*
 * LPC1769.h
 */

#ifndef LPC1769_H_
#define LPC1769_H_

#include <stdint.h>

#define     __I     volatile const     /*!< defines 'read only' permissions                 */
#define     __O     volatile           /*!< defines 'write only' permissions                */
#define     __IO    volatile           /*!< defines 'read / write' permissions              */


/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/


/*------------- System Control (SC) ------------------------------------------*/
#define FLASHCFG	(*((uint32_t *)0x400FC000UL)) 	/* Flash access configuration */
#define PLL0CON		(*((uint32_t *)0x400FC080UL))	/* Registro de control del PLL0	*/
#define	PLL0CFG		(*((uint32_t *)0x400FC084UL))	/* Registro de configuracion del PLL0 */
#define	PLL0STAT	(*((uint32_t *)0x400FC088UL))	/* Registro de estado del PLL0 */
#define	PLL0FEED	(*((uint32_t *)0x400FC08CUL))	/* Registro de control del PLL0 */
#define	PLL1CON		(*((uint32_t *)0x400FC0A0UL))	/* Registro de control del PLL1 */
#define	PLL1CFG		(*((uint32_t *)0x400FC0A4UL))	/* Registro de configuracion del PLL1 */
#define	PLL1STAT	(*((uint32_t *)0x400FC0A8UL))	/* Registro de estado del PLL1 */
#define	PLL1FEED	(*((uint32_t *)0x400FC0ACUL))	/* Registro de control del PLL1 */
#define PCONP	    (*((uint32_t *)0x400FC0C4UL))	/* Registro de Control de Alimentación de Periféricos */
#define CCLKCFG		(*((uint32_t *)0x400FC104UL))	/* Registro de configuracion del clock */
#define USBCLKCFG	(*((uint32_t *)0x400FC108UL))	/* Registro de Configuración de Clock de USB */
#define CLKSRCSEL	(*((uint32_t *)0x400FC10CUL))	/* Registro de seleccion del clock *//*usa 2 bits*/
#define SCS			(*((uint32_t *)0x400FC1A0UL))	/* Registro de control de sistema y registro de status */
#define PCLKSEL0	(*((uint32_t *)0x400FC1A8UL))	/* Registro de Selección de Clock de Periféricos 0 */
#define PCLKSEL1	(*((uint32_t *)0x400FC1ACUL))	/* Registro de Selección de Clock de Periféricos 1 */
#define CLKOUTCFG	(*((uint32_t *)0x400FC1C8UL))	/* Registro de Configuración de Salida de Clock */


/*------------- Pin Connect Block (PINCON) -----------------------------------*/
typedef struct
{
  __IO uint32_t PINSEL0;
  __IO uint32_t PINSEL1;
  __IO uint32_t PINSEL2;
  __IO uint32_t PINSEL3;
  __IO uint32_t PINSEL4;
  __IO uint32_t PINSEL5;
  __IO uint32_t PINSEL6;
  __IO uint32_t PINSEL7;
  __IO uint32_t PINSEL8;
  __IO uint32_t PINSEL9;
  __IO uint32_t PINSEL10;
       uint32_t RESERVED0[5];
  __IO uint32_t PINMODE0;
  __IO uint32_t PINMODE1;
  __IO uint32_t PINMODE2;
  __IO uint32_t PINMODE3;
  __IO uint32_t PINMODE4;
  __IO uint32_t PINMODE5;
  __IO uint32_t PINMODE6;
  __IO uint32_t PINMODE7;
  __IO uint32_t PINMODE8;
  __IO uint32_t PINMODE9;
  __IO uint32_t PINMODE_OD0;
  __IO uint32_t PINMODE_OD1;
  __IO uint32_t PINMODE_OD2;
  __IO uint32_t PINMODE_OD3;
  __IO uint32_t PINMODE_OD4;
  __IO uint32_t I2CPADCFG;
} LPC_PINCON_TypeDef;

/*------------- General Purpose Input/Output (GPIO) --------------------------*/
typedef struct
{
  __IO uint32_t FIODIR;
  	   uint32_t RESERVED0[3];
  __IO uint32_t FIOMASK;
  __IO uint32_t FIOPIN;
  __IO uint32_t FIOSET;
  __O  uint32_t FIOCLR;
} LPC_GPIO_TypeDef;

typedef struct
{
  __I  uint32_t IntStatus;
  __I  uint32_t IO0IntStatR;
  __I  uint32_t IO0IntStatF;
  __O  uint32_t IO0IntClr;
  __IO uint32_t IO0IntEnR;
  __IO uint32_t IO0IntEnF;
       uint32_t RESERVED0[3];
  __I  uint32_t IO2IntStatR;
  __I  uint32_t IO2IntStatF;
  __O  uint32_t IO2IntClr;
  __IO uint32_t IO2IntEnR;
  __IO uint32_t IO2IntEnF;
} LPC_GPIOINT_TypeDef;

/*------------- Timer (TIM) --------------------------------------------------*/

/*------------- Pulse-Width Modulation (PWM) ---------------------------------*/

/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/

/*------------- Serial Peripheral Interface (SPI) ----------------------------*/

/*------------- Synchronous Serial Communication (SSP) -----------------------*/

/*------------- Inter-Integrated Circuit (I2C) -------------------------------*/

/*------------- Inter IC Sound (I2S) -----------------------------------------*/

/*------------- Repetitive Interrupt Timer (RIT) -----------------------------*/

/*------------- Real-Time Clock (RTC) ----------------------------------------*/

/*------------- Watchdog Timer (WDT) -----------------------------------------*/

/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/

/*------------- Digital-to-Analog Converter (DAC) ----------------------------*/

/*------------- Motor Control Pulse-Width Modulation (MCPWM) -----------------*/

/*------------- Quadrature Encoder Interface (QEI) ---------------------------*/

/*------------- Controller Area Network (CAN) --------------------------------*/

/*------------- General Purpose Direct Memory Access (GPDMA) -----------------*/

/*------------- Universal Serial Bus (USB) -----------------------------------*/

/*------------- Ethernet Media Access Controller (EMAC) ----------------------*/



/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define LPC_GPIO_BASE         (0x2009C000UL)
#define LPC_GPIO0             ((LPC_GPIO_TypeDef      *) 0x2009C000UL    )
#define LPC_GPIO1             ((LPC_GPIO_TypeDef      *) 0x2009C020UL    )
#define LPC_GPIO2             ((LPC_GPIO_TypeDef      *) 0x2009C040UL    )
#define LPC_GPIO3             ((LPC_GPIO_TypeDef      *) 0x2009C060UL    )
#define LPC_GPIO4             ((LPC_GPIO_TypeDef      *) 0x2009C080UL    )
#define LPC_PINCON            ((LPC_PINCON_TypeDef    *) 0x4002C000UL    )

#endif /* LPC1769_H_ */
