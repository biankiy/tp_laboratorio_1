/*
 * utnB.h
 *
 * Updated on: 18 sep. 2021 11.28am
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef utnB_H_
#define utnB_H_

void MostrarUnEnteroCriterio(char simbolo[],int numero,int criterio);

/***
 * \fn char PedirChar(char[], char*)
 * \brief  Pide un caracter al usuario y lo retorna en la cariable pasada por parametro
 *
 * \param mensaje
 * \param caracter

 */
void PedirChar(char mensaje[],char* caracter);
void ConfirmaDatos(char* caracter,char* mensaje,int intentos);

int getInt(char mensaje[],char mensajeError[],int* inputInt,int reintentos);
int getFloat(char mensaje[],char mensajeError[],float* inputFloat,int reintentos);
void getString(char cadena[],char mensaje[],int tam);


/***
 * \fn int PedirNumeroEntero()
 * \brief Pide un numero entero al usuario y lo retorna
 * \param mensaje
 * \return int, el numero ingresado por el usuario
 */
int PedirNumeroEntero(char mensaje[]);


void PedirNumeroEnteroPuntero(int* numero,char mensaje[]);

/***
 * \fn void PedirNumeroEnteroExcluyente(int*, int*, char[], char[])
 * \brief
 *
 * \param numeroExcluyente
 * \param numero
 * \param mensaje
 * \param mensajeError
 */
void PedirNumeroEnteroExcluyente(int numeroExcluyente,int* numero,char mensaje[],char mensajeError[]);


/***
 * \fn int PedirNumeroEnteroConRango(char[], char[], int, int)
 * \brief  Pide al usuario un numero dentro del rango especificado
 *
 * \param mensaje: El mensaje a ser mostrado
 * \param mensajeError : El mensaje a ser mostrado en caso de error
 * \param min : El menor numero a ingresar
 * \param max : el maximo numero a ingresar
 * \return int: el numero ingresado por el usuario
 */
int PedirNumeroEnteroConRango(char mensaje[],char mensajeError[],int min, int max);

/***
 * \fn void PedirNumeroEnteroConRangoPuntero(int*, char[], char[], int, int)
 * \brief  Pide al usuario un numero dentro del rango especificado y lo guarda en la variable apuntada
 * \param int* numero: puntero a numero
 * \param mensaje: El mensaje a ser mostrado
 * \param mensajeError : El mensaje a ser mostrado en caso de error
 * \param min : El menor numero a ingresar
 * \param max : el maximo numero a ingresar
 */
void PedirNumeroEnteroConRangoPuntero(int* numero,char mensaje[],char mensajeError[],int min, int max);

/***
 * \fn void mostrarEntero(char[], int)
 * \brief Muestra un mensaje por pantalla
 *
 * \param mensaje : El mensaje a ser mostrado
 * \param numero : El numero a ser mostrado
 */
void mostrarEntero (char mensaje[],int numero);


/***
 * \fn int esNumerico(char cadena[]);
 * \brief Verifica si el valor que recibio es numerico 
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 */
int esNumerico(char cadena[]);

/***
 *
 * \fn int esNumericoFlotante(char[])
 * \brief
 *
 * \param cadena
 * \return
 */
int esNumericoFlotante(char cadena[]);
/***
 * \fn int esTelefonoCuit(char cadena[]);
 * \brief Verifica si el valor que recibio es un telefono/Cuit/Cuil
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es telefono/Cuit/Cuil y 0 si no lo es
 */
int esTelefonoCuit(char cadena[]);



/***
 * \fn int esTelefono(char cadena[]);
 * \brief Verifica si el valor que recibio es un telefono 
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 */
int esAlfaNumerico(char cadena[]);



/***
 * \fn int esSoloLetras(char cadena[]);
 * \brief Verifica si el valor recibido contiene solo letras 
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es solo ' ' y letras /  0 si no lo es
 */
int esSoloLetras(char cadena[]);

/***
 * \fn int getStringNumeros(char[], char[], char[], int, int)
 * \brief Realiza valida y carga un string de numeros
 *
 * \param mensaje .El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar en caso de error
 * \param input
 * \param lenInput
 * \param reintentos
 * \return retorna 1 si la cadena es valida, 0 en caso contrario */
