/*
 * calculos.c
 *
 *  Created on: 13 abr. 2022
 *      Author: bianky
 */

#include <stdio.h>
#include <stdlib.h>

float calcularTarjetaDebito(float precioPasaje){

	float descuento;
	float resultado;

	descuento = (precioPasaje * 10)/100;
	resultado = precioPasaje - descuento;
	return resultado;
}
float calcularTarjeCredito(float precioPasaje){

	float interes;
	float resultado;

	interes = (precioPasaje * 25)/100;
	resultado = precioPasaje + interes;
	return resultado;
}
float calcularBitcoin(float precioPasaje){

	float bitcoin = 4606954.55;
	float resultado;

	resultado = precioPasaje / bitcoin;

	return resultado;
}

float calculararUnitario(int km,float precioPasaje){

	float resultado;

	resultado = precioPasaje /km;
	return resultado;
}

float diferenciaPrecio(float precioLatam, float precioAerolineas){

	float diferencia;

	if(precioLatam > precioAerolineas){
		diferencia = precioLatam - precioAerolineas;
	}else{
		diferencia =precioAerolineas - precioLatam;
	}
	return diferencia;
}
