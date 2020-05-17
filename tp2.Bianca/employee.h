#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED


//void hardcodearEmployees(Employee lista[], int len);
/** \brief muestra un empleado
 *
 * \param empleado aux
 * \param vector de sector
 * \param tamanio del vector
 * \return sin retorno
 *
 */

void mostrarEmpleado (Employee x);


 /** \brief Inicializa el campo isEmpy del vector de empleados en 1
  * \param Estructura eEmployee: lista de empleados
  * \return 0 si pudo inicializar con exito, y -1 si no.
  */
 int initEmployees(Employee lista[], int len);


void printEmployees( Employee lista[], int len);
int searchFreeLocation(Employee lista[], int len);

/** \brief Aniade empleados al vector de empleados.
 *
 * \param Lista de empleados
 * \param Tamanio de la lista
 * \param Id del empleado
 * \param Nombre del empleado
 * \param Apellido del empleado
 * \param Salario
 * \param Sector
 * \param Indice en el cual cargarlo.
 * \return 0  si pudo cargar al empleado con exito, y -1 si no.
 */


int altaEmpleado(int id, Employee lista[], int len);


/** \brief Busca un lugar vacio (isEmpty = 0) en el vector de empleados
 *
 * \param Lista de empleados
 * \param Tamanio de la lista.
 * \return 0 si pudo encontrar lugar vacio con exito, y -1 si no.
 *
 */

int addEmployee(Employee lista[], int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Encuentra un empleado en la lista con un id.
 *
 * \param  lista de empleados
 * \param  lasrgo de la lista
 * \param id del empleado a buscar
 * \return   El indice del empleado si lo encuentra, sino -1.
 *
 */

int findEmployeeById(Employee lista[], int len,int id);

void modifyEmployee(Employee lista[],int len);

/** \brief Da de baja a un empleado del sistema.
 *
 * \param Lista de empleados
 * \param Tamanio de la lista
 * \param Id del empleado
 * \param Vector de sectores
 * \param Tamanio del vector de sectores.
 * \return  0 si pudo eliminar con exito, y -1 si no.
 *
 */

void removeEmployee(Employee lista[],int len, int id);
float sumaSalarios(Employee lista[],int len);

float promedio(Employee lista[],int len);

int cantidadDeEmpleadosSalarioMayorDelPromedio(Employee lista[],int len,float promedio);

/** \brief Agrupa los empleados por sector (del 1 al 5) y los ordena de manera ascendente o descendente.
 *
 * \param Lista de empleados
 * \param Tamanio del vector de empleados
 * \param Orden (1 para ascendente y 0 para descendente)
 * \return 0 si pudo ordenar con exito, y -1 si no.0 si pudo ordenar con exito, y -1 si no.
 *
 */

void sortEmployees(Employee lista[],int tam,int order);

/** \brief retorna menu info
 *
 * \param lista de empleados
 * \param tamaño vector empleado
 * \param vector de sectores
 * \param  tamaño vecor sectores
 * \return Retorna 0 si es una opcion valida, -1 si no
 *
 */

void informar(Employee lista[],int len);
//void hardcodearEmployees(Employee list[], int len);
//void mostrarEmpleado (Employee x);
//void printEmployees( Employee list[], int len);
//int altaEmpleado(int id, Employee list[], int len);

#endif // EMPLOYEE_H_INCLUDED
