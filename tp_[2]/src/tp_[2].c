/*
 ============================================================================
 Name        : TP_[02]
 Author      : Bianca Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : abm pasajeros
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"
#include "arrayPassenger.h"
#include "estadoVuelo.h"
#include "utn.h"

#define MAXPASAJEROS 2000
#define ESTADO 5
#define TIPO 3

int main(void) {
	setbuf(stdout,NULL);

	 ePassenger vec[MAXPASAJEROS];
	 int nextId = 1000;
	 char menu ='s';
	 ePassenger aux;
	 int idBuscado;
	 int flag = 0;

	    eStatusFlight estatus[ESTADO]=
	    {
	        {0,"EN ESPERA"},
	        {1,"ARRIVADO"},
	        {2,"DEMORADO"},
	        {3,"REPROGRAMADO"},
	        {4,"CANCELADO"}
	    };
	    eTypePassenger tiposPasajero[TIPO]=
	    {
	        {1,"Economico"},
	        {2,"Ejecutiva"},
	        {3,"Primera Clase"}
	    };

	    initPassengers(vec,MAXPASAJEROS);
	    do
	    {
	        switch(menuPrincipal())
	        {
	        case 1:
	            pedirDatos(&aux,estatus,ESTADO,tiposPasajero,TIPO);
	            if( addPassenger(vec,MAXPASAJEROS,nextId,aux.name,aux.lastName,aux.price,aux.typePassenger,aux.flycode,aux.statusFlight,estatus,ESTADO,tiposPasajero,TIPO) ){

	            	flag = 1;
	                nextId++;
	            }
	            break;
	        case 2:
	            if (flag){
	                modifyPassenger(vec,MAXPASAJEROS,estatus,ESTADO,tiposPasajero,TIPO);
	            }
	            else{
	                printf("<><><| ERROR - No se pueden modificar si no se ingresaron previamente pasajeros |<><><\n");
	            }

	            break;
	        case 3:
	            if(flag){
	                mostrarPasajeros(vec,MAXPASAJEROS,estatus,ESTADO,tiposPasajero,TIPO);
	                pedirId(&idBuscado);
	                removePassenger(vec,MAXPASAJEROS,idBuscado,estatus,ESTADO,tiposPasajero,TIPO);
	            } else{
	                printf("<><><| ERROR - No se puede dar de baja si no se ingresaron previamente pasajeros |<><><\n");
	            }

	            break;
	        case 4:
	            if (flag){
	                informar(vec,MAXPASAJEROS,estatus,ESTADO,tiposPasajero,TIPO);
	            }
	            else{
	                printf("<><><| ERROR -No se puede informar si no se ingresaron previamente pasajeros |<><><\n");
	            }
	            break;
	        case 5:
	            if (altaForzada(vec,MAXPASAJEROS,10,&nextId)){
	                printf("<><><| DATOS CARGADOS EXITOSAMENTE |<><><\n");
	            }
	            flag = 1;
	            break;
	        case 6:
	                menu='n';
	            break;
	        default:
	            printf("<><><| ERROR - Opcion Invalida |<><><");
	        }

	        system("Pause");
	        printf("<><><| PROGRAMA FINALIZADO |<><><|");

	    }while (menu == 's');

	return EXIT_SUCCESS;
}
