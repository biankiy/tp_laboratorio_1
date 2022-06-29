/*
 * estadoVuelo.h
 *
 *  Created on: 8 jun. 2022
 *      Author: bianky
 */


#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

typedef struct{
    int idStatus;
    char desc[20];
}eStatusFlight;

typedef struct{
    int idTypePassenger;
    char desc[20];
}eTypePassenger;


#endif /* STATUSFLIGHT_H_ */

/**
 * @brief muestra un listado de los tipos de vuelo
 *
 * @param estados eStatusFlight[] array de los estados de vuelo
 * @param cantEst largo del array de estados de vuelo
 * @return -1 en caso de error, 0 si lo pudo listar correctamente
 */
int listarEstado(eStatusFlight estados[],int cantEst);
/**
 * @brief busca dentro del array de vuelos estados de vuelo la descripccion correspondiente a un determinado id de estado de vuelo y devuelve la descripccion correspondiente
 *
 * @param estados eStatusFlight array del estado de vuelos
 * @param cantEst largo del array de estados de vuelo
 * @param idEst id del estado de vuelo que se buscara
 * @param descripccion direccion donde se copiara la descripccion del vuelo en caso de haberse ingresado un id de vuelo existente
 * @return 0 en caso de error o que no se encuentre el id, 1 si se logro copiar la descripccion correctamente
 */
int altaDescripcionEstado(eStatusFlight estados[],int cantEst,int idEst,char descripccion[]);

//-------------------------------------------------------------------------------------------------------------

 /**
  * @brief permite mostrar el listado de tipos de pasajero existente
  *
  * @param tipos eTypePassenger, array de tipo de pasajeros
  * @param cantTipos largo del array
  * @return -1 en caso de error. 0 si logro listar correctamente
  */
int listarTipoPasajero(eTypePassenger tipos[],int cantTipos);
 /**
  * @brief permite cargar la descripccion del tipo de pasajero segun el id del tipo de pasajero
  *
  * @param tipos eTypePassenger array de tipo de pasajeros
  * @param tamTipos int largo el array de tipo de pasajeros
  * @param idTipo int  id del tipo de pasajero.
  * @param vec char[] destino donde sera copiada la descripcciond el tipo de pasajero
  * @return
  */
int cargarDescTypePassenger(eTypePassenger tipos[],int tamTipos, int idTipo, char vec[]);
