/*
 * estadoVuelo.c
 *
 *  Created on: 8 jun. 2022
 *      Author: bianky
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estadoVuelo.h"

int listarEstado(eStatusFlight estados[],int cantEst){

    int retorno = -1;

    if (estados != NULL && cantEst > 0){
    	printf("<><><><><><><><><><><><><><><><>\n");
        printf("<><><|  ESTADO DE VUELO  |<><><|\n\n");
        printf("<><><| CODIGO      ESTADO <><><|\n");
        printf("<><><><><><><><><><><><><><><><>\n");

        for (int i = 0; i < cantEst; i++ ) {
            printf("%d         %s\n",estados[i].idStatus,estados[i].desc);
        }
        retorno = 0;
    }
    return retorno;
}
int altaDescripcionEstado(eStatusFlight estados[],int cantEst,int idEst,char descripccion[]){

    int retorno = -1;
    if (estados!= NULL && cantEst > 0 && idEst >= 0 && idEst <=4 && descripccion != NULL){
        for (int i = 0; i < cantEst; i++) {
        	if (estados[i].idStatus == idEst){

                strcpy(descripccion,estados[i].desc);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

//------------------------------------------------------
int listarTipoPasajero(eTypePassenger tipos[],int cantTipos){

    int retorno = -1;
    if (tipos != NULL && cantTipos > 0)
    {
    	printf("<><><><><><><><><><><><><><><><>\n");
        printf("<><><| Tipo de pasajero |<><><\n\n");
        printf("CODIGO      ESTADO\n");
        printf("<><><><><><><><><><><><><><><><>\n");

        for (int i = 0; i < cantTipos; i++ ){
            printf("%d         %s\n",tipos[i].idTypePassenger,tipos[i].desc);
        }

        retorno = 0;
    }
    return retorno;

}
int cargarDescTypePassenger(eTypePassenger tipos[],int tamTipos, int idTipo, char vec[]){

    int retorno = -1;

    if (tipos != NULL && tamTipos > 0 && idTipo >0 && vec != NULL){
        for (int i = 0; i < tamTipos; i++){

            if (tipos[i].idTypePassenger == idTipo){

                strcpy(vec,tipos[i].desc);
                retorno = 0;
                break;
            }
        }

    }
    return retorno;
}
