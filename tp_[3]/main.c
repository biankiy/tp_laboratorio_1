#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "pasajero.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);

	char seguir = 's';
	int lastId = 0;
	LinkedList *listaPasajeros = ll_newLinkedList();
	int tam;

	int flagLoad = 0;
	int flagBinGuardado=1;
	int flagDataGuardado=1;

	if(listaPasajeros == NULL)
	{
		printf("||<> No hay memoria suficiente <>||\n");
		EXIT_FAILURE;
	}

	if (!ObtenerUltimoId("ultimoId.bin", &lastId))
	{
		printf("||<> No se pudo conseguir el ultimo Id <>||\n");
		EXIT_FAILURE;
	}

	do {
		tam = ll_len(listaPasajeros);

		switch( menuPrincipal()){

			case 1:
				if (!flagLoad){
					controller_loadFromText("data.csv", listaPasajeros);
					flagLoad = 1;
					flagBinGuardado = 0;
					flagDataGuardado = 0;
				}else{
					printf("||<> ATENCION ,No se permite una segunda carga de archivo, LOS DATOS PODRIAN DUPLICARSE <>||\n");
				}
				break;
			case 2:
				if (!flagLoad){
					controller_loadFromBinary("data.bin" ,listaPasajeros);
					flagLoad= 1;
					flagBinGuardado = 0;
					flagDataGuardado = 0;
				}else{
					printf("||<> ATENCION ,No se permite una segunda carga de archivo, LOS DATOS PODRIAN DUPLICARSE <>||\n");
				}

				break;
			case 3:
				if( controller_addPassenger(listaPasajeros,&lastId)){
					printf("||<> Se Confirmo el Alta <>|| \n");
					flagDataGuardado = 0;
					flagBinGuardado = 0;
				}else{
					printf("||<> NO Se Pudo Realizar el Alta <>||\n");
				}
				break;
			case 4:
				if (tam > 0){

					if ( controller_editPassenger(listaPasajeros)){
						printf("||<> Cambios guardados! <>||\n");
						flagDataGuardado = 0;
						flagBinGuardado = 0;
					}else{
						printf("||<> No se pudieron guardar los cambios <>||\n");
					}
				}else{
					printf("||<> NO hay pasajeros para mostrar <>||\n");
				}
				break;
			case 5:
				if(tam >0){
					if(controller_removePassenger(listaPasajeros)){
						printf("||<> Baja realizada con Exito <>||\n");
						flagDataGuardado = 0;
						flagBinGuardado = 0;
					}else{
						printf("||<> No se pudo realizar la Baja <>||\n");
					}
				}else{
					printf("||<> NO hay pasajeros para mostrar <>||\n");
				}
				break;
			case 6:
				if (!controller_ListPassenger(listaPasajeros)){
					printf("||<> NO hay pasajeros para mostrar <>||\n");
				}
				break;
			case 7:
				if(tam >0){
					if (controller_sortPassenger(listaPasajeros)){
						printf("||<> TODO Ok <>||\n");
					}
					else{
						printf("||<> ERROR, No se pudo realizar el ordenamiento  ||<>\n");
						printf("||<> No hay pasajeros cargados o la lista = NULL ||<>\n");
					}
				}else{
					printf("||<> NO hay pasajeros para mostrar <>||\n");
				}
				break;
			case 8:
				if (tam>0){
					controller_saveAsText("data.csv",listaPasajeros);
					flagDataGuardado = 1;
				}else{
					printf("||<> NO hay pasajeros para guardar <>||\n");
				}

				break;
			case 9:
				if (tam>0){
					controller_saveAsBinary("data.bin",listaPasajeros);
					flagBinGuardado = 1;
				}else{
					printf("||<> NO hay pasajeros para guardar <>||\n");
				}
				break;
			case 10:
				if (flagBinGuardado && flagDataGuardado){
					seguir = 'n';
					ll_deleteLinkedList(listaPasajeros);
					GuardarUltimoId("ultimoId.bin", &lastId);
				}else{
					printf("||<> ATENCION! ATENCION! <>||\n");
					printf("||<>  Para poder salir se debe guardar la informacion en el archivo \"data\" y en el archivo \"bin\"<>||\n");
				}
				break;

				default:
					printf("||<> La opcion Ingresada es INVALIDA <>||\n");
			}

	  system("pause");
	} while (seguir == 's');

	return 0;
}
