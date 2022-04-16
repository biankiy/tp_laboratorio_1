/*
 * calculos.h
 *
 *  Created on: 13 abr. 2022
 *      Author: bianky
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @brief Calcula el valor a pagar con tarjeta de Debito
///
/// @param precioPasaje , el valor del pasaje
/// @return retorno el precio a pagar con debito
float calcularTarjetaDebito(float precioPasaje);

/// @brief Calcula el valor a pagar con tarjeta de Credito
///
/// @param precioPasaje , el valor del pasaje
/// @return retorno el precio a pagar con credito
float calcularTarjeCredito(float precioPasaje);

/// @brief Calcula el valor a pagar con bitcoin
///
/// @param precioPasaje , el valor del pasaje
/// @return retorno el precio a pagar con bitcoin
float calcularBitcoin(float precioPasaje);

/// @brief Calcula el valor a precio Unitario
///
/// @param km , es la cantidad de km ingresados por el usuario
/// @param precioPasaje , el valor del pasaje
/// @return retorno el valor del precio unitario
float calculararUnitario(int km,float precioPasaje);

/// @brief Calcula la diferencia de precios entre aerolineas y latam
///
/// @param precioLatam el valor del precio latam
/// @param precioAerolineas el valor del precio aerolineas
/// @return retorna el valor de la diferencia de precios.
float diferenciaPrecio(float precioLatam, float precioAerolineas);
#endif /* CALCULOS_H_ */
