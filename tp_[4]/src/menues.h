#ifndef MENUES_H_
#define MENUES_H_

/***
 * \fn void PanelEmpleadosSueldoHoras()
 * \brief Muestra el panel titulo de mostrarEmpleados
 *
 */
void PanelEmpleadosSueldoHoras();

/***
 * \fn void Cartel(char[])
 * \brief Muestra por un titulo por pantalla
 *
 * \param mensaje a ser mostrado
 */
void Cartel(char mensaje[]);


/**
 * \fn void CartelABM(char[])
 * \brief Muestra por un titulo por pantalla
 *
 * \param mensaje a ser mostrado
 */
void CartelABM(char mensaje[]);

/***
 * \fn void PanelEmpleados(char[])
 * \brief Muestra por un titulo por pantalla en columnado con los detalles del empleado
 *
 * \param mensaje a ser mostrado
 */
void PanelEmpleados(char mensaje[]);


/***
 * \fn void Menu_OptionABM()
 * \brief Muestra las opciones disponibles a elegir por el usuario
 *
 */
void Menu_OptionABM();

/***
 * \fn int Menu_MainABM()
 * \brief Muestra el menu principal del abm empleados
 *
 * \return la opcion elegida por el usuario del 1 al 10
 */
int Menu_MainABM();

/***
 * \fn void opcionMenuEdit()
 * \brief Muestra las opciones disponibles a elegir por el usuario del 1 al 4
 *
 */
void opcionMenuEdit();

/***
 * \fn int Menu_Edit()
 * \brief Muestra el menu de editar empleado
 *
 * \return retorna del 1 al 4 depende la opcion elegida por el usuario
 */
int Menu_Edit();


/***
 * \fn void opcionMenuSort()
 * \brief Muestra las opciones de ordenamientos disponibles a elegir por el usuario
 *
 */
void opcionMenuSort();


/***
 * \fn int Menu_Sort()
 * \brief Es el Menu principal de ordenamiento, cuenta con 4 opciones diferentes a eleccion del usuario
 *
 * \return retorna del 1 al 5 depende la opcion elegida por el usuario
 */
int Menu_Sort();




#endif /* MENUES_H_ */
