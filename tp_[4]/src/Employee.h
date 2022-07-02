#include "utnB.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;


/*-----GETTERS------*/
/***
 * \fn int Employee_getId(Employee*, int*)
 * \brief Obtiene el campo id del puntero a empleado pasado por parametro
 *
 * \param this
 * \param id
 * \return 1 en caso de poder obtenerlo, 0 en caso de error
 */
int Employee_getId(Employee* this,int* id);

/***
 * \fn int Employee_getHorasTrabajadas(Employee*, int*)
 * \brief Obtiene el campo horasTrabajadas del puntero a empleado pasado por parametro
 *
 * \param this
 * \param id
 * \return 1 en caso de poder obtenerlo, 0 en caso de error
 */
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/***
 * \fn int Employee_getNombre(Employee*, char*)
 * \brief Obtiene el campo nombre del puntero a empleado pasado por parametro
 *
 * \param this
 * \param id
 * \return 1 en caso de poder obtenerlo, 0 en caso de error
 */
int Employee_getNombre(Employee* this,char* nombre);

/***
 * \fn int Employee_getSueldo(Employee*, float*)
 * \brief Obtiene el campo sueldo del puntero a empleado pasado por parametro
 *
 * \param this
 * \param id
 * \return 1 en caso de poder obtenerlo, 0 en caso de error
 */
int Employee_getSueldo(Employee* this,float* sueldo);

/***
 * \fn int Employee_getAllFields(Employee*, int*, char*, int*, float*)
 * \brief Obtiene todos los campos del puntero empleado pasado por parametro y los carga en las variables pasadas por parametro
 *
 * \param pEmp
 * \param id
 * \param name
 * \param horasT
 * \param sueldo
 * \return 1 en caso de poder obtenerlo, 0 en caso de error
 */
int Employee_getAllFields(Employee* pEmp,int* id,char* name,int* horasT,float* sueldo);

/*-----SETTERS------*/

/****
 * \fn int Employee_setId(Employee*, int)
 * \brief Asigna el id pasado por parametro en el campo id del puntero a empleado pasado por parametro
 *
 * \param this
 * \param id
 * \return 1 en caso de poder asignarlo, 0 en caso de error
 */
int Employee_setId(Employee* this,int id);

/***
 * \fn int Employee_setNombre(Employee*, char*)
 * \brief Asigna el nombre pasado por parametro en el campo nombre del puntero a empleado pasado por parametro
 *
 * \param this
 * \param nombre
 * \return 1 en caso de poder asignarlo, 0 en caso de error
 */
int Employee_setNombre(Employee* this,char* nombre);


/***
 * \fn int Employee_setSueldo(Employee*, float)
 * \brief Asigna el sueldo pasado por parametro en el campo sueldo del puntero a empleado pasado por parametro
 *
 * \param this
 * \param sueldo
 * \return 1 en caso de poder asignarlo, 0 en caso de error
 */
int Employee_setSueldo(Employee* this,float sueldo);


/***
 * \fn int Employee_setHorasTrabajadas(Employee*, int)
 * \brief Asigna el id pasado por parametro en el campo id del puntero a empleado pasado por parametro
 *
 * \param this
 * \param id
 * \return 1 en caso de poder obtenerlo, 0 en caso de error
 */
int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/***
 * \fn Employee_setAllFields(Employee* pEmp,int id,char* name,int horasT,float sueldo);
 * \brief Realiza la carga de los datos pasados por parametro a una estructura empleado existente
 *
 * \param newEmp: Puntero a Empleado (Employee*)
 * \param newId:  Nuevo Id empleado (int)
 * \param newNombre: Nuevo Nombre empleado (char*)
 * \param newSueldo: Nuevo sueldo empleado (float)
 * \param newHorasT: Nuevo horas de trabajo empleado (int)
 * \return 1 si pudo realizar la carga exitosamente,0 en caso contrario.
 */
int Employee_setAllFields(Employee* pEmp,int id,char* name,int horasT,float sueldo);


///------------------------------------FUNCIONES DE COMPARACION DE DATOS-------------------------------------------


/****
 * \fn int Employee_CompareByName(void*, void*)
 * \brief Realiza la comparacion entre los nombres de dos empleados pasados por parametro
 *
 * \param e1
 * \param e2
 * \return devuelve 0 /1/-1 segun el resultado de la comparacion
 */
int Employee_CompareByName(void* e1, void* e2);

/***
 * \fn int Employee_CompareById(void*, void*)
 * \brief Realiza la comparacion entre los ids de dos empleados pasados por parametro
 *
 * \param e1
 * \param e2
 * \return si el id (e1) >(e2) retorna -1
			   	id (e1) ==(e2) retorna 0
				id (e1) <(e2) retorna 1
 */
int Employee_CompareById(void* e1, void* e2);


/****
 * \fn int Employee_CompareByHoursW(void*, void*)
 * \brief Realiza la comparacion entre los campos HorasTrabajadas dos empleados pasados por parametro
 *
 * \param e1
 * \param e2
 * \return si el id (e1) >(e2) retorna 1
			   	id (e1) ==(e2) retorna 0
				id (e1) <(e2) retorna -1
 */
int Employee_CompareByHoursW(void* e1, void* e2);


/****
 * \fn int Employee_CompareBySalary(void*, void*)
 * \brief Realiza la comparacion entre los campos sueldos de dos empleados pasados por parametro
 *
 * \param e1
 * \param e2
 * \return si el id (e1) >(e2) retorna 1
			   	id (e1) ==(e2) retorna 0
				id (e1) <(e2) retorna -1
 */
