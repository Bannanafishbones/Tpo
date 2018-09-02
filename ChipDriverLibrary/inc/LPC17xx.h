/*******************************************************************************************************************************//**
 *
 * @file		LPC17xx.h
 * @brief    	CMSIS Cortex-M3 Core Peripheral Access Layer Header File for NXP LPC17xx Device Series
 * @note		Se adapta el formato al utilizado en Informatica II
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef __LPC17xx_H__
#define __LPC17xx_H__

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "lpc_types.h"

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

/** @defgroup CMSIS_175X_6X_IRQ CHIP_175X_6X: LPC175x/6x peripheral interrupt numbers
 * @{
 */

typedef enum {
	/* -------------------------  Cortex-M3 Processor Exceptions Numbers  ----------------------------- */
	Reset_IRQn                    = -15,		/*!< 1 Reset Vector, invoked on Power up and warm reset */
	NonMaskableInt_IRQn           = -14,		/*!< 2 Non maskable Interrupt, cannot be stopped or preempted */
	HardFault_IRQn                = -13,		/*!< 3 Hard Fault, all classes of Fault */
	MemoryManagement_IRQn         = -12,		/*!< 4 Memory Management, MPU mismatch, including Access Violation and No Match */
	BusFault_IRQn                 = -11,		/*!< 5 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
	UsageFault_IRQn               = -10,		/*!< 6 Usage Fault, i.e. Undef Instruction, Illegal State Transition  */
	SVCall_IRQn                   = -5,			/*!< 11 System Service Call via SVC instruction   */
	DebugMonitor_IRQn             = -4,			/*!< 12 CDebug Monitor   */
	PendSV_IRQn                   = -2,			/*!< 14 Pendable request for system service */
	SysTick_IRQn                  = -1,			/*!< 15 System Tick Interrupt */

	/* ---------------------------  LPC17xx Specific Interrupt Numbers  ------------------------------- */
	WDT_IRQn                      = 0,			/*!< Watchdog Timer Interrupt                         */
	TIMER0_IRQn                   = 1,			/*!< Timer0 Interrupt                                 */
	TIMER1_IRQn                   = 2,			/*!< Timer1 Interrupt                                 */
	TIMER2_IRQn                   = 3,			/*!< Timer2 Interrupt                                 */
	TIMER3_IRQn                   = 4,			/*!< Timer3 Interrupt                                 */
	UART0_IRQn                    = 5,			/*!< UART0 Interrupt                                  */
	UART_IRQn                     = UART0_IRQn,	/*!< Alias for UART0 Interrupt                        */
	UART1_IRQn                    = 6,			/*!< UART1 Interrupt                                  */
	UART2_IRQn                    = 7,			/*!< UART2 Interrupt                                  */
	UART3_IRQn                    = 8,			/*!< UART3 Interrupt                                  */
	PWM1_IRQn                     = 9,			/*!< PWM1 Interrupt                                   */
	I2C0_IRQn                     = 10,			/*!< I2C0 Interrupt                                   */
	I2C_IRQn                      = I2C0_IRQn,	/*!< Alias for I2C0 Interrupt                         */
	I2C1_IRQn                     = 11,			/*!< I2C1 Interrupt                                   */
	I2C2_IRQn                     = 12,			/*!< I2C2 Interrupt                                   */
	SPI_IRQn                      = 13,			/*!< SPI Interrupt                                    */
	SSP0_IRQn                     = 14,			/*!< SSP0 Interrupt                                   */
	SSP_IRQn                      = SSP0_IRQn,	/*!< Alias for SSP0 Interrupt                         */
	SSP1_IRQn                     = 15,			/*!< SSP1 Interrupt                                   */
	PLL0_IRQn                     = 16,			/*!< PLL0 Lock (Main PLL) Interrupt                   */
	RTC_IRQn                      = 17,			/*!< Real Time Clock and event recorder Interrupt     */
	EINT0_IRQn                    = 18,			/*!< External Interrupt 0 Interrupt                   */
	EINT1_IRQn                    = 19,			/*!< External Interrupt 1 Interrupt                   */
	EINT2_IRQn                    = 20,			/*!< External Interrupt 2 Interrupt                   */
	EINT3_IRQn                    = 21,			/*!< External Interrupt 3 Interrupt                   */
	ADC_IRQn                      = 22,			/*!< A/D Converter Interrupt                          */
	BOD_IRQn                      = 23,			/*!< Brown-Out Detect Interrupt                       */
	USB_IRQn                      = 24,			/*!< USB Interrupt                                    */
	CAN_IRQn                      = 25,			/*!< CAN Interrupt                                    */
	DMA_IRQn                      = 26,			/*!< General Purpose DMA Interrupt                    */
	I2S_IRQn                      = 27,			/*!< I2S Interrupt                                    */
	ETHERNET_IRQn                 = 28,			/*!< Ethernet Interrupt                               */
	RITIMER_IRQn                  = 29,			/*!< Repetitive Interrupt Interrupt                   */
	MCPWM_IRQn                    = 30,			/*!< Motor Control PWM Interrupt                      */
	QEI_IRQn                      = 31,			/*!< Quadrature Encoder Interface Interrupt           */
	PLL1_IRQn                     = 32,			/*!< PLL1 Lock (USB PLL) Interrupt                    */
	USBActivity_IRQn              = 33,			/*!< USB Activity interrupt                           */
	CANActivity_IRQn              = 34,			/*!< CAN Activity interrupt                           */
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __MPU_PRESENT             1         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          5         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    1         /*!< Set to 1 if different SysTick Config is used     */


#include "core_cm3.h"                       /* Cortex-M3 processor and core peripherals           */
#include "system_LPC17xx.h"                 /* System Header                                      */
#include "Debug.h"

/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/
/** @defgroup PERIPH_175X_6X_BASE CHIP: LPC175x/6x Peripheral addresses and register set declarations
 * @ingroup CHIP_17XX_40XX_Drivers
 * @{
 */

#define LPC_GPIO0_BASE            0x2009C000
#define LPC_GPIO1_BASE            0x2009C020
#define LPC_GPIO2_BASE            0x2009C040
#define LPC_GPIO3_BASE            0x2009C060
#define LPC_GPIO4_BASE            0x2009C080

/* APB0 peripheral */
#define LPC_WWDT_BASE             0x40000000
#define LPC_TIMER0_BASE           0x40004000
#define LPC_TIMER1_BASE           0x40008000
#define LPC_UART0_BASE            0x4000C000
#define LPC_UART1_BASE            0x40010000
#define LPC_PWM1_BASE             0x40018000
#define LPC_I2C0_BASE             0x4001C000
#define LPC_SPI_BASE              0x40020000
#define LPC_RTC_BASE              0x40024000
#define LPC_REGFILE_BASE          0x40024044
#define LPC_GPIOINT_BASE          0x40028080
#define LPC_IOCON_BASE            0x4002C000
#define LPC_SSP1_BASE             0x40030000
#define LPC_ADC_BASE              0x40034000
#define LPC_CANAF_RAM_BASE        0x40038000
#define LPC_CANAF_BASE            0x4003C000
#define LPC_CANCR_BASE            0x40040000
#define LPC_CAN1_BASE             0x40044000
#define LPC_CAN2_BASE             0x40048000
#define LPC_I2C1_BASE             0x4005C000

/* APB1 peripheral */
#define LPC_FMC_BASE              0x40084000
#define LPC_SSP0_BASE             0x40088000
#define LPC_DAC_BASE              0x4008C000
#define LPC_TIMER2_BASE           0x40090000
#define LPC_TIMER3_BASE           0x40094000
#define LPC_UART2_BASE            0x40098000
#define LPC_UART3_BASE            0x4009C000
#define LPC_I2C2_BASE             0x400A0000
#define LPC_I2S_BASE              0x400A8000
#define LPC_RITIMER_BASE          0x400B0000
#define LPC_MCPWM_BASE            0x400B8000
#define LPC_QEI_BASE              0x400BC000
#define LPC_SYSCTL_BASE           0x400FC000
#define LPC_PMU_BASE              0x400FC0C0

/* AHB peripheral */
#define LPC_ENET_BASE             0x50000000
#define LPC_GPDMA_BASE            0x50004000
#define LPC_USB_BASE              0x5000C000

/* Assign LPC_* names to structures mapped to addresses */
#define LPC_PMU                   ((LPC_PMU_T              *) LPC_PMU_BASE)
#define LPC_GPDMA                 ((LPC_GPDMA_T            *) LPC_GPDMA_BASE)
#define LPC_USB                   ((LPC_USB_T              *) LPC_USB_BASE)
#define LPC_ETHERNET              ((LPC_ENET_T             *) LPC_ENET_BASE)
#define LPC_GPIO                  ((LPC_GPIO_T             *) LPC_GPIO0_BASE)
#define LPC_GPIO1                 ((LPC_GPIO_T             *) LPC_GPIO1_BASE)
#define LPC_GPIO2                 ((LPC_GPIO_T             *) LPC_GPIO2_BASE)
#define LPC_GPIO3                 ((LPC_GPIO_T             *) LPC_GPIO3_BASE)
#define LPC_GPIO4                 ((LPC_GPIO_T             *) LPC_GPIO4_BASE)
#define LPC_GPIOINT               ((LPC_GPIOINT_T          *) LPC_GPIOINT_BASE)
#define LPC_RTC                   ((LPC_RTC_T              *) LPC_RTC_BASE)
#define LPC_REGFILE               ((LPC_REGFILE_T          *) LPC_REGFILE_BASE)
#define LPC_WWDT                  ((LPC_WWDT_T             *) LPC_WWDT_BASE)
#define LPC_UART0                 ((LPC_USART_T            *) LPC_UART0_BASE)
#define LPC_UART1                 ((LPC_USART_T            *) LPC_UART1_BASE)
#define LPC_UART2                 ((LPC_USART_T            *) LPC_UART2_BASE)
#define LPC_UART3                 ((LPC_USART_T            *) LPC_UART3_BASE)
#define LPC_SPI                   ((LPC_SPI_T              *) LPC_SPI_BASE)
#define LPC_SSP0                  ((LPC_SSP_T              *) LPC_SSP0_BASE)
#define LPC_SSP1                  ((LPC_SSP_T              *) LPC_SSP1_BASE)
#define LPC_TIMER0                ((LPC_TIMER_T            *) LPC_TIMER0_BASE)
#define LPC_TIMER1                ((LPC_TIMER_T            *) LPC_TIMER1_BASE)
#define LPC_TIMER2                ((LPC_TIMER_T            *) LPC_TIMER2_BASE)
#define LPC_TIMER3                ((LPC_TIMER_T            *) LPC_TIMER3_BASE)
#define LPC_MCPWM                 ((LPC_MCPWM_T            *) LPC_MCPWM_BASE)
#define LPC_I2C0                  ((LPC_I2C_T              *) LPC_I2C0_BASE)
#define LPC_I2C1                  ((LPC_I2C_T              *) LPC_I2C1_BASE)
#define LPC_I2C2                  ((LPC_I2C_T              *) LPC_I2C2_BASE)
#define LPC_I2S                   ((LPC_I2S_T              *) LPC_I2S_BASE)
#define LPC_QEI                   ((LPC_QEI_T              *) LPC_QEI_BASE)
#define LPC_DAC                   ((LPC_DAC_T              *) LPC_DAC_BASE)
#define LPC_ADC                   ((LPC_ADC_T              *) LPC_ADC_BASE)
#define LPC_IOCON                 ((LPC_IOCON_T            *) LPC_IOCON_BASE)
#define LPC_SYSCTL                ((LPC_SYSCTL_T           *) LPC_SYSCTL_BASE)
#define LPC_SYSCON                ((LPC_SYSCTL_T           *) LPC_SYSCTL_BASE) /* Alias for LPC_SYSCTL */
#define LPC_CANAF_RAM             ((LPC_CANAF_RAM_T        *) LPC_CANAF_RAM_BASE)
#define LPC_CANAF                 ((LPC_CANAF_T            *) LPC_CANAF_BASE)
#define LPC_CANCR                 ((LPC_CANCR_T            *) LPC_CANCR_BASE)
#define LPC_CAN1                  ((LPC_CAN_T              *) LPC_CAN1_BASE)
#define LPC_CAN2                  ((LPC_CAN_T              *) LPC_CAN2_BASE)
#define LPC_RITIMER               ((LPC_RITIMER_T          *) LPC_RITIMER_BASE)
#define LPC_FMC                   ((LPC_FMC_T              *) LPC_FMC_BASE)

/* IRQ Handler Alias list */
#define UART_IRQHandler           UART0_IRQHandler
#define I2C_IRQHandler            I2C0_IRQHandler
#define SSP_IRQHandler            SSP0_IRQHandler

/**
 * @}
 */


/***********************************************************************************************************************************
 *** MACROS
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** TIPO DE DATOS PUBLICOS
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* __LPC17xx_H__ */

