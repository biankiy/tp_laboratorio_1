
/**
* @brief  Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
*
* @param path char* nombre o ruta del del archivo
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 si no pudi realizar la apertura o path o lista = a NULL; 1 si pudo realizar la carga correctamente.
*/int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
/**
* @brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
*
* @param path char* nombre o ruta del del archivo
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 si no pudo realizar la apertura o path o lista = a NULL; 1 si pudo realizar la carga correctamente.
*/int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
* @brief Da de alta a un nuevo pasajero
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @param pLastId int* puntero al ultimo id utilizado
* @return 0 en caso de list o plastId = a NULL; 1 si se adhirio correctamente.
*/int controller_addPassenger(LinkedList* pArrayListPassenger,int* pLastId);

/**
* @brief Modifica datos de un pasajero
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 en caso de no realizar modificacion, 1 si se realizo alguna modificacion
*/int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
* @brief Da de baja un pasajero significa eliminarlo del array de pasajeros
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 en caso de no confirmar la eliminacion, 1 si se elimino correctamente
*/int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
* @brief muestra una lista de pasajeros
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 si no hay pasajeros cargados o arrayList = a NULL, 1 Si se pudo mostrar correctamente.
*/int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
* @brief ordena la lista de pasajeros
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 si no se realizo ningun ordenamiento o el arrayList sea = a NULL, 1 si se realizo algun ordenamiento
*/int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
* @brief Guarda los datos de los pasajeros en el archivo data.csv [modo texto].
*
* @param path char* nombre o ruta del del archivo
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 en caso de qe la ruta sea invalida o el arrayList sea = a NULL, 1 si se pudo gardar correctamente.
*/int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
* @brief  Guarda los datos de los pasajeros en el archivo data.csv [modo binario].
*
* @param path char* nombre o ruta del del archivo
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 en caso de que la ruta sea invalida o arrayList sea igual a NULL, 1 si se pudo gardar correctamente.
*/int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

