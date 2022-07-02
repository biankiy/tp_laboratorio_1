
#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#include "menues.h"


int proximoId_maxArchivoTXT(char* path,LinkedList* pArrayListEmployee,int* maxId)
{
    int retorno;

    char* auxId;
    char* auxNombre;
    char* auxHorasT;
    char* auxSueldo;

    FILE* pFile;
    FILE* pArchivoProxId;

    pFile= fopen("data.csv","r");
    pArchivoProxId= fopen(path,"w");

    *maxId=0;


    Employee* auxEmployee;

    int flag=0;

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
	    				if(flag==0)
						{
							Employee_getId(auxEmployee, maxId); //cargo el primer id
							flag=1;
						}
	    				*maxId+=1;

	    				retorno=1;
	    				free(auxEmployee);
	    			}
	    	}
	    }

		//*maxId+=1;

		fprintf(pArchivoProxId,"%d\n",*maxId);
		fclose(pArchivoProxId);
		fclose(pFile);
	}
	return retorno;
}


int proximoId_CargarMaxIdV2(LinkedList* pArrayListEmployee,int* idMax)
{
    FILE* pFile;
    int retorno;

    retorno=0;

    pFile=fopen("maxId.txt","w");

    if(pArrayListEmployee != NULL)
    {
		proximoId_maxArchivoTXT("maxId.txt", pArrayListEmployee,idMax);
		retorno = 1;
    }

    fprintf(pFile,"%d\n",*idMax);
    fclose(pFile);

    return retorno;
}


int ProximoId_obtener(int* id)
{
	int retorno;

	retorno= 0;
	int newID;

	FILE* pFile;

	pFile = fopen("maxId.txt","r");
	if(pFile!=NULL)
	{
		fscanf(pFile, "%d\n", &newID);
		*id = newID;
		fclose(pFile);
		retorno = 1;
	}
	return retorno;
}


