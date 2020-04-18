#ifndef CALCULADORAB_H_INCLUDED
#define CALCULADORAB_H_INCLUDED
#endif // CALCULADORAB_H_INCLUDED


void bienvenida();
void menuCalculadora();

int sumar(int num1, int num2);
/**
* brief recibe dos numeros enteros A y B , retorna la suma.
* param el primero numero para realizar la suma es entero.
* param el segundo numero utilizado para la suma es entero.
* return retorna el resultado de la suma entre A y B .
*/



int restar(int num1, int num2);
/**
* brief:recibe dos numeros enteros A y B , retorna la resta.
* param el primero numero para realizar la resta es entero.
* param el segundo numero utilizado para la resta es entero.
* return: retorna el resultado de la resta .
*/

int multiplicar(int num1, int num2);
/**
* brief: recibe dos numeros enteros A y B , retorna la multiplicacion.
* param: el primero numero para realizar la multiplicacion es entero.
* param: el segundo numero utilizado para la multiplicacion es entero.
* return retorna el resultado de la multiplicacion.
*/


float dividir(int num1, int num2);
/**
* brief : recibe dos numeros flotantes A y B , retorna la division.
* param : el numero dividiendo.
* param : el numero divisor.
* return :retorna el resultado de la division.
*/


long long int factorial(int num1);

/**
* brief :recibe un numero flotante y le realiza su factorial.
* param :el numero a realizarle el factorial.
* return :retorna el resultado del factorial.
*/

void calcularOperaciones(numeroUno, numeroDos, flagX, flagY);
void mostrarTodasLasOperaciones(int numeroUno, int numeroDos);




