/*
 * menu.c
 *
 *  Created on: 19 jun. 2022
 *      Author: bianky
 */
#include "menu.h"

int menuPrincipal() {
	int opcion;

	printf("\n\n");
	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><>\n");
	printf("<><><>><><><><><><><><><><><>>>>>>>>>>>  ABM PASAJEROS UTN  <<<<<<<<<<<<><><><><><><><><><><><><><><>><\n");
	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><>\n");
	printf("<><><| [ 1  ] <= [ CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO data.csv (modo texto)  ] |><><><>\n");
	printf("<><><| [ 2  ] <= [ CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO data.csv (modo binario)] |><><><>\n");
	printf("<><><| [ 3  ] <= [ ALTA DE PASAJERO                                                          ] |><><><>\n");
	printf("<><><| [ 4  ] <= [ MODIFICAR PASAJERO                                                        ] |><><><>\n");
	printf("<><><| [ 5  ] <= [ BAJA DE PASAJERO                                                          ] |><><><>\n");
	printf("<><><| [ 6  ] <= [ LISTAR PASAJEROS                                                          ] |><><><>\n");
	printf("<><><| [ 7  ] <= [ ORDENAR PASAJEROS                                                         ] |><><><>\n");
	printf("<><><| [ 8  ] <= [ GUARDAR LOS DATOS DE LOS PASAJEROS EN EL ARCHIVO data.csv (modo texto)    ] |><><><>\n");
	printf("<><><| [ 9  ] <= [ GUARDAR LOS DATOS DE LOS PASAJEROS EN EL ARCHIVO data.csv (modo binario)  ] |><><><>\n");
	printf("<><><| [ 10 ] <= [ SALIR                                                                     ] |><><><>\n");
	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");

	printf("Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);

	return opcion;

}
int menuModificacion()
{
	int opcion;
	printf("[ 1 ] <= [ Modificar Nombre] |><><><>\n");
	printf("[ 2 ] <= [ Modificar Apellido] |><><><>\n");
	printf("[ 3 ] <= [ Modificar Precio] |><><><>\n");
	printf("[ 4 ] <= [ Modificar Tipo Pasajero] |><><><>\n");
	printf("[ 5 ] <= [ Modificar Codigo de vuelo] |><><><>\n");
	printf("[ 6 ] <= [ Modificar estado de vuelo] |><><><>\n");
	printf("[ 7 ] <= [ Confirmar Cambios] |><><><>\n");
	printf("[ 8 ] <= [ Salir.\n");

	printf("<><><| Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
int menuOrdenamiento()
{
	int opcion;

	printf("\n\n");
	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><>\n");
	printf("|               -----    M E N U    O R D E N A M I E N T O   -----            |\n");
	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><>\n");
	printf("[ 1 ] <= [ Ordenar por id.\n");
	printf("[ 1 ] <= [ Ordenar por nombre.\n");
	printf("[ 1 ] <= [ Ordenar por pellido.\n");
	printf("[ 1 ] <= [ Ordenar por precio,\n");
	printf("[ 1 ] <= [ Ordenar por tipo de pasajero.\n");
	printf("[ 1 ] <= [ ordenar por codigo de vuelo.\n");
	printf("[ 1 ] <= [ ordenar por estado de vuelo.\n");
	printf("[ 1 ] <= [ Salir.\n");
	printf("Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}

