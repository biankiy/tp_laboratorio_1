/*
 * utn.c
 *
 *  Created on: 2 abr. 2022
 *      Author: bianky
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

void pedirNumeroSimple(int* pRestultado, char* mensaje, char* mensajeError,int minimo, int maximo){

	int bufferInt;

	if(pRestultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo){

			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo){
				*pRestultado = bufferInt;
			}else{
				printf("%s",mensajeError);
			}
	}
}

int utn_getNumero(int* pRestultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

	int bufferInt;
	int retorno = -1;

	if(pRestultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){

		do{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo){
				*pRestultado = bufferInt;
				retorno = 0;
				break;

			}else{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}

	return retorno;
}

int utn_getCaracter(char* pRestultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){

	char bufferChar;
	int retorno = -1;

	if(pRestultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){

		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo){
				*pRestultado = bufferChar;
				retorno = 0;
				break;

			}else{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	  }

	return retorno;
}
int utn_pedirfloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	int retorno = -1;
	float bufferFloat;
	int i;

	for(i=0; i<=reintentos; i++){
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}
