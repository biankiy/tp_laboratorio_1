

//------------------------------FUNCIONES MAX ID AUTOINCREMENTAL----------------------------------------------------------

/****
 * \fn int proximoId_maxArchivoTXT(char*, LinkedList*, int*)
 * \brief Obtiene el id maximo luego de la carga de un archivo y la devuelve por referencia
 *
 * \param path
 * \param pArrayListEmployee
 * \param maxId: puntero a entero que guardara el idMaximo
 * \return 1 en caso de obtenerlo, 0 en caso contrario
 */
int proximoId_maxArchivoTXT(char* path,LinkedList* pArrayListEmployee,int* maxId);

/****
 * \fn int proximoId_maxArchivoTXT(char*, LinkedList*, int*)
 * \brief Obtiene el id maximo a partir de un archivo y lo escribe en un archivo propio y  la devuelve por referencia

 * \param pArrayListEmployee
 * \param maxId: puntero a entero que guardara el idMaximo
 * \return 1 en caso de obtenerlo, 0 en caso contrario
 */
int proximoId_CargarMaxIdV2(LinkedList* pArrayListEmployee,int* idMax);

/***
 * \fn int ProximoId_obtener(int*)
 * \brief Realiza la lectura de un archivo y Obtiene el id.
 *
 * \param id
 * \return 1 en caso de obtener el id, 0 en caso contrario
 */
int ProximoId_obtener(int* id);


/***
 * \fn int ProximoId_actualizar(int*)
 * \brief Realiza la apertura de un archivo y apartir del id pasado por parametro, lo incrementa, lo guarda y lo pasa por parametro actualizado
 *
 * \param id
 * \return 1 en caso de poder actualizar el id, 0 en caso contrario
 */
int ProximoId_actualizar(int* id);


//------------------------------FUNCIONES CONTROLLER----------------------------------------------------------

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 (lista NULL) / 1 en caso de exito
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 (lista NULL) / 1 en caso de exito
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/****
 * \fn int controller_addEmployee(LinkedList*)
 * \brief Realiza el alta de un empleado en la lista pasada por parametro
 *
 * \param pArrayEmployee
 * \return 0 em caso de error lista NULL/ 1 caso de exito /
 */
int controller_addEmployee(LinkedList* pArrayEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 lista NULL / 1 caso de exito
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de error / 1 caso de exito / -1 cancelado por el usuario
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  0 en caso de NULL / 1 EXITO / -1 cancelado por el usuario
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/***
 * \fn int controller_sortEmployee(LinkedList*)
 * \brief Realiza el ordenamiento de la lista segun criterio del usuario
 *
 * \param pArrayListEmployee
 * \return 1 en caso de exito, 0 caso contrario
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
* \return int 0 en caso de NULL / 1 - exito / -1 cancelado por el usuario
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de NULL / 1 - exito / -1 cancelado por el usuario
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

