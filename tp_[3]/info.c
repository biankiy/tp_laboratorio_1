/*
 * info.c
 *
 *  Created on: 19 jun. 2022
 *      Author: bianky
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "LinkedList.h"
#include "utn.h"
#include "info.h"
#include "menu.h"

#define INFO -1

int Passenger_SolicitarDatos(char* nombres,char* apellido, float* precio, int* tipoPasajero,char* flycode,int* statusFlight)
{
	int retorno = 0;
	char mensajeNombre[]="Ingrese nombre: \n";
	char mensajeApellido[]="Ingrese apellido: \n";
	char mensajePrecio[]="Ingrese Precio desde $1000 \n";
	char mensajeTipoPasajero[]="[1_PrimeraClase]\n[2_Ejecutiva] \n[3_Economico] \nIngrese tipo de pasajero : ";
	char mensajeFlyCode[]="Ingrese codigo de vuelo alfanumerico de 7 digitos: \n";
	char mensajeStatus[]=" [1_CANCELADO]\n [2_ARRIVADO]\n [3_DEMORADO]\n [4_REPROGRMADO]\n Ingrese el estado de vuelo: ";
	char mensajeError[]="ERROR = ";
	if (nombres != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && flycode != NULL)
	{
		printf("\n\n");
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><\n");
		printf("|---                         ---  M E N U   A L T A ---                   ---|\n");
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><\n");

		if( utn_getNombreOApellido(nombres, mensajeNombre, mensajeError, 3, 49, INFO) &&
		utn_getNombreOApellido(apellido, mensajeApellido, mensajeError,2, 49, INFO) &&
		utn_getNumeroFloat(precio, mensajePrecio, mensajeError, 1000, 100000,INFO) &&
		utn_getNumeroInt(tipoPasajero, mensajeTipoPasajero, mensajeError, 1, 3, INFO) &&
		utn_getAlfanumerico(flycode, mensajeFlyCode, mensajeError, 7, 7, INFO)&&
		utn_getNumeroInt(statusFlight, mensajeStatus, mensajeError,1, 4,INFO)){

			retorno = 1;
		}
	}
	return retorno;
}


int mostrarUnPasajero (LinkedList* pArrayListPassenger){

	int retorno = 0;
	int len = ll_len(pArrayListPassenger);

	if (pArrayListPassenger != NULL && len >0){

		printf("ID        NOMBRE        APELLIDO     PRECIO     CODIGO DE VUELO     TIPO DE PASAJERO      ESTADO VUELO\n");
		printf("------------------------------------------------------------------------------------------------------\n");

		for (int i = 0; i < len ; i++){
			mostrarPasajero(ll_get(pArrayListPassenger,i));
			retorno = 1;
		}
	}
	return retorno;
}
int mostrarPasajero(Passenger* passenger){

	int retorno = 0;
	char auxStringTipo[20];
	char auxStringStatus[20];

	if (passenger != NULL){

		Passenger_getTipoStringPasajero(passenger,auxStringTipo);
		Passenger_getStatusStringPasajero(passenger, auxStringStatus);
		printf("%d   %10s    %10s   %10.2f   %15s   %15s   %20s\n",passenger->id,passenger->nombre,passenger->apellido,passenger->precio,passenger->codigoVuelo,auxStringTipo,auxStringStatus);
		retorno = 1;
	}
	return retorno;
}

int buscarPasajeroPorID(LinkedList* pArrayListPassenger,int idBuscado){

	int index=-1;

	if (pArrayListPassenger !=NULL && idBuscado>0){
		Passenger* aux = NULL;

		for (int i = 0; i <ll_len(pArrayListPassenger); i++){

			aux = ll_get(pArrayListPassenger,i);
			if (aux->id == idBuscado){

				index = i;
				break;
			}
		}
	}
	return index;
}
int AltaPasajero(LinkedList* pArrayListPassenger,int* pLastId){

	int retorno = 0;
	char confirmaAlta;

	if(pArrayListPassenger != NULL && pLastId != NULL){

		Passenger* aux = Passenger_new();
		if (aux != NULL){

			if( Passenger_SolicitarDatos(aux->nombre, aux->apellido,&aux->precio,&aux->tipoPasajero,aux->codigoVuelo,&aux->statusFlight))
			{
				mostrarPasajero(aux);
				printf("||<> Confirmar Alta? s/n: ");
				fflush(stdin);
				scanf("%c",&confirmaAlta);
				confirmaAlta = tolower(confirmaAlta);

				while (confirmaAlta!='s' && confirmaAlta!='n'){
					printf("||<> ERROR, Confirmar Alta? [s/n]: ");
					fflush(stdin);
					scanf("%c",&confirmaAlta);
				}
				if(confirmaAlta == 's'){

					(*pLastId)++;
					aux->id = *pLastId;
					ll_add(pArrayListPassenger, aux);
					aux = NULL;
					retorno = 1;
				}
			}
		}
	}
    return retorno;
}

int bajaPasajero (LinkedList* pArrayListPassenger){

	int retorno = 0;
	int idBuscado;
	int indexBuscado;
	char confirmaBaja;
	char MensajeId[]="||<> Ingrese ID: ";
	char MensajeError[]=" ||<> ERROR! = ";

	Passenger* aux = NULL;
	if (pArrayListPassenger != NULL){

		mostrarUnPasajero(pArrayListPassenger);
		utn_getNumeroInt(&idBuscado, MensajeId, MensajeError, 1, 10000,INFO);
		indexBuscado = buscarPasajeroPorID(pArrayListPassenger, idBuscado);
		if(indexBuscado == -1)
		{
			printf("||<> No se encontro el ID ingresado ||<>");
		}else{

				aux = ll_get(pArrayListPassenger,indexBuscado);
				if (aux != NULL){

					mostrarPasajero(aux);
					printf("||<> Confirma Baja? [s/n]: ");
					fflush(stdin);
					scanf("%c",&confirmaBaja);
					confirmaBaja = tolower(confirmaBaja);


					while (confirmaBaja!='s' && confirmaBaja!='n'){
						printf("||<> ERROR = Confirma Baja? [s/n]: ");
						fflush(stdin);
						scanf("%c",&confirmaBaja);
					}
					if(confirmaBaja == 's'){
						retorno = 1;
						ll_remove(pArrayListPassenger, indexBuscado);
					}
				}
		}
	}
	return retorno;
}

int modificarPasajero(LinkedList* pArrayListPassenger){

	int retorno = 0;
	char mensajeId[]= "||<>Ingrese el id que desea buscar , [0 para salir]: ";;
	char mensajeNombre[] ="||<>Ingrese Nombre: ";
	char mensajeApellido[]="||<>Ingrese Apellido: ";
	char mensajePrecio[]="||<>Ingrese Precio entre [1000-100000]:  ";
	char mensajeTipoPasajero[]="||<>[1_FirstClass]\n||<>[2_ExecutiveClass]\n||<>[n3_EconomyClass]\n||<> Ingrese tipo de pasajero : \n";
	char mensajeCodigoVuelo[]="||<>IIngrese  Codigo de Vuelo: ";
	char mensajeStatus[]="||<>[1_Aterrizado]\n||<>[2_En horario]\n||<>[3_En vuelo]\n||<>[4_Demorado]\n ||<> Ingrese el estado de vuelo: ";
	char mensajeError[]="||<>[ Error ]<>||";
	int idBuscado;
	int indexEncontrado;
	char continuar = 's';

	Passenger* auxCambios = Passenger_new(); //Creo pas dinamico donde voy a realizar los cambios
	Passenger* aux = NULL;// puntero para guardar la referencia del indice encontrado.

	if (auxCambios != NULL && pArrayListPassenger != NULL){

		mostrarUnPasajero(pArrayListPassenger); // MUESTRO PASAJEROS
		utn_getNumeroInt(&idBuscado, mensajeId, mensajeError, 0, 10000,INFO); //SOLICITO ID
		if (idBuscado){

			indexEncontrado = buscarPasajeroPorID(pArrayListPassenger, idBuscado);//BUSCO ID
			if(indexEncontrado == -1){

				printf("||<>[No se encontro el Id igresado]<>||\n");
			}
			else{

				aux = ll_get(pArrayListPassenger, indexEncontrado);//guardo la referencia del indice encontrado
				*auxCambios = * aux;//copio el contenido del puntero en el auxiliar donde realizo los cambios
				do{
					//SI ENCUENTRO ID ACCEDO A MENU DE MODIFICACION

					printf("\n\n");
					printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><>><><><><><><><><>\n");
					printf("|----                  ----    M E N U       M O D I F I C A C I O N    ----                  ----|\n");
					printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>\n\n");
					printf("ID        NOMBRE        APELLIDO     PRECIO     CODIGO DE VUELO     TIPO DE PASaAJERO      ESTATUS\n");
					printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><>><><><><><><><><>\n");
					mostrarPasajero(auxCambios); //MUESTRO COPIA DEL PASAJERO ENCONTRADO
					switch(menuModificacion())
					{
					case 1://cambiar nombre
						utn_getNombreOApellido(auxCambios->nombre,mensajeNombre, mensajeError, 3, 49, INFO);
						break;
					case 2://cambiar apellido
						utn_getNombreOApellido(auxCambios->apellido, mensajeApellido, mensajeError, 2, 49,INFO);
						break;
					case 3://cambiar precio
						utn_getNumeroFloat(&auxCambios->precio, mensajePrecio, mensajeError, 1000, 100000, INFO);
						break;
					case 4://cambiar tipo pasajero
						utn_getNumeroInt(&auxCambios->tipoPasajero, mensajeTipoPasajero, mensajeError,1, 3, INFO);
						break;
					case 5://cambiar codigo de vuelo
						utn_getAlfanumerico(auxCambios->codigoVuelo, mensajeCodigoVuelo, mensajeError, 7, 7, INFO);
						break;
					case 6://cambiar estado de vuelo
						utn_getNumeroInt(&auxCambios->statusFlight,mensajeStatus, mensajeError,1, 4,INFO);
						break;
					case 7://confirmar cambios
						*aux = *auxCambios;//COPIO EL CONTENIDO DEL AUXILIAR MODIFIOCADO EN EL PUNTERO DEL INDICE ENCONTRADO
						Passenger_delete(auxCambios);
						auxCambios = NULL;
						retorno = 1;
						break;
					case 8:
						continuar= 'n';
						break;
					default:
						break;
					}

				}while (continuar == 's');
			}
		}


	}
	return retorno;
}




int ordenarPasajero(LinkedList* pArrayListPassenger){

	int retorno = 0;
	int seguir = 1;

	if (pArrayListPassenger != NULL){

		retorno = 1;
		do{

			switch (menuOrdenamiento())
			{
			case 1:
				printf("Se estan Cargando los datos...\n");
				ll_sort(pArrayListPassenger,Passenger_sortId,1);
				break;
			case 2:
				printf("Se estan Cargando los datos...\n");
				ll_sort(pArrayListPassenger,Passenger_sortName,1);
				break;
			case 3:
				printf("Se estan Cargando los datos...\n");
				ll_sort(pArrayListPassenger,Passenger_sortLastName,1);
				break;
			case 4:
				printf("Se estan Cargando los datos...\n");
				ll_sort(pArrayListPassenger,Passenger_sortPrice,1);
				break;
			case 5:
				printf("Se estan Cargando los datos...\n");
				ll_sort(pArrayListPassenger,Passenger_sortTypePassenger,1);
				break;
			case 6:
				printf("Se estan Cargando los datos...\n");
				ll_sort(pArrayListPassenger,Passenger_sortFlycode,1);
				break;
			case 7:
				printf("Se estan Cargando los datos...\n");
				ll_sort(pArrayListPassenger,Passenger_sortStatusFlight,1);
				break;
			case 8:
				seguir = 0;
				break;
			default:
				printf("||<> ERROR, Opcion invalida <>||\n");
				break;
		}
	system("pause");
	}while (seguir == 1);

	}
	return retorno;
}

