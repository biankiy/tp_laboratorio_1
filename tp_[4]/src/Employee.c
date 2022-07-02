
#include "LinkedList.h"
#include "Employee.h"
#include "menues.h"


//-------------GETTERS

int Employee_getId(Employee* pEmp,int* newId)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && newId != NULL)// sin limite *newId>1000)
	{
		*newId= pEmp->id;
		retorno=1;
	}
	return retorno;
}

int Employee_getNombre(Employee* pEmp,char* newName)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && newName != NULL)// sin limite *newId>1000)
	{
		strcpy(newName,pEmp->nombre);
		retorno=1;
	}
	return retorno;
}

int Employee_getSueldo(Employee* pEmp,float* newSueldo)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && newSueldo != NULL)// sin limite *newId>1000)
	{
		*newSueldo=pEmp->sueldo;
		retorno=1;
	}
	return retorno;
}

int Employee_getHorasTrabajadas(Employee* pEmp,int* newHorasT)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && newHorasT != NULL && *newHorasT>0)// sin limite *newId>1000)
	{
		*newHorasT= pEmp->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int Employee_getAllFields(Employee* pEmp,int* id,char* name,int* horasT,float* sueldo)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && id != NULL && name != NULL && horasT != NULL && sueldo != NULL)// sin limite *newId>1000)
	{
		if(	Employee_getId(pEmp, id)==1 && Employee_getNombre(pEmp, name)==1 &&
		   Employee_getSueldo(pEmp, sueldo)==1 && Employee_getHorasTrabajadas(pEmp, horasT)==1)
		{
			retorno=1;
		}
	}
	return retorno;
}

//--------------SETTERS -----------------------------------------------

int Employee_setId(Employee* pEmp,int newId)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && newId >0)// sin limite *newId>1000)
	{
		pEmp->id= newId;
		retorno=1;
	}
	return retorno;
}

int Employee_setNombre(Employee* pEmp,char* newName)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && newName != NULL)// sin limite *newId>1000)
	{
		strcpy(pEmp->nombre,newName);
		retorno=1;
	}
	return retorno;
}

int Employee_setSueldo(Employee* pEmp,float newSueldo)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && newSueldo>0)// sin limite *newId>1000)
	{
		pEmp->sueldo=newSueldo;
		retorno=1;
	}
	return retorno;
}

int Employee_setHorasTrabajadas(Employee* pEmp,int newHorasT)
{
	int retorno;

	retorno=0;
	if(pEmp != NULL && newHorasT>0)// sin limite *newId>1000)
	{
		pEmp->horasTrabajadas= newHorasT;
		retorno=1;
	}
	return retorno;
}

int Employee_setAllFields(Employee* pEmp,int id,char* name,int horasT,float sueldo)
{
	int retorno;

	int set_id;
	int set_Nombre;
	int set_HorasT;
	int set_Sueldo;

	retorno=0;
	if(pEmp != NULL && id>0 && name != NULL && sueldo>0 && horasT>0)// sin limite *newId>1000)
	{
		set_id=Employee_setId(pEmp, id);
		set_Nombre=Employee_setNombre(pEmp, name);
		set_HorasT=Employee_setHorasTrabajadas(pEmp, horasT);
		set_Sueldo=Employee_setSueldo(pEmp, sueldo);

		if(	set_id==1 && set_Nombre==1 && set_HorasT==1 && set_Sueldo==1)
		{
			retorno=1;
		}
	}
	return retorno;
}


//----------------CONSTRUCTORES-----------
Employee* Employee_new()
{
	Employee* newEmployee;

	newEmployee= (Employee*) malloc (sizeof(Employee));

	Employee_setAllFields(newEmployee,1," ",1,1);

	return newEmployee;
}

Employee* Employee_newParamString(char* newId,char* newNombre,char* newHorasT,char* newSueldo)
{
	Employee* newEmployee;

	int auxId;
	float auxSueldo;
	int auxHorasT;

	newEmployee= Employee_new();

	if(newEmployee != NULL && newId != NULL && newNombre != NULL && newSueldo!= NULL && newHorasT != NULL)
	{
		auxId= atoi(newId);
		auxHorasT= atoi(newHorasT);
		auxSueldo= atof(newSueldo);

		if(Employee_setAllFields(newEmployee,auxId,newNombre,auxHorasT,auxSueldo)!=1)
		{
			free(newEmployee);
			newEmployee= NULL;
		}
	}
	return newEmployee;
}