int ProximoId_actualizar(int* id)
{
	int retorno;

	retorno= 0;


	FILE* pFile;
	pFile = fopen("maxId.txt","w"); // abre el texto

	if(pFile!=NULL)
	{
		*id+=1;
		fprintf(pFile,"%d\n",*id);

		fclose(pFile);
		retorno = 1;
	}
	return retorno;
}


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno;

	retorno=0;
	pFile= fopen(path,"r");
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		if(parser_EmployeeFromText(pFile, pArrayListEmployee) != 0)
		{
			printf("Empleados cargados con exito desde %s!!!\n",path);
			retorno=1;
		}
	}
	fclose(pFile);
    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno;

	retorno=0;
	pFile= fopen(path,"rb");
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		if(parser_EmployeeFromBinary(pFile, pArrayListEmployee) != 0)
		{
			printf("Empleados cargados con exito desde %s!!!\n",path);
			retorno=1;
		}
	}
	fclose(pFile);
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayEmployee)
{
	int retorno;
	int proximoId=0;
	Employee* newEmp;

	newEmp = Employee_new();

	if(ll_len(pArrayEmployee)==0)
	{
		proximoId_CargarMaxIdV2(pArrayEmployee, &proximoId);
	}

	ProximoId_obtener(&proximoId);

	if(newEmp != NULL && Employee_Alta(newEmp,proximoId) != -1)
	{
		ll_add(pArrayEmployee, newEmp);
		ProximoId_actualizar(&proximoId);

		retorno= 1;
	}
	else{
		free(newEmp);
		printf("Sistema completo!!!\n");
	}
	return retorno;
}



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int tam;
	int retorno;
	Employee* auxEmpleado;

	retorno=0;
	tam= ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && tam>0)
	{
		printf("----(los elementos pueden demorarse en aparecer)... Cargando ...\n");
		PanelEmpleadosSueldoHoras();
		ll_sort(pArrayListEmployee,Employee_CompareById, 1);
		for(int i=0 ; i<tam ; i++)
		{
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);

			if(auxEmpleado != NULL)
			{
				Mostrar_UnEmpleado(auxEmpleado,0);
			}
		}
		retorno=1;
	}
	return retorno;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int idEmpleadoEdit;
	int index;

	Employee* newEmpEditable;

	retorno=0;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		getInt("Ingrese id del empleado a modificar : \n","Error,Ingrese un id valido!\n",&idEmpleadoEdit,3);

		if( Employee_searchEmployee(pArrayListEmployee, idEmpleadoEdit,&index)==1 )
		{
			newEmpEditable=(Employee*)ll_get(pArrayListEmployee, index);
			if(newEmpEditable != NULL)
			{
				retorno=Employee_edit(newEmpEditable);
			}
		}
	}
	return retorno;

}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int idEmpleadoBaja;
	int index;
	char confirma = 'n';

	Employee* newEmpleadoBaja;

	retorno=0;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		getInt("Ingrese id del empleado a dar de baja : \n","Error,Ingrese un id valido!\n",&idEmpleadoBaja,3);

		if( Employee_searchEmployee(pArrayListEmployee, idEmpleadoBaja,&index)==1 )
		{
			newEmpleadoBaja=(Employee*)ll_get(pArrayListEmployee, index);


			Mostrar_UnEmpleado(newEmpleadoBaja, 1);
			ConfirmaDatos(&confirma, "Confirma la baja del empleado? s/n", 2);
			if(tolower(confirma) == 's')
			{
				ll_remove(pArrayListEmployee, index);
				retorno=1;
			}else{
				retorno=-1;
			}
		}
	}
	return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int criterio;
    int retorno;

    retorno=0;

    if(pArrayListEmployee!=NULL)
    {
        Cartel( "ORDENAR EMPLEADOS");

		PedirNumeroEnteroConRangoPuntero(&criterio,"\nIngrese 0 para ordenar en forma DSC\nIngrese 1 para ordenar en forma ASC", "\nError, Ingrese una opcion valida\n", 0, 1);


		switch(Menu_Sort())
		{
			case 1:
			  Cartel("ORDENAR POR ID");
			  printf("\n\n...Ordenamiento en proceso...\n\n");
			  ll_sort(pArrayListEmployee,Employee_CompareById, criterio);
			  printf("\n\n..El ordenamiento se ha realizado correctamente...\n\n");
			  system("pause");

			  retorno=1;
			  break;

			case 2:
				Cartel("ORDENAR POR NOMBRE");
				printf("\n\n...Ordenamiento en proceso...\n\n");
				ll_sort(pArrayListEmployee, Employee_CompareByName, criterio);
				printf("\n\n..El ordenamiento se ha realizado correctamente...\n\n");
				system("pause");

				retorno=1;
				break;

		   case 3:
			   Cartel("ORDENAR POR CANTIDAD DE HORAS TRABAJADAS");
			   printf("\n\n...Ordenamiento en proceso...\n\n");
			   ll_sort(pArrayListEmployee,Employee_CompareByHoursW, criterio);

			   printf("\n\n..El ordenamiento se ha realizado correctamente...\n\n");
			   system("pause");
			   retorno=1;
				break;

		   case 4:
			   Cartel("ORDENAR POR SUELDO");
			   printf("\n\n...Ordenamiento en proceso...\n\n");
			   ll_sort(pArrayListEmployee,Employee_CompareBySalary,criterio);

			   printf("\n\n..El ordenamiento se ha realizado correctamente...\n\n");
			   system("pause");
			   retorno=1;
				break;

		   default:
				printf("\n<<<<<<<<<<<<<< VOLVIENDO A MENU <<<<<<<<<<<<\n");
				system("pause");
				break;
		}
    }
    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno;

	FILE* pFile;
	Employee* pEmp;

	int len;

	int auxId;
	char auxNombre[128];
	int auxHT;
	float auxSueldo;
	int i;

	char confirma;

	confirma ='n';

	ConfirmaDatos(&confirma,"\n ADVERTENCIA: Se sobreescribira el archivo TXT, confirma ? s / n\n", 3);

	retorno = 0;
	if(confirma == 's')
	{
		//employee_initAll_Fields(&auxId, auxNombre, &auxHT, &auxSueldo);

		if(pArrayListEmployee != NULL && path != NULL)
		{
			len = ll_len(pArrayListEmployee);

			pFile = fopen(path, "w");
			if(pFile != NULL)
			{
				fprintf(pFile,"id,nombre,horas trabajadas,sueldo\n");
				for( i = 0; i < len ; i++)
				{
					pEmp = (Employee*)ll_get(pArrayListEmployee, i);
					if(Employee_getAllFields(pEmp, &auxId, auxNombre, &auxHT, &auxSueldo)==1)
					{
						fprintf(pFile,"%d,%s,%d,%2.f\n",auxId, auxNombre, auxHT, auxSueldo);

					}
				}
			}
			//ll_clear(pArrayListEmployee);
			retorno = 1;
			fclose(pFile);
		}
	}else{
		retorno=-1;
	}
    return retorno;
}



int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* pEmployee;
	int len;
	int i;
	int retorno;
	char confirma='n';

	retorno = 0;
	ConfirmaDatos(&confirma,"\n ADVERTENCIA: Se sobreescribira el archivo BIN, confirma ? s / n\n", 3);

	if(confirma == 's')
	{
		if(pArrayListEmployee != NULL && path != NULL)
		{
			len=ll_len(pArrayListEmployee);

			pFile = fopen(path, "wb");

			if(pFile != NULL)
			{
				for( i = 0; i < len; i++)
				{
					pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
					fwrite(pEmployee, sizeof(Employee), 1, pFile);
				}

			}
			fclose(pFile);
			retorno = 1;
		}

	}else{
		retorno = -1;
	}
    return retorno;
}
