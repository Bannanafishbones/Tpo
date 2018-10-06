#include "sensorth.h"
#include "MyTypes.h"


void MaquinaDeEstado (void)
{

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

uint8_t getProximoSenso(void)
{

}

void setInicioBaja(void)
{
	tiempo_en_baja = TIEMPO_INICIO_BAJA;
}

void setInicioAlta(void)
{
	tiempo_en_alta = TIEMPO_INICIO_ALTA;
}

void setIntentos()
{
	intentos = INTENTOS_MAXIMOS;
}

Type_Tension getTension()
{

}

void setTensionAlta()
{
	tiempo_en_alta = TENSION_ALTA;
}

void setTensionBaja()
{
	tiempo_en_baja = TENSION_BAJA;
}

void setInicioDato_Baja()
{
	tiempo_en_baja = TIEMPO_DATO_BAJA;
}

void setInicioDato_Alta()
{
	tiempo_en_alta = 0;
}

void AsignarValor(uint8_t valor)
{
	char valor1 = ~(1 << bit);
	char valor2 = (0xF & valor1);


	if(valor)
		temperatura |= (valor << bit);
	else
		temperatura &= _40bits &~(1 << bit);
		//temperatura &= (1 << bit);
}

bool CheckSum()
{

}