int Employee_CompareBySalary(void* e1, void* e2);


///------------------------------------FUNCIONES DE CARGA DE DATOS-------------------------------------------

/****
 * \fn int LoadNombre(char*)
 * \brief Realiza la carga y validacion de un nombre y la devuelve por referencia
 *
 * \param auxName
 * \return 1 en caso de exito , 0 en caso contrario
 */
int LoadNombre(char* auxName);

/***
 * \fn int LoadSueldo(float*)
 * \brief Realiza la carga y validacion de un sueldo y lo devuelve por referencia
 *
 * \param auxSueldo
 * \return 1 en caso de exito , 0 en caso contrario
 */
int LoadSueldo(float* auxSueldo);

/***
 * \fn int LoadHorasT(int*)
 * \brief Realiza la carga y validacion de las horasTrabajadas del empleado y lo devuelve por referencia
 *
 * \param auxHorasT
 * \return 1 en caso de exito , 0 en caso contrario
 */
int LoadHorasT(int* auxHorasT);

//-----Carga pEmpleado-------------------------------------

/***
 * \fn int Employee_loadNombre(Employee*, char*)
 * \brief
 *
 * \param pEmp
 * \param auxName
 * \return
 */
int Employee_loadNombre(Employee* pEmp, char* auxName);

/***
 * \fn int Employee_loadSueldo(Employee*, float*)
 * \brief
 *
 * \param pEmp
 * \param auxSueldo
 * \return
 */
int Employee_loadSueldo(Employee* pEmp,float* auxSueldo);


/***
 * \fn int Employee_loadHorasT(Employee*, int*)
 * \brief
 *
 * \param pEmp
 * \param auxHorasT
 * \return
 */
int Employee_loadHorasT(Employee* pEmp,int* auxHorasT);


/***
 * \fn int loadDataEmployee(int, Employee*)
 * \brief Realiza la carga de todos los campos al empleado pasado por parametro, ademas actualiza su id de manera autoincremental.
 *
 * \param idAuto: id Autoincremental
 * \param pEmp; El puntero a empleado
 * \return 1 en caso de exito/ 0 en caso de error
 */
int loadDataEmployee(int idAuto,Employee* pEmp);



/*----------------CONSTRUCTORES----------------------*/

/***
 * \fn Employee Employee_new*()
 * \brief Reserva espacio de memoria para un empleado de manera dinamica e inicializa con valores por defecto
 * \return 1 en caso de hallar espacio , 0 en caso contrario
 */
Employee* Employee_new();



/***
 * \fn int Employee_newParam(Employee*, int, char*, int, int)
 * \brief Realiza la carga de los datos pasados por parametro,( los convierte de string a los tipos de cada campo) a una estructura empleado existente
 * \param newEmp: Puntero a Empleado (Employee*)
 * \param newId:  Nuevo Id empleado (char*)
 * \param newNombre: Nuevo Nombre empleado (char*)
 * \param newSueldo: Nuevo sueldo empleado (char*)
 * \param newHorasT: Nuevo horas de trabajo empleado (char*)
 * \return 1 si pudo realizar la carga exitosamente,0 en caso contrario.
 */

Employee* Employee_newParamString(char* newId,char* newNombre,char* newHorasT,char* newSueldo);


///-============= FUNCIONES PARA LISTAR=========================================


/***
 * \fn void Mostrar_UnEmpleado(Employee*)
 * \brief Muestra los campos del empleado pasado por parametro. El criterio depende si uno desea verlo con o sin panel descriptivo de los campos
 *
 * \param auxEmpleado
 * \param criterio: 1 con barra de menu / 0 mostrar sin barra solo los valores del empleado
 */
void Mostrar_UnEmpleado(Employee* auxEmpleado,int criterio);


///-============= FUNCIONES PARA LISTAR=========================================



///----------FUNCIONES DATOS AUTOINC
///
int Employee_MaxId(LinkedList* pArrayEmployee,int* maxId);

/***
 * \fn int Employee_searchEmployee(LinkedList*, int, int*)
 * \brief Realiza la busqueda de un empleado en la lista en caso de encontrarlo, indica que existe y devuelve su posicion
 *
 * \param pArrayEmployees: lista de empleados
 * \param idABuscar: el id del empleado a buscar
 * \param posicion: la posicion dentro del array
 * \return 1 si lo encontro, 0 en caso contrario
 */
int Employee_searchEmployee(LinkedList* pArrayEmployees,int idABuscar,int* posicion);



/***
 * \fn int Employee_Alta(Employee*, int)
 * \brief Realiza la carga de los datos del empleado, incluyendo el id autoincremental y lo muestra
 * (Este es paso previo al controller_add)
 *
 * \param pEmp: puntero a empleado
 * \param proximoId: id Autoincremental (int)
 * \return 1 si pudo realizar la carga, 0 en caso contrario
 */
int Employee_Alta(Employee* pEmp,int proximoId);

/***
 * \fn int Employee_edit(Employee*)
 * \brief Realiza la modificacion de los campos Nombre, horas trabajadas y sueldo del empleado pasado por parametro
 *
 * \param pEmp
 * \return  * \return -1 si el usuario cancelo la modificacion, 1 si pudo realizar la carga, 0 en caso contrario
 */
int Employee_edit(Employee* pEmp);










#endif // employee_H_INCLUDED
