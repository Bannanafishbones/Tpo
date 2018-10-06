#include <stdint.h>
#include <stdbool.h>

typedef enum {ESPERAR = 0, INICIO_MCU_BAJA = 1, INICIO_MCU_ALTA = 2, INICIO_DHT_BAJA = 3, INICIO_DHT_ALTA = 4, DATO_BAJA = 5, DATO_ALTA = 6, VERIFICACION = 7} Type_Estado;
typedef enum {BAJA = 0, ALTA = 1} Type_Tension;

// FALTAN DEFINIR LOS DATOS DE LOS DEFINE
#define TIEMPO0 28;
#define INTENTOS_MAXIMOS 4;
#define TENSION_ALTA 40;
#define TENSION_BAJA 20;
#define TIEMPO_DATO_BAJA 15;
#define _40bits 0xFFFFFFFFFF;


static volatile Type_Estado estado = ESPERAR;
static volatile uint8_t tiempo_sensor = 0;
static volatile Type_Tension tension_actual = BAJA;
static volatile uint8_t intentos;
static volatile uint8_t tiempo_sensor;
static volatile uint8_t tiempo_en_baja;
static volatile uint8_t tiempo_en_alta;
static volatile uint8_t bit;
static volatile uint8_t byte;
static volatile uint64_t temperatura;

uint8_t getProximoSenso();
void setInicioBaja();
void setInicioAlta();
void setIntentos();
Type_Tension getTension();
void setTensionAlta();
void setTensionBaja();
void setInicioDato_Baja();
void setInicioDato_Alta();
void AsignarValor();
bool CheckSum();
void MaquinaDeEstado (void);

