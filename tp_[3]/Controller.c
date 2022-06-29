#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "pasajero.h"
#include "info.h"
#include "utn.h"
#include "parser.h"
#include "menu.h"



int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int cantidadAlta= 0;

	FILE* f = NULL;

	if(path != NULL && pArrayListPassenger != NULL){
		f = fopen(path,"r");
		if (f != NULL){
			cantidadAlta = parser_PassengerFromText(f, pArrayListPassenger);
			if(cantidadAlta){

				printf("<><><| Los pasajeros se cargaron Correctamente = %d. |<><><\n",cantidadAlta);
				retorno = 1;
			}
		}
		fclose(f);
	}

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int cantidadAlta = 0;

		FILE* f = NULL;
		if (path != NULL && pArrayListPassenger != NULL){
			f = fopen(path,"rb");
			if (f != NULL){
				cantidadAlta = parser_PassengerFromBinary(f, pArrayListPassenger);
				if (cantidadAlta){

					printf("<><><| Los pasajeros se cargaron Correctamente = %d. |<><><\n",cantidadAlta);
					retorno = 1;
				}
			}
			fclose(f);
		}

	    return retorno;

}

int controller_addPassenger(LinkedList* pArrayListPassenger,int* pId){

	int retorno = 0;

	if (pArrayListPassenger != NULL && pId != NULL){

		if( AltaPasajero(pArrayListPassenger, pId)){
			retorno = 1;
		}
	}
	return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger){

    int retorno = 0;

    if(modificarPasajero(pArrayListPassenger)){
    	retorno = 1;
    }
    return retorno;
}


int controller_removePassenger(LinkedList* pArrayListPassenger){

	int retorno = 0;

	if (pArrayListPassenger != NULL){

		if (bajaPasajero(pArrayListPassenger)){
			retorno = 1;
		}
	}
	return retorno;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger){

	int retorno = 0;

	if (pArrayListPassenger != NULL && ll_len(pArrayListPassenger)>0){
		if (mostrarUnPasajero(pArrayListPassenger)){
			retorno = 1;
		}
	}
    return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger){

	int retorno = 0;
	if (pArrayListPassenger != NULL && ll_len(pArrayListPassenger)>0){
		if (ordenarPasajero(pArrayListPassenger)){
			retorno = 1;
		}
	}
	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){

	int retorno = 0;
	int cantidadGuardados = 0;

	if(path != NULL && pArrayListPassenger != NULL){

		FILE* f = fopen(path,"w");
		if (f != NULL){
			cantidadGuardados = parser_TextFromPassenger(f, pArrayListPassenger);
			if (cantidadGuardados){
				printf("<><><| Los pasajeros se cargaron Correctamente = %d. |<><><\n",cantidadGuardados);
				retorno = 1;
			}
		}
		fclose(f);
	}
	return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){

	int retorno = 0;
	int cantidadGuardados = 0;

	if(path != NULL && pArrayListPassenger != NULL){

		FILE* f = fopen(path,"wb");
		if (f != NULL){

			cantidadGuardados = parser_binaryFromPassenger(f, pArrayListPassenger);
			if (cantidadGuardados){

				printf("<><><| Los pasajeros se guardaron Correctamente = %d. |<><><\n",cantidadGuardados);
				retorno = 1;
			}

		}
		fclose(f);
	}
	return retorno;
}

