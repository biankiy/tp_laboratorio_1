#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3
#define TAMSEC 5

#define TAMHARDCORE 8

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
    int isEmpty;
}Employee;

typedef struct
{
    int id;
    char name[51];
}Sector;




int menu();

int main()
{
    int proximoId= 999;
    char confirm= 'y';
    char seguir= 'y';
    Employee listOfEmployees[TAM];

     Sector sectores[TAMSEC] =
    {
        {1, "Recursos Humanos"},
        {2, "Administracion"},
        {3, "Sistemas"},
        {4, "Comunicacion"},
        {5, "Contable"}
    };
    initEmployees(listOfEmployees,TAM);
//    hardcodearEmployees(listOfEmployees, TAM);

    proximoId +=  TAMHARDCORE;

    do
    {
        switch(menu())
        {
            case 1:

                     if(altaEmpleado(proximoId, listOfEmployees, TAM,sectores,TAMSEC)==1)
                    {
                        proximoId++;
                    }break;
            case 2:
                     printf("2 - Modificar Empleado\n");

                     modifyEmployee(listOfEmployees, TAM,sectores,TAMSEC);
                    break;
            case 3:
                    removeEmployee(listOfEmployees, TAM, getInt(999,99999, "Ingrese Id Empleado\n","Error,ingrese un ID\n") );

                    break;
            case 4:
                    printf("4 - Informes\n");
                    printEmployees(listOfEmployees, TAM,sectores,TAMSEC);
                    informar(listOfEmployees, TAM,sectores,TAMSEC);

                    break;
            case 5:
                    printf("Desea salir?: y/n \n");
                    fflush(stdin);
                    scanf("%c", &confirm);
                    if(confirm == 'y')
                    {
                        seguir = 'n';
                    }
                    break;

            default:
                    printf("\n\n ERROR ,Ingrese una opcion valida\n\n");
                    break;
        }


       system("pause");


    }while(seguir =='y');


    return 0;
}




char getString(int lenChar,char mensajeAMostrar[] )
{
    char nuevoDato[lenChar];
    printf(mensajeAMostrar);
    fflush(stdin);
   scanf("%s",nuevoDato);
    return nuevoDato;
}



float nuevoSueldo(float rangoA, float rangoB, char mensajeAMostrar[],char mensajeError[])
{
    float newSalary;
    int isOk=0;

    printf(mensajeAMostrar);
    scanf("%f",&newSalary);

    while(newSalary<rangoA || newSalary>rangoB && isOk==0)
    {
        printf(mensajeError);

        scanf("%f",&newSalary);

        if(newSalary>rangoA && newSalary<rangoB)
        {
            isOk=1;
        }

    }


    return newSalary;
}



int getInt(int rangoA, int rangoB, char mensajeAMostrar[],char mensajeError[])
{
    int valorInt;
    int isOk=0;

    printf(mensajeAMostrar);
    scanf("%d",&valorInt);

    while(valorInt<rangoA || valorInt>rangoB && isOk==0)
    {
        printf(mensajeError);

        scanf("%d",&valorInt);

        if(valorInt>rangoA && valorInt<rangoB)
        {
            isOk=1;
        }
    }
    return valorInt;

}



int menu()
{
    int opcion;

    system("cls");

    printf("------------------------------- \n");
    printf("-----  EMPLEADOS MENU ---------\n");
    printf("------------------------------- \n");


    printf("\n1) - Alta Empleado\n");
    printf("2) - Modificar Empleado\n");
    printf("3) - Baja Empleado\n");
    printf("4) - Informes\n");
    printf("5) - Salir\n");

    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    system("cls");

    return opcion;
}
int menuModify()
{
    int opcion;

    system("cls");

    printf("------MODIFICAR EMPLEADO---\n\n");
    printf("1--Modificar Nombre\n");
    printf("2--Modificar Apellido\n");
    printf("3--Modificar Salario\n");
    printf("4--Modificar Sector\n");
    printf("5--Ver modificaciones\n");
    printf("6--Salir--\n");

    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int menuInfo()
{
    int opcion;

    system("cls");
    printf("------------INFORMES----------------*\n\n");
    printf("1--Listado de los empleados ordenados alfabeticamente\n");
    printf("2--Total y promedio de los salarios,\n");
    printf("3--Salir--\n");


    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}


int initEmployees(Employee lista[], int len)
{
    int esArrayVacio;
    esArrayVacio=-1;

    for( int indice=0; indice<len; indice++)
    {
        lista[indice].isEmpty=1;
    }
    esArrayVacio=0;

    return esArrayVacio;
}

int cargarNameSector(char descripcion[], int idSec, Sector sectores[], int len)
{
    int todoOk = 0;

    for(int i=0; i<len; i++)
    {
        if(sectores[i].id == idSec)
        {
            strcpy(descripcion, sectores[i].name);
            todoOk = 1;
        }
    }
    return todoOk;
}

/*void hardcodearEmployees(Employee lista[], int len)
{
    for(int indice; indice<len; indice++)
    {
        lista[indice].id= ids[indice];
        strcpy(lista[indice].name,names[indice]);
        strcpy(lista[indice].lastName,lastNames[indice]);
        lista[indice].salary= salaries[indice];
        lista[indice].idSector=idsSector[indice];
        lista[indice].isEmpty= 0;
    }
}
*/

void mostrarEmpleado (Employee x,Sector sectores[], int tamSec)
{
    char nombreSector[20];
    cargarNameSector(nombreSector, x.idSector, sectores, tamSec);

    printf("%d %10s   %10s  %6.2f     %d    %s  \n", x.id, x.name,x.lastName,x.salary,x.idSector,nombreSector);
}

void printEmployees( Employee vec[], int tam,Sector sectores[], int tamsec)
{
    int flag=0;
    system("cls");
    printf( " ****Listado de Empleados ****\n ");
    printf(" Id      NOMBRE  APELLIDO  SALARIO   ID.SECTOR    SECTOR\n");

    for (int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i],sectores,tamsec);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\n No hay empleados para mostrar\n");

    }
}