int getStringNumeros(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);



/***
 * \fn int getStringNumeroFlotante(char[], char[], char[], int, int)
 * \brief
 *
 * \param mensaje
 * \param mensajeError
 * \param input
 * \param lenInput
 * \param reintentos
 * \return
 */

int getStringNumeroFlotante(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);


/***
 * \fn int getStringSoloLetras(char[], char[], char[], int, int)
 * \brief Realiza valida y carga un string de numeros
 *
 * \param mensaje .El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar en caso de error
 * \param input
 * \param lenInput
 * \param reintentos
 * \return retorna 1 si la cadena es valida, 0 en caso contrario */
int getStringSoloLetras(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);

/***
 * \fn int getStringAlfaNumerico(char[], char[], char[], int, int)
 * \brief Realiza valida y carga un string de numeros
 *
 * \param mensaje .El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar en caso de error
 * \param input
 * \param lenInput
 * \param reintentos
 * \return retorna 1 si la cadena es valida, 0 en caso contrario */
int getStringAlfaNumerico(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);

/***
 * \fn int  getStringTelefonoCuit(char[], char[], char[], int, int)
 * \brief Realiza valida y carga un string de numeros
 *
 * \param mensaje .El mensaje a mostrar
 * \param mensajeError El mensaje a mostrar en caso de error
 * \param input
 * \param lenInput
 * \param reintentos
 * \return retorna 1 si la cadena es valida, 0 en caso contrario */
int getStringTelefonoCuit(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos);

/***
 * \fn void MostrarMensaje(char[])
 * \brief
 *
 * \param mensaje
 */
void MostrarMensaje(char mensaje[]);

/***
 * \fn void MostrarMensajesRetornoFunciones(char[], char[], char[])
 * \brief Muestra diferentes mensajes segun el estado pasado por parametro
 *
 * \param mensaje1
 * \param mensaje2
 * \param mensaje3
 */

void MostrarMensajesRetornoFunciones(int estado, char mensaje1[],char mensaje2[],char mensaje3[],char mensaje4[]);

/****
 * \fn void MostrarArrayV4(int*, int)
 * \brief Muestra un array de enteros de manera horizontal y con casillas de separacion
 *
 * \param array
 * \param tam
 */
void MostrarArrayV4(int* array,int tam);





/***
 * \fn int String_Normalize_AllMinus(char[])
 * \brief Convierte cada uno de los caracteres de la cadena pasada por parametro a minuscula y la retorna convertida por referencia
 *
 * \param input
 * \return 1 si pudo realizar la conversion .0 en caso contrario
 */
int String_Normalize_AllMinus(char input[]);

/***
 * \fn int String_Normalize_AllMayus(char[])
 * \brief Convierte cada uno de los caracteres de la cadena pasada por parametro a mayuscula y la retorna convertida por referencia
 *
 * \param input
 * \return 1 si pudo realizar la conversion .0 en caso contrario
 */
int String_Normalize_AllMayus(char input[]);

/***
 * \fn void String_Normalize_MayusMinus(char[])
 * \brief Convierte cada uno de los caracteres de la cadena pasada por parametro a mayuscula y su primer caracter a mayuscula. la retorna convertida por referencia
 *
 * \param input
 * \return 1 si pudo realizar la conversion .0 en caso contrario
 */
void String_Normalize_MayusMinus(char input[]);

/***
 * \fn void getString_NormalizeName(char[], char[], char[], int, int, int)
 * \brief Pide el ingreso de una cadena, si es un string de solo letras segun el criterio normaliza 0: todo minus/1 mayus primer caracter luego minus / 2 todo matus
 *
 * \param mensaje : el mensaje a ser mostrado
 * \param mensajeError : el mensaje a ser mostrado en caso de error
 * \param input: la cadena donde sera cargado el string convertido
 * \param lenInput: tamanio de la cadena
 * \param reintentos :
 * \param criterio normaliza 0: todo minus/1 mayus primer caracter luego minus / 2 todo matus
 */
void getString_NormalizeName(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos,int criterio);







#endif /* KARENIO_H_ */
