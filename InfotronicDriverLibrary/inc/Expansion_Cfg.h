/*******************************************************************************************************************************//**
 *
 * @file		Expansion_Cfg.h
 * @brief		Archivo de configuración. Inidca que placa de expansión esta instalada en el BaseBooard (Infotronic)
 * @date		30/05/2016
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef EXPANSION_CFG_H_
#define EXPANSION_CFG_H_


/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/
/* La placa base Infotronic esta preparada para trabajar actualmente con 4 placas de expansión distintas. Este modulo
 * permite indicar que placa de expansion esta siendo utilizada. Mediante este mecanismo se pueden automatizar algunas
 * configuraciones.
 * IMPORTANTE: Si no tiene ninguna placa de expansión conectada, deje todos los defines comentados.
 *             Si tiene alguna placa de expansion conectada, solo deje descomentado el define correspondiente.
 */
//#define EXPANSION_1_INSTALLED		/* Decomente el define si conecta la Expansion 1, de lo contrario dejelo comentado */
#define EXPANSION_2_INSTALLED		/* Decomente el define si conecta la Expansion 2, de lo contrario dejelo comentado */
//#define EXPANSION_3_INSTALLED		/* Decomente el define si conecta la Expansion 3, de lo contrario dejelo comentado */
//#define EXPANSION_4_INSTALLED		/* Decomente el define si conecta la Expansion 4, de lo contrario dejelo comentado */

/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* EXPANSION_CFG_H_ */