int searchFreeLocation(Employee lista[], int len)
{
    int location=-1;
    for(int i=0; i<len ; i++)
    {
        if(lista[i].isEmpty==1)
        {
            location=i;
            break;
        }
    }

    return location;
}




int altaEmpleado(int id, Employee lista[], int len, Sector sectores[], int tamsec)
{
    printf("*****ALTA EMPLEADO*****\n\n");
    int todoOk=0;
    Employee auxEmployee;
    int location= searchFreeLocation(lista,len);

    if(location== -1)
    {
        printf("No hay espacio disponible\n");
    }
    else
    {
        auxEmployee.id= id;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxEmployee.name);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxEmployee.lastName);

        printf("Ingrese salario: ");
        scanf("%f",&auxEmployee.salary);

        printf("Ingrese id sector: ");
        scanf("%d",&auxEmployee.idSector);


        auxEmployee.isEmpty=0;

        printf("\n\n ID      NOMBRE   APELLIDO   SALARIO   ID.SECTOR    SECTOR\n");
        mostrarEmpleado(auxEmployee,sectores,tamsec);

        lista[location]= auxEmployee;

        todoOk=1;
    }
    if(todoOk==1)
    {
        printf("\n El alta se realizo exitosamente\n\n");

    }

    return todoOk;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int existe= -1;
    for(int i=0; i<len; i++ )
    {
        if(list[i].id==id)
        {
            existe=i;
            break;
        }
    }
    if(existe==-1)
    {
        printf("\n El empleado que ingreso no existe\n");
    }
    return existe;
}


void modifyEmployee(Employee list[],int len,Sector sectores[],int tamsec)
{

    int id;
    char confirm;

    char seguir  ='y';


    printf("Ingrese ID empleado:  \n");
    scanf("%d",&id);
    int indice= findEmployeeById(list,len,id);
    if(indice== -1)
    {
        printf("\nNo existe empleado con ese ID");
    }
    else
    {
       do
        {
            switch(menuModify())
            {

            case 1:
                printf("------------------------------\n")
                printf("******Modificar Nombre*******\n");

                printf("\n Desea Modificar  el Nombre?: y/n \n");

                fflush(stdin);
                scanf("%c", &confirm);

                if(confirm == 'y')
                {
                    strcpy(list[indice].name,getString(30,"Ingrese nuevo Nombre\n"));

                    printf("Se ha actualizado el nombre con exito\n\n");

                }
                else
                {
                    printf("Se ha cancelado la operacion\n");
                }
                break;

            case 2:
                printf("----------Modificar Apellido-------------*\n");

                printf("\n Modificar Apellido?: y/n \n");

                fflush(stdin);
                scanf("%c", &confirm);

                if(confirm == 'y')
                {
                    strcpy(list[indice].lastName,getString(30,"Ingrese nuevo Apellido\n"));

                    printf("Se ha actualizado el apellido con exito\n\n");

                }
                else
                {
                    printf("Se ha cancelado la operacion\n");
                }
                break;

            case 3:
                printf("\n Modifica sueldo?: y/n \n");

                fflush(stdin);


                scanf("%c", &confirm);

                if(confirm == 'y')
                {
                    list[indice].salary = nuevoSueldo(0, 999999, "Ingrese nuevo sueldo: \n","Error,reingrese\n");
                    ;
                    printf("Se ha actualizado el sueldo con exito\n\n");

                }
                else
                {
                    printf("Se ha cancelado la operacion\n");
                }
                break;

            case 4:
                printf("\n Modificar SECTOR?: y/n \n");

                fflush(stdin);


                scanf("%c", &confirm);

                if(confirm == 'y')
                {
                    list[indice].idSector = getInt(1,5, "Ingrese nuevo SECTOR: \n","Error,reingrese\n");
                    ;
                    printf("Se ha actualizado el SECTOR con exito\n\n");

                }
                else
                {
                    printf("Se ha cancelado la operacion\n");
                }
                break;

            case 5:
                mostrarEmpleado(list[indice],sectores,tamsec);
                fflush(stdin);
                break;

            case 6:

                printf("Desea salir?: y/n \n");
                fflush(stdin);

                scanf("%c", &confirm);
                if(confirm == 'y')
                {
                    seguir = 'n';
                }

            }
            system("pause");

        }
        while(seguir=='y');



    }
}

