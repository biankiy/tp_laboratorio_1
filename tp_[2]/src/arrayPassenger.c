/*
 * arrayPassenger.c
 *
 *  Created on: 8 jun. 2022
 *      Author: bianky
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "arrayPassenger.h"
#include "utn.h"
#include "menu.h"
#include "estadoVuelo.h"
#define INTENTOSINF -1


 static int mostrarUnPasajero (ePassenger pasajero,eStatusFlight estado[],int tamStado,eTypePassenger tiposPasajero[],int cantTipo)
{
    int retorno = -1;
    char estadoAux[20];
    char tipoPasajeroAux[20];

    if (estado != NULL && tamStado > 0){
        altaDescripcionEstado(estado,tamStado,pasajero.statusFlight,estadoAux);
        cargarDescTypePassenger(tiposPasajero,cantTipo,pasajero.typePassenger,tipoPasajeroAux);
        printf("%d    %10s      %10s   %15s     %10.2f     %10s     %15s\n",pasajero.id,pasajero.name,pasajero.lastName,tipoPasajeroAux,pasajero.price,pasajero.flycode,estadoAux);
        retorno = 0;
    }

    return retorno;
}
static int swapPasajero (ePassenger* list, int pos1, int pos2, int len)
{
    int retorno = -1;
    ePassenger aux;
    if (list != NULL && pos1 >= 0 && pos1<len && pos2 >= 0 && pos2 <len){

        aux = list[pos1];
        list[pos1] = list[pos2];
        list[pos2] = aux;
        retorno = 0;
    }
    return retorno;
}

int buscarLibre(ePassenger* list,int len)
{
    int retorno = -1;
    if (list != NULL && len >0){
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}
int initPassengers(ePassenger* list, int len)
{
    int retorno = -1;
    if(list != NULL && len >0)
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty =  1;
        }
        retorno = 0;
    }
    return retorno;
}
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int status,eStatusFlight estados[], int cantEst,eTypePassenger tipos[], int cantTipos)
{
    int retorno = 0;
    int posicionLibre;
    char altaOK;
    char auxTipo[20];
    char auxStatus[20];

    if (list != NULL && len > 0 && id >=0 && name != NULL && lastName != NULL && price > 0 && typePassenger >0 && typePassenger <= 3 && flycode != NULL && status >= 0 && status <= 4)
    {
        posicionLibre=buscarLibre(list,len);
        if ( posicionLibre >= 0 && posicionLibre < len)
        {
            altaDescripcionEstado(estados,cantEst,status,auxStatus);
            cargarDescTypePassenger(tipos,cantTipos,typePassenger,auxTipo);
            printf("ID        NOMBRE         APELLIDO     TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("%d   %10s      %10s   %15s     %10.2f   %10s   %15s\n",id,name,lastName,auxTipo,price,flycode,auxStatus);
            printf("\n\n<><><|Confirma el alta del pasajero? (s/n): ");
            fflush(stdin);
            scanf("%c",&altaOK);
            while (altaOK != 's' && altaOK != 'n'){

                printf("<><><| ERROR: Ingrese [S/N]: ");
                fflush(stdin);
                scanf("%c",&altaOK);
                altaOK = tolower(altaOK);
            }

            if (altaOK == 's'){
                list[posicionLibre].id = id;
                strcpy (list[posicionLibre].name,name);
                strcpy (list[posicionLibre].lastName,lastName);
                list[posicionLibre].price = price;
                strcpy (list[posicionLibre].flycode,flycode);
                list[posicionLibre].typePassenger = typePassenger;
                list[posicionLibre].isEmpty = 0;
                list[posicionLibre].statusFlight=status;
                printf(" -  ALTA REALIZADA CON EXITO - \n");
                retorno = 1;
            }
        }
    }
    return retorno;
}
int mostrarPasajeros(ePassenger* list, int length, eStatusFlight estatus[],int tamStatus,eTypePassenger tiposPasajero[],int cantTipo)
{
    int retorno = 0;

    if (list != NULL && length > 0){

        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("|                              LISTADO          DE          PASAJEROS                                |\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("ID        NOMBRE          APELLIDO    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
        printf("-----------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < length; i++){
            if (list[i].isEmpty == 0){

                mostrarUnPasajero(list[i],estatus,tamStatus,tiposPasajero,cantTipo);
                retorno = 1;
            }
        }
        if(!retorno){
            printf("<><><| No hay pasajeros para mostrar <><><|\n");
        }
    }
    return retorno;
}

int findPassengerById(ePassenger* list, int len,int id)
{
    int retorno = -1;
    if (list != NULL && len >0 && id >= 1000) {
        for (int i = 0; i < len; i++){
            if (list[i].id == id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int removePassenger(ePassenger* list, int len, int id,eStatusFlight estados[],int cantEst,eTypePassenger tiposPasajero[],int cantTipo)
{
    int retorno = 0;
    int indexBuscado;
    char bajaOK;

    if (list != NULL && len > 0 && id >= 0)  {
        indexBuscado = findPassengerById(list,len,id);
        if (indexBuscado == -1) {
            printf("<><><| No se encontro el ID |<><><");
        }
        else {

            printf("\n");
            mostrarUnPasajero(list[indexBuscado],estados,cantEst,tiposPasajero,cantTipo);
            printf("\n");
            printf("Desea confirmar la baja? [s/n]: ");
            fflush(stdin);
            scanf("%c",&bajaOK);
            fflush(stdin);
            bajaOK = tolower(bajaOK);

            while (bajaOK != 's' && bajaOK != 'n'){
				printf("<><><| ERROR = confirma la baja?(s/n): ");
				fflush(stdin);
				scanf("%c",&bajaOK);
				fflush(stdin);
				bajaOK = tolower(bajaOK);
            }
            if (bajaOK == 's'){
                list[indexBuscado].isEmpty = 1;
                printf(" - BAJA CONFIRMADA - \n");
                retorno = 1;
            }else {
                printf(" - BAJA CANCELADA -\n");
            }
        }
    }
    return retorno;
}
int altaForzada(ePassenger* list,int len, int cant, int* pId)
{
    int retorno = 0;
    int posLibre;
    ePassenger aux[10] =
    {

        {0000,"Remera","Leando",121301.2,"oprtg200",3,0,0},
        {0000,"Pantalon","Karen",819221.13,"szxca157",2,3,0},
        {0000,"Bufanda","Patricio",302249.77,"rutyb478",1,2,0},
        {0000,"Guantes","Alexis",32511.2,"nvmbx462",3,1,0},
        {0000,"Medias","Victor",21551,"uytre695",1,0,0},
        {0000,"Buzo","Nicolas",46789.98,"zpslq321",1,4,0},
        {0000,"Zapatilla","Lucila",25369.61,"pocva525",3,1,0},
        {0000,"Camisas","Julian",47102,"oprtu363",2,4,0},
        {0000,"Camperas","Riku",36932.2,"biany789",2,2,0},
        {0000,"Remeron","Luna",22475.2,"gulrr117",1,1,0}

    };

    if (list != NULL && len > 0 && cant >0 && pId != NULL) {

        for (int i = 0 ; i < cant; i++){
            posLibre = buscarLibre(list,len);

            if(list[posLibre].isEmpty == 1) {
                list[posLibre] = aux[i];
                list[posLibre].id = *pId;
                (*pId)++;
            }
        }
        retorno  = 1;
    }
    return retorno;
}
int sortPassengers(ePassenger* list, int tam, int order)
{
    int retorno = -1;
    int ordenados;
    int limite = tam-1;

    //La lista se ordena como 1 ascendente y 0 descendente
    if(list != NULL && tam > 0 && (order == 1 || order == 0)) {
        do{
            ordenados = 1;

            for(int i = 0; i < limite; i ++){
                if((order == 1 && ( (stricmp(list[i].lastName,list[i+1].lastName) > 0)  || (stricmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].typePassenger > list[i+1].typePassenger))) ||

                        (order == 0 && ( (stricmp(list[i].lastName,list[i+1].lastName) < 0)  || (stricmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].typePassenger < list[i+1].typePassenger)))
                   )
                {
                    swapPasajero(list,i,i+1,tam);
                    ordenados = 0;
                }
            }
            limite --;
        }while(ordenados == 0);
        	retorno = 0;
    }
    return retorno;
}
int sortPassengersByCode(ePassenger* list, int len, int order)
{
    int retorno = -1;
    int ordenados;
    int limite = len-1;

    if(list != NULL && len > 0 && (order == 1 || order == 0)){

        do{
        	ordenados = 1;
            for (int i=0; i<limite; i++) {

                if( (order == 1 && ((stricmp(list[i].flycode,list[i+1].flycode) > 0 ) || (stricmp(list[i].flycode,list[i+1].flycode)== 0 && list[i].statusFlight>list[i+1].statusFlight  ))) ||
                        (order == 0 && ((stricmp(list[i].flycode,list[i+1].flycode) < 0 ) || (stricmp(list[i].flycode,list[i+1].flycode)== 0 && list[i].statusFlight<list[i+1].statusFlight  )))
                  )
                {
                    swapPasajero(list,i,i+1,len);
                    ordenados = 0;
                }
            }
            limite --;
        }
        while (ordenados == 0);
        	retorno = 0;
    }
    return retorno;
}
int modifyPassenger(ePassenger* list,int len,eStatusFlight estatus[],int tamStatus,eTypePassenger tiposPasajero[],int cantTipo)
{
    int retorno = 0;
    int idBuscado;
    int indexBuscado;
    char repetir = 's';
    char continuar;
    int flagCambio = 0;

    ePassenger aux;

    if (list!= NULL && estatus != NULL && tiposPasajero != NULL && len >0 && tamStatus >0 && cantTipo >0){
        mostrarPasajeros(list,len,estatus,tamStatus,tiposPasajero,cantTipo);
        pedirId(&idBuscado);
        indexBuscado = findPassengerById(list,len,idBuscado);

        if (indexBuscado >= 0 && indexBuscado < len) {
            aux = list[indexBuscado];

            do {

                printf("----------------------------------------------------------------------------\n");
                printf("<><><|             M  O  D  I  F  I  C  A  C  I  O  N                |<><><\n");
                printf("----------------------------------------------------------------------------\n");
                printf("\n\n");

                printf("ID        NOMBRE          APELLIDO    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                mostrarUnPasajero(aux,estatus,tamStatus,tiposPasajero,cantTipo);
                printf("\n\n");

                switch(menuModificacion()) {

					case 1:
						pedirNombre(aux.name);
						flagCambio = 1;
						break;
					case 2:
						flagCambio = 1;
						pedirApellido(aux.lastName);
						break;
					case 3:
						flagCambio = 1;
						pedirPrecio(&aux.price);
						break;
					case 4:
						flagCambio = 1;
						pedirTypePassenger(&aux.typePassenger,tiposPasajero,cantTipo);
						break;
					case 5:
						flagCambio = 1;
						pedirFlycode(aux.flycode);
						break;
					case 6:
						if(flagCambio){
							list[indexBuscado] = aux;
							printf("- Se ha realizado la modificacion -\n");
							flagCambio = 0;

						}
						else{
							printf("- No se ha realizado ningun cambio -.");
						}

						break;
					case 7:
						if (flagCambio){

							printf("-- ATENCION , si no guardo los cambios se perderan -- ");
							printf("Desea continuar?? [S/N]: ");
							fflush(stdin);
							scanf("%c",&continuar);
							while (continuar !='s' && continuar != 'n'){

								printf("ERROR -Opcion incorrecta: s/n: ");
								fflush(stdin);
								scanf("%c",&continuar);
							}
							if (continuar =='s'){
								repetir = 'n';
							}
						}
						else{
							repetir = 'n';
						}

						break;
					default:
						printf("<><><| ERROR - Opcion incorrecta |<><><");
						break;
					}
                system("pause");
            } while (repetir == 's');
        }
        else
        {
            printf("<><><| NO SE ENCONTRO EL PASAJERO INGRESADO |<><><");
        }
    }
    return retorno;
}
int informar(ePassenger* list, int len,eStatusFlight estatus[],int tamStatus,eTypePassenger tipos[],int tamTipos)
{
    int retorno = -1;
    char continuar = 's';
    float precioTotal;
    float precioProm;
    int flagVueloActivo = 0;
    int flagMayorProm = 0;
    if (list != NULL && len > 0)
    {
        do
        {
            switch(menuInformar())
            {
            case 1:
                sortPassengers(list,len,1);
                mostrarPasajeros(list,len,estatus,tamStatus,tipos,tamTipos);
                break;
            case 2:
                mostrarPasajeros(list,len,estatus,tamStatus,tipos,tamTipos);
                calcularPrecioTotal(list,len,&precioTotal);
                calcularPrecioPromedio(list,len,&precioProm);

                printf("\n\n<><><|Precio total de todos los pasajeros: %.2f\n",precioTotal);
                printf("\n  <><><|Precio promedio de los vuelos: %.2f\n",precioProm);
                printf("\n  <><><|Listado de pasajeros que superan el precio promedio.\n\n\n");
                printf("ID        NOMBRE          APELLIDO    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
                printf("------------------------------------------------------------------------------------------------------\n");

                for (int i = 0; i < len; i++) {
                    if (list[i].isEmpty == 0 && list[i].price>precioProm ){
                        mostrarUnPasajero(list[i],estatus,tamStatus,tipos,tamTipos);
                        flagMayorProm = 1;
                    }

                }
                if (!flagMayorProm){
                    printf("\n\nNingun pasajero supera el precio promedio.\n\n");
                }
                break;
            case 3:
                sortPassengersByCode(list,len,1);
                printf("ID        APELLIDO          NOMBRE    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                for (int i = 0; i < len; i++)
                {
                    if (list[i].isEmpty == 0 && list[i].statusFlight == 1 ){
                        mostrarUnPasajero(list[i],estatus,tamStatus,tipos,tamTipos);
                        flagVueloActivo = 1;
                    }

                }
                if(!flagVueloActivo){
                    printf("<><><| No hay pasajeros en vuelo activo |<><><\n*");
                }
                break;
            case 4:
                continuar = 'n';
                break;
            default:
                printf("<><><| ERROR - Opcion incorrecta |<><><\n");
                break;
            }
            system("pause");

        }while (continuar =='s');

        retorno = 0;
    }
    return retorno;
}