//--------------LISTADOS -----------------------------------------------
void Mostrar_UnEmpleado(Employee* auxEmpleado,int criterio)
{
	int auxId;
	char auxNombre[128];
	float auxSueldo;
	int auxHorasT;
	if(criterio ==1)
	{
		PanelEmpleadosSueldoHoras();
	}
	if(Employee_getAllFields(auxEmpleado, &auxId, auxNombre, &auxHorasT,&auxSueldo)==1)
	{
		printf("| %-4d  | %-16s  | %-4d  | $%-8.2f  |\n",auxId,auxNombre,auxHorasT,auxSueldo);
	}
}

void Mostrar_CambiosEmpleados(Employee* pEmp,Employee* pEmp2,int criterio)
{
	int id;
	char nombre[128];
	int hoursW;
	float salary;

	int auxId;
	char auxNombre[128];
	int auxHoursW;
	float auxSalary;

	Employee_getAllFields(pEmp, &id, nombre, &hoursW, &salary);
	Employee_getAllFields(pEmp2, &auxId, auxNombre, &auxHoursW, &auxSalary);
	switch(criterio)
	{
		case 1:
			printf("[%s]--->[%s]\n",nombre,auxNombre);
			break;
		case 2:
			printf("[%d]--->[%d]\n",hoursW,auxHoursW);
			break;
		case 3:
			printf("[$%.2f]--->[$%.2f]\n",salary,auxSalary);
			break;
		default:
			printf("Error, Ingrese un criterio correcto 1: NOMBRE 2: HORAS TRABAJADAS 3: SUELDO\n");
			break;
	}
}



///---------FUNCIONES DE CARGA DE DATOS-------------
int Employee_loadNombre(Employee* pEmp, char* auxName)
{
	int retorno;
	retorno=0;
	if(pEmp != NULL && auxName != NULL)
	{
		if(LoadNombre(auxName)==1)
		{
			Employee_setNombre(pEmp, auxName);
		}

		retorno =1;
	}
	return retorno;
}

int Employee_loadSueldo(Employee* pEmp,float* auxSueldo)
{
	int retorno;

	retorno=0;

	if(pEmp != NULL && auxSueldo != NULL)
	{
		if(LoadSueldo(auxSueldo)==1)
		{
			Employee_setSueldo(pEmp, *auxSueldo);
			retorno=1;
		}
	}
	return retorno;
}

int Employee_loadHorasT(Employee* pEmp,int* auxHorasT)
{
	int retorno;
	retorno=0;
	if(pEmp != NULL && auxHorasT != NULL)
	{
		if(LoadHorasT(auxHorasT)==1)
		{
			Employee_setHorasTrabajadas(pEmp, *auxHorasT);
			retorno =1;
		}
	}
	return retorno;
}
//------------------------------------------------------------------------------
int LoadNombre(char* auxName)
{
	int retorno;
	char auxNamePrueba[128];
	retorno=0;
	if(auxName != NULL)
	{
		getStringSoloLetras("Ingrese NOMBRE del empleado: ","ERROR,Ingrese un nombre valido: ",auxNamePrueba,128,3);
		if(esSoloLetras(auxNamePrueba)==1)
		{
			String_Normalize_MayusMinus(auxNamePrueba);
			strcpy(auxName,auxNamePrueba);

			retorno=1;
		}

	}
	return retorno;
}

int LoadSueldo(float* auxSueldo)
{
	int retorno;
	char auxSueldoStr[256];
	retorno=0;

	if(auxSueldo != NULL)
	{
		*auxSueldo=0;
		getStringNumeroFlotante("Ingrese SUELDO del empleado : \n", "Error,  ingrese un sueldo valido: ", auxSueldoStr, 256, 3);

			*auxSueldo=atof(auxSueldoStr);
			retorno =1;
	}
	return retorno;
}