void removeEmployee(Employee list[],int len, int id,Sector sectores[],int tamsec)
{
    char confirm;
    int indice= findEmployeeById(list,len,id);

    printf("----------REMOVER EMPLEADOS----------- \n\n");

    if( indice ==-1)
    {
        printf("No existe un empleado con id: %d\n", id);
    }
    else
    {
        printf(" Id      Names   lastNames   Salaries   idSector\n");
        mostrarEmpleado(list[indice],sectores,tamsec);

        printf("desea remover el empleado?: y/n \n");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm== 'y')
        {
            list[indice].isEmpty=1;
            printf("\nSe ha removido al empleado con id:%d con exito\n", id);
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}
float sumaSalarios(Employee lista[],int len)
{
    float acumulador=0;
    if(len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty==0)
            {
                acumulador+=lista[i].salary;
            }
        }
    }
    return acumulador;
}

float promedio(Employee lista[],int len)
{
    float acumulador=0;
    int contador=0;
    float promedio;
    int flag=0;
    if(len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty==0)
            {
                acumulador+=(float)lista[i].salary;
                contador++;
                flag=1;
            }
        }
        promedio=(float)acumulador/contador;
        if(flag==0)
        {
            promedio=0;
        }
    }

    return promedio;
}

int cantidadDeEmpleadosSalarioMayorDelPromedio(Employee lista[],int len,float promedio)
{
    int cantidadEmpleados=0;
    if(len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty==0&&lista[i].salary>=promedio)
            {
                cantidadEmpleados++;
            }
        }
    }
    return cantidadEmpleados;
}
void sortEmployees(Employee list[],int tam,int order)
{
    Employee auxEmpleado;
    int valOrder=0;
    if(tam>0&&(order==1||order==0))
    {
        if(order==1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(list[i].idSector>list[j].idSector)
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                        valOrder=1;
                    }
                    else
                    {
                        if(list[i].idSector==list[j].idSector&&strcmp(list[i].lastName,list[j].lastName)>0)
                        {
                            auxEmpleado=list[i];
                            list[i]=list[j];
                            list[j]=auxEmpleado;
                            valOrder=1;
                        }
                    }
                }
            }
        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(list[i].idSector<list[j].idSector)
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                        valOrder=1;
                    }
                    else
                    {

                        if(list[i].idSector==list[j].idSector&&strcmp(list[i].lastName,list[j].lastName)<0)
                        {
                            auxEmpleado=list[i];
                            list[i]=list[j];
                            list[j]=auxEmpleado;
                            valOrder=1;
                        }
                    }
                }
            }
        }

    }
}

void informar(Employee lista[],int len,Sector sectores[],int tamsec)
{
    int opcionInformes;
    char confirm ='s';
    char seguir ='s';

    int order;
    float promedioSalarios;
    float acumuladorSalarios;
    int cantidadEmpleadosSuperanPromedio;


    do
    {
        opcionInformes=menuInfo();
        switch(opcionInformes)
        {
        case 1:
            system("cls");
            printf("\n -------------EMPLEADOS------------");
            printf("\n Ingrese la forma en que desea ordenarlo ");
            printf("\n 1--- ORDEN ASCENDENTE ");
            printf("\n 2--- ORDEN DESCENDENTE \n");
            scanf("%d", &order);
            sortEmployees(lista,len,order);
            system("cls");
			printEmployees(lista,len,sectores,tamsec);
            break;

        case 2:
            acumuladorSalarios=sumaSalarios(lista,len);

            promedioSalarios=promedio(lista,len);
            cantidadEmpleadosSuperanPromedio=cantidadDeEmpleadosSalarioMayorDelPromedio(lista,len,promedioSalarios);
            system("cls");

             printf("\n --------TOTAL A PAGAR ---------\n\n");
             printf("Sueldo totales a pagar: $%.2f\n",acumuladorSalarios);
             printf("Salario promedio de los empleados: $%.2f\n",promedioSalarios);
             printf("Cantidad de empleados que superan o igualan el promedio: %d\n",cantidadEmpleadosSuperanPromedio);

            break;

        case 3:
            printf("Desea salir?: y/n \n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 'y')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("Ingrese una opcion valida \n\n");
        }
        system("pause");
    }
    while(seguir=='s');
}

