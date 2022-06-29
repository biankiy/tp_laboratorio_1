/*
 * info.h
 *
 *  Created on: 19 jun. 2022
 *      Author: bianky
 */

#include "LinkedList.h"
#include "pasajero.h"
#ifndef MANIPULARPASAJEROS_H_
#define MANIPULARPASAJEROS_H_



#endif /* MANIPULARPASAJEROS_H_ */

int Passenger_SolicitarDatos(char* nombreStr,char* apellido, float* precio, int* tipoPasajero,char* flycode,int* statusFlight);


 int mostrarUnPasajero (LinkedList* pArrayListPassenger);
 int mostrarPasajero(Passenger* passenger);
 int buscarPasajeroPorID(LinkedList* pArrayListPassenger,int idBuscado);
 int bajaPasajero (LinkedList* pArrayListPassenger);
 int AltaPasajero(LinkedList* pArrayListPassenger,int* pLastId);
 int modificarPasajero(LinkedList* pArrayListPassenger);
 int ordenarPasajero(LinkedList* pArrayListPassenger);