int LoadHorasT(int* auxHorasT)
{
	int retorno;
	char auxHorasStr[256];
	retorno=0;
	if( auxHorasT != NULL)
	{
		getStringNumeros("Ingrese cantidad de HORAS TRABAJADAS del empleado: ","ERROR,Ingrese una cantidad valida: ", auxHorasStr, 256, 3);
		*auxHorasT= atoi(auxHorasStr);
		retorno =1;
	}
	return retorno;
}

///---------- FUNCIONES PARA COMPARACION DE DATOS---------------------------

int Employee_CompareByName(void* e1, void* e2)
{

	int comp;

	Employee* emp1;
	Employee* emp2;

	emp1 =(Employee*) e1;
	emp2 =(Employee*) e2;

	comp = strcmp(emp1->nombre,emp2->nombre);

	return comp;
}

int Employee_CompareById(void* e1, void* e2)
{
		int retorno;
	    Employee* a=(Employee*) e1;
	    Employee* b=(Employee*) e2;
	    int auxIdA;
	    int auxIdB;

	    Employee_getId(a,&auxIdA);
	    Employee_getId(b,&auxIdB);

	    if(auxIdA>auxIdB)
	    {
	        retorno=1;

	    }else if(auxIdA==auxIdB)
	    {
	        retorno=0;
	    }else
	    {
	        retorno=-1;
	    }
	    return retorno;
	}


int Employee_CompareByHoursW(void* e1, void* e2)
{
	int comp;

	Employee* emp1;
	Employee* emp2;

	int horasT1;
	int horasT2;

	emp1 =(Employee*) e1;
	emp2 =(Employee*) e2;

	if(emp1 != NULL && emp2 != NULL)
	{
		Employee_getHorasTrabajadas(emp1, &horasT1);
		Employee_getHorasTrabajadas(emp2, &horasT2);

			if(horasT1 > horasT2)
			{
				comp=1;
			}else if(horasT1 == horasT2)
			{
				comp=0;
			}else
			{
				comp=-1;
			}
	}
	return comp;
}


int Employee_CompareBySalary(void* e1, void* e2)
{
	int comp;
	float salaryE1;
	float salaryE2;

	Employee* emp1;
	Employee* emp2;

	emp1 =(Employee*) e1;
	emp2 =(Employee*) e2;

	comp=2;

	if(emp1 != NULL && emp2 != NULL)
	{
		Employee_getSueldo(emp1, &salaryE1);
		Employee_getSueldo(emp2, &salaryE2);

		if(salaryE1 > salaryE2)
		{
			comp=1;
		}else if(salaryE1 == salaryE2)
		{
			comp=0;
		}else
		{
			comp=-1;
		}
	}

	return comp;
}



///--------------FUNCIONES AUXILIARES ABM------------------


int loadDataEmployee(int idAuto,Employee* pEmp)
{
	int retorno;

    char auxNombre[128];
    int auxHorasT;
    float auxSueldo;

    retorno=1;
    LoadNombre(auxNombre);
    LoadHorasT(&auxHorasT);
    LoadSueldo(&auxSueldo);

	if( Employee_setAllFields(pEmp, idAuto, auxNombre, auxHorasT, auxSueldo)==0)
    {
		free(pEmp);

		retorno=0;
	}
    return retorno;
}


/***
 * \fn int Employee_searchEmployee(LinkedList*, int, int*)
 * \brief Realiza la busqueda de un empleado en la lista en caso de encontrarlo, indica que existe y devuelve su posicion
 *
 * \param pArrayEmployees: lista de empleados
 * \param idABuscar: el id del empleado a buscar
 * \param posicion: la posicion dentro del array
 * \return 1 si lo encontro, 0 en caso contrario
 */
int Employee_searchEmployee(LinkedList* pArrayEmployees,int idABuscar,int* posicion)
{
	int retorno;
	int len;
	int auxId;

	Employee* auxEmp;

	retorno=0;
	len=ll_len(pArrayEmployees);

	if(pArrayEmployees != NULL && len>0)
	{
		for(int i=0; i<len ; i++)
		{
			auxEmp=(Employee*)ll_get(pArrayEmployees, i);
			if(auxEmp != NULL)
			{
				Employee_getId(auxEmp, &auxId);
				if(auxId== idABuscar)
				{
					*posicion= i;
					retorno=1;
				}
			}else{
				free(auxEmp);
			}
		}
	}
	return retorno;
}

