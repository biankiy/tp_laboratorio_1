#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno;
    char* auxId;
    char* auxNombre;
    char* auxHorasT;
    char* auxSueldo;
    Employee* auxEmployee;


    auxEmployee = Employee_new(); //constructor vacio
    auxId= (char*)malloc(sizeof(char)*10);
    auxNombre= (char*)malloc(sizeof(char)*128);
    auxHorasT= (char*)malloc(sizeof(char)*10);
    auxSueldo= (char*)malloc(sizeof(char)*10);

    retorno= 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasT,auxSueldo); //lectura fantasma
		while(!feof(pFile))
	    {
	    	if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasT,auxSueldo)==4)// cortado en pedacitos
	    	{
	    		auxEmployee= Employee_newParamString(auxId,auxNombre,auxHorasT,auxSueldo);

	    			if(auxEmployee != NULL)
	    			{
						ll_add(pArrayListEmployee, auxEmployee);//validar
						retorno=1;
	    			}
	    	}
	    }
	}
	fclose(pFile);
	return retorno;
}




/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int isOk;
   // int auxId;

    isOk= -1;
	Employee* auxEmployee; //creo un empleado auxiliar que sirva como constructor

	if(pFile != NULL && pArrayListEmployee != NULL)
	{

	    while(!feof(pFile))
	    {
	    	auxEmployee = Employee_new(); //constructor vacio
	    	if(auxEmployee != NULL)//si consiguio espacio para guardar ese empleado
			{
				if(fread(auxEmployee, sizeof(Employee), 1, pFile) == 1)//si devuelve 1 es porque leyo un elemento
				{
					ll_add(pArrayListEmployee, auxEmployee);//agrego
					auxEmployee= NULL;
					isOk = 1;
				}
			}
	    }
	}
    return isOk;
}
