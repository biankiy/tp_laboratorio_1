/*
 * menu.c
 *
 *  Created on: 8 jun. 2022
 *      Author: bianky
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "arrayPassenger.h"
#include "menu.h"

int menuPrincipal (){

    int respuesta;
		printf("\n\n");
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("<><><>>>>>>>>>>>  ABM PASAJEROS UTN  <<<<<<<<<<<<><><><><<><><><><><><\n");
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><>\n");
		printf("<><><| [ 1 ] <= [ ALTA DE PASAJEROS      ] |><><><>\n");
		printf("<><><| [ 2 ] <= [ MODIFICAR PASAJERO     ] |><><><>\n");
		printf("<><><| [ 3 ] <= [ BAJA DE PASAJERO       ] |><><><>\n");
		printf("<><><| [ 4 ] <= [ INFORMAR               ] |><><><>\n");
		printf("<><><| [ 5 ] <= [ CARGA FORZADA          ] |><><><>\n");
		printf("<><><| [ 6 ] <= [ SALIR                  ] |><><><>\n");
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");

    printf("Ingrese una opcion: ");
    scanf("%d",&respuesta);

    return respuesta;
}

int menuModificacion (){

		int respuesta;

		printf("<><><| [ 1 ] <= [ NOMBRE            ] |><><><>\n");
		printf("<><><| [ 2 ] <= [ APELLIDO          ] |><><><>\n");
		printf("<><><| [ 3 ] <= [ PRECIO            ] |><><><>\n");
		printf("<><><| [ 4 ] <= [ TIPO DE PASAJERO  ] |><><><>\n");
		printf("<><><| [ 5 ] <= [ CODIGO DE VUELO   ] |><><><>\n");
		printf("<><><| [ 6 ] <= [ CONFIRMAR CAMBIOS ] |><><><>\n");
		printf("<><><| [ 7 ] <= [ SALIR             ] |><><><>\n");
        printf("\n<><><| Que desea modificar?: ");
        fflush(stdin);
        scanf("%d",&respuesta);
        return respuesta;
}
int menuInformar ()
{
    int respuesta;

    printf("<><><| [ 1 ] <= [ Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
    printf("<><><| [ 2 ] <= [ Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. \n");
    printf("<><><| [ 3 ] <= [ Listado de los pasajeros por Codigo de vuelo y estados de vuelos ACTIVO (1)\n");
    printf("<><><| [ 4 ] <= [ Salir.\n");
    printf("Ingrese una opcion: ");

		fflush(stdin);
		scanf("%d",&respuesta);
    return respuesta;
}