///--------------FUNCIONES PRINCIPALES ABM------------------
//int Employee_Alta(LinkedList* pArrayEmployee,Employee* pEmp,int* proximoId)

int Employee_Alta(Employee* pEmp,int proximoId)
{
    int isOk;

    isOk=-1;

    Cartel("ALTA EMPLEADOS");

    if(pEmp != NULL )
    {
    	if(loadDataEmployee(proximoId,pEmp)==1)
    	{
    		Employee_setId(pEmp, proximoId);

			if(pEmp != NULL)
			{
				Mostrar_UnEmpleado(pEmp, 1);

				isOk= 1;
			}
    	}
    }
    else
    {
        printf("SISTEMA COMPLETO !!!\n\n");
        free(pEmp);
    }
    return isOk;
}





int Employee_edit(Employee* pEmp)
{
	int retorno;

	Employee* auxEmp;
	char confirma;
	char salir='n';

	auxEmp=Employee_new();
	char auxNombre[128];
	int auxHoursW;
	float auxSalary;


	confirma ='n';

	retorno=0; //el empleado no existe

	if(pEmp != NULL)
	{
		do{
			switch(Menu_Edit())
			{
				case 1://nombre
						printf("==== MODIFICAR NOMBRE EMPLEADO ====\n");
						Mostrar_UnEmpleado(pEmp, 1);
						Employee_loadNombre(auxEmp, auxNombre);
						Mostrar_CambiosEmpleados(pEmp,auxEmp,1);

						ConfirmaDatos(&confirma,"Desea confirmar los cambios? s/n", 3);
						if(confirma == 's')
						{
							Employee_setNombre(pEmp, auxNombre);

							printf("\n--Se ha cambiado el nombre con exito!!--\n");
							Mostrar_UnEmpleado(pEmp, 1);
						//	flagCambios=1;
							retorno=1;
						}else
						{
							retorno=-1; ///el usuario cancelo la operacion
						}
				break;

				case 2://horas
						printf("==== MODIFICAR HORAS TRABAJADAS EMPLEADO ====\n");
						Mostrar_UnEmpleado(pEmp, 1);
						Employee_loadHorasT(auxEmp, &auxHoursW);
						Mostrar_CambiosEmpleados(pEmp,auxEmp,2);

						ConfirmaDatos(&confirma,"Desea confirmar los cambios? s/n", 3);
						if(confirma == 's')
						{
							Employee_setHorasTrabajadas(pEmp,auxHoursW);

							printf("\n--Se ha cambiado las horas trabajadas con exito!!--\n");
							Mostrar_UnEmpleado(pEmp, 1);
							retorno=1;
					//		flagCambios=1;
						}else
						{
							retorno=-1; ///el usuario cancelo la operacion
						}
					break;
				case 3://sueldo

					printf("==== MODIFICAR HORAS TRABAJADAS EMPLEADO ====\n");
					Mostrar_UnEmpleado(pEmp, 1);
					Employee_loadSueldo(auxEmp, &auxSalary);
					Mostrar_CambiosEmpleados(pEmp,auxEmp,3);

					ConfirmaDatos(&confirma,"Desea confirmar los cambios? s/n", 3);
					if(confirma == 's')
					{
						Employee_setSueldo(pEmp,auxSalary);

						printf("\n--Se ha cambiado el sueldo con exito!!--\n");
						Mostrar_UnEmpleado(pEmp, 1);
						retorno=1;

					}else
					{
						retorno=-1; ///el usuario cancelo la operacion
					}
					break;

				case 4:
					salir = 's';

					break;

				default:
					printf("--ERROR, Ingrese una opcion valida 1: nombre 2:horas trabajadas 3: sueldo 4: salir--\n");
					break;
			}

		}while(salir != 's');
		free(auxEmp);

	}
	return retorno;
}

