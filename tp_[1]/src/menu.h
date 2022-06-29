/*
 * bian.h
 *
 *  Created on: 4 abr. 2022
 *      Author: bianky
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>

/// @brief
///
/// @param km , son los km ingresados por esuario
/// @param precioAerolineas ,precio del valor del pasaje de aerolineas ingresados por el usuario
/// @param precioLatam ,precio del valor del pasaje de latam ingresados por el usuario
/// @param flag1 validacion de que se ingresador los km
/// @param flag2 validacion de que se ingresador el valor de los pasajes
void cartel(int km,float precioAerolineas,float precioLatam,int flag1,int flag2);


/// @brief Muestra el Menu de las formas de pago
///
void calcularCostosMenu();


/// @brief Menu para cargar el valor de los pasajes de aerolineas y latam
///
/// @param opcion la opcion de usuario
/// @param flag1 validacion de que se ingresaron los kms
/// @param precioAerolineas se pasa por puntero el valor de pasaje aerolineas
/// @param precioLatam precioAerolineas se pasa por puntero el valor de pasaje latam
/// @return retorna 1 si salio  bien o 0 si salio algo mal///
int menuIngresoDeVuelos(int opcion, int flag1, float* precioAerolineas, float* precioLatam);


/// @brief muestra cuanto saldria el vuelo con las distintas formas de pago
///
/// @param precioLatam se le pasa el valor del pasaje latam
/// @param latamDebito preico a pagar con debito
/// @param latamCredito precio a pagar con credito
/// @param latamBitcoin precio a pagar con bitcoin
/// @param latamUnitario precio de valor unitario
void mostrarCostosLatam(float precioLatam, float latamDebito, float latamCredito,float latamBitcoin, float latamUnitario );

/// @brief muestra cuanto saldria el vuelo con las distintas formas de pago
///
/// @param precioAerolineas se le pasa el valor del pasaje aerolineas
/// @param aerolineasDebito precio a pagar con debito
/// @param aerolineasCredito precio a pagar con credito
/// @param aerolineasBitcoin precio a pagar con bitcoin
/// @param aerolineasUnitario precio de valor unitario
void mostrarCostosAerolinea(float precioAerolineas, float aerolineaDebito, float aerolinaCredito, float aerolineaBitcoin, float aerolineaUnitario);

/// @brief realiza la carga de forzada de datos que ya estan cargados y solo muestra los resultados de los precios.
///
void cargaForzada();
#endif /* MENU_H_ */
