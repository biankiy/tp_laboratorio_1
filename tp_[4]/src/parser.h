/*
 * parser.h
 *
 *  Created on: 4 nov. 2021
 *      Author: Compu casa
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de NULL / 1 caso de exito
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de NULL / 1 caso de exito
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);





#endif /* PARSER_H_ */
