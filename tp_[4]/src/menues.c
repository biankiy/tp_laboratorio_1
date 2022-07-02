
#include <stdio.h>
#include <stdlib.h>
#include "menues.h"

#include "utnB.h"


void PanelEmpleadosSueldoHoras()
{
	printf("__________________________________________________\n");
	printf("|  ID   |       NOMBRE      |HORAS T|   SUELDO    |\n");
	printf("|_______|___________________|_______|_____________|\n");
}


void Cartel(char mensaje[])
{

	printf("\n#############################################");
	printf("\n------  %s  --------",mensaje);
	printf("\n##############################################\n");
}

void CartelABM(char mensaje[])
{

	printf("\n####################################################################");
	printf("\n%5s",mensaje);
	printf("\n####################################################################\n");
}

void PanelEmpleados(char mensaje[])
{
    system("cls");
    printf("\n////////////////////////////////////////////////////////////////////////////////\n");
    printf("%s",mensaje);
    printf("\n////////////////////////////////////////////////////////////////////////////////\n");

}


void Menu_OptionABM()
{
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 1- Cargar los empleados desde data.csv (modo TXT)            |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 2- Cargar los empleados desde data.csv (modo BIN)            |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 3- ALTA DE EMPLEADO                                          |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 4- MODIFICAR DATOS DE EMPLEADO                               |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 5- BAJA DE EMPLEADO                                          |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 6- LISTAR EMPLEADOS                                          |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 7- ORDENAR EMPLEADOS                                         |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 8- Guardar los datos de los empleados en data.csv (modo TXT) |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 9- Guardar los datos de los empleados en data.csv (modo BIN) |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n| 10- SALIR                                                    |");
	printf("\n|--------------------------------------------------------------|");
	printf("\n|////////////////////////[Gimenez Karen 1-B]///////////////////|");
}

int Menu_MainABM()
{
    int opcion;
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n|-------------------MENU EMPLEADOS TP4-------------------------|");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    Menu_OptionABM();
    PedirNumeroEnteroConRangoPuntero(&opcion,"Ingrese una opcion del 1 al 10\n","ERROR, reingrese una opcion valida\n",1,10);

    return opcion;
}


void opcionMenuEdit()
{
	 Cartel("MODIFICAR EMPLEADO");
	printf("\n|===================================|");
	printf("\n|<>| 1 - NOMBRE                     |");
	printf("\n|--|--------------------------------|");
	printf("\n|<>| 2 - HORAS TRABAJADAS           |");
	printf("\n|--|--------------------------------|");
	printf("\n|<>| 3 - SALARIO                    |");
	printf("\n|--|--------------------------------|");
	printf("\n|<>| 4 - REGRESAR AL MENU           |\n");
	printf("\n|  |       PRINCIPAL                |");
	printf("\n|===================================|\n");
}


int Menu_Edit()
{
    int opcion;
    opcionMenuEdit();
    PedirNumeroEnteroConRangoPuntero(&opcion,"Ingrese una opcion del 1 al 4","ERROR, reingrese una opcion valida\n",1,4);

    return opcion;
}

void opcionMenuSort()
{
	printf("Elija el criterio de ordenamiento:\n ");
	printf("\n|===================================|");
	printf("\n|<>| 1 - ORDENAR POR ID             |");
	printf("\n|--|--------------------------------|");
	printf("\n|<>| 2 - ORDENAR POR NOMBRE         |");
	printf("\n|--|--------------------------------|");
	printf("\n|<>| 3 - ORDENAR POR HORAS TRAB.    |");
	printf("\n|--|--------------------------------|");
	printf("\n|<>| 4 - ORDENAR POR SUELDO	      |");
	printf("\n|--|--------------------------------|");
	printf("\n|<>| 5 - REGRESAR AL MENU           |\n");
	printf("\n|  |       PRINCIPAL                |");
	printf("\n|===================================|\n");
}
int Menu_Sort()
{
	int opcion;
	opcionMenuSort();
	PedirNumeroEnteroConRangoPuntero(&opcion,"Ingrese una opcion del 1 al 5","ERROR, reingrese una opcion valida\n",1,5);

	return opcion;
}
