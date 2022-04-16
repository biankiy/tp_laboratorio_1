/*
 * utn.h
 *
 *  Created on: 2 abr. 2022
 *      Author: bianky
 */

#ifndef UTN_H_
#define UTN_H_

/// @brief
///
/// @param pRestultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
void pedirNumeroSimple(int* pRestultado, char* mensaje, char* mensajeError,int minimo, int maximo);
/// @brief
///
/// @param pRestultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getNumero(int* pRestultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/// @brief
///
/// @param pRestultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_pedirfloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
/// @brief
///
/// @param pRestultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getCaracter(char* pRestultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);










#endif /* UTN_H_ */
