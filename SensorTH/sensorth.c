#include "sensorth.h"
#include "MyTypes.h"
#include <stdint.h>


void MaquinaDeEstado (void)
{
	static volatile Type_Estado estado = ESPERAR;
	static volatile uint8_t tiempo_sensor = 0;
	static volatile Type_Tension tension_actual = BAJA;

	static volatile uint8_t tiempo_sensor;
	static volatile uint8_t tiempo_en_baja;
	static volatile uint8_t tiempo_en_alta;
	static volatile uint8_t bit;
	static volatile uint8_t byte;

	getProximoSenso();
	setInicioBaja();
	setInicioAlta();
	setIntentos();
	getTension();
	setTensionAlta();
	setTensionBaja();
	setInicioDato_Baja();
	setInicioDato_Alta();
	AsignarValor();
	CheckSum();

	switch (estado)
	{
		case ESPERAR:
			getProximoSenso();
			if (tiempo_sensor == 0)
			{
				setInicioBaja();
				setIntentos();
				estado = INICIO;
			}
			else
			{
				tiempo_sensor--;
			}
		break;

		case INICIO_MCU_BAJA:
			 tension_actual = getTension();
			 if(tension_actual == BAJA)
			 {
				 if(tiempo_en_baja != 0)
					 tiempo_en_baja--;
				 else
				 {
					 setTensionAlta();
				  	 estado = INICIO_MCU_ALTA;
				 }
			 }
			 else
			 {
				setInicioBaja();
			 }
		break;

		case INICIO_MCU_ALTA:
			tension_actual = getTension();
			 if(tension_actual == ALTA)
			 {
				 if(tiempo_en_alta != 0)
					 tiempo_en_alta--;
				 else
				 {
					 setTensionBaja();
					 estado = INICIO_DHT_BAJA;
				 }
			 }
			 else
			 {
				setInicioAlta();
			 }
		break;

		case INICIO_DHT_BAJA:
			tension_actual = getTension();
			if(tension_actual == BAJA)
			{
				if(tiempo_en_baja != 0)
					tiempo_en_baja--;
				else
				{
					setTensionAlta();
					estado = INICIO_DHT_ALTA;
				}
			}
			else
			{
				setInicioBaja();
			}
		break;

		case INICIO_DHT_ALTA:
			tension_actual = getTension();
			if(tension_actual == ALTA)
			{
				if(tiempo_en_alta != 0)
					tiempo_en_alta--;
				else
				{
					setInicioDato_Baja();
					bit = 0;
					byte = 0;
					estado = DATO_BAJA;
				}
			}
			else
			{
				setInicioAlta();
			}
		break;

		case DATO_BAJA:
			tension_actual = getTension();
			if (tension_actual == BAJA)
			{
				if(tiempo_en_baja != 0)
					tiempo_en_baja--;
				else
					setInicioDato_Alta();
			}
			else
			setInicioDato_Baja();
		break;

		case DATO_ALTA:
			tension_actual = getTension();
			if (tension_actual == ALTA)
				tiempo_en_alta++;
			else
			{
				if(bit < 40)
				{
					if(tiempo_en_alta == TIEMPO0)
					{
						AsignarValor(0);
						bit++;
					}
					else if (tiempo_en_alta > TIEMPO0)
					{
						AsignarValor(1);
						bit++;
					}
				}
				else
					estado = VERIFICACION;
			}
		break;

		case VERIFICACION:
			CheckSum();
			tiempo_sensor = tiempo_DHT;
		break;
	}

}
