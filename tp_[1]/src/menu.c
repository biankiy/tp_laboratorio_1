/*
 * bian.c
 *
 *  Created on: 4 abr. 2022
 *      Author: bianky
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"

void cartel(int km,float precioAerolineas,float precioLatam,int flag1,int flag2){

	printf("\n--------- Menu ---------\n");

	if(flag1 == 0){
		printf("1) Ingrese Kilometros:( km=x)\n");
	}else{
		printf("1) Ingrese Kilometros:(km = %d)\n", km);
	}
	if(flag2 == 0){
		printf("2) Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n");
	}else{
		printf("2) Ingresar Precio de Vuelos: (Aerolíneas=%.2f, Latam=%.2f)\n",precioAerolineas,precioLatam);
	}

	printf("3) Calcular todos los costos:\n");
	printf("4) Informar Resultados\n");
	printf("5) Carga forzada de datos \n");
	printf("6) Salir \n");
	printf("-------------------------\n");
	printf(" \n");
}

void calcularCostosMenu(){

	printf("\n");
	printf("\n Calcular todos los costos: ");
	printf("\n a_ Tarjeta de débito descuento 10");
	printf("\n b_ Tarjeta de crédito interés 25 ");
	printf("\n c_ Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
	printf("\n d_ Mostrar precio por km (precio unitario) ");
	printf("\n e_ Mostrar diferencia de precio ingresada (Latam - Aerolíneas) ");
	printf("\n");

}

int menuIngresoDeVuelos(int opcion, int flag1, float* precioAerolineas, float* precioLatam){

	int flagM1 = 0;
	int flagM2 = 0;
	int retorno;
	char confirma = 'n';


	if (flag1 == 1) {

				do {
					if (utn_getNumero(&opcion,"\nIngrese Aerolinea: "
											"\n 1- Aerolineas"
											"\n 2- Latam"
											"\n 3- Salir "
											"\n Ingrese opcion: ","Error", 1, 3, 0) == 0) {

						switch (opcion) {
						case 1:

							if(	utn_pedirfloat(precioAerolineas, "\nIngresar Precio de \"Aerolineas-Argentinas\":$", "error", 0, 999999, 3) ==0){
								flagM1 = 1;
							}

							break;
						case 2:
							if(	utn_pedirfloat(precioLatam, "\nIngresar Precio de \"Latam\":$", "error", 0, 999999, 3) == 0){
								flagM2 = 1;
							}
							break;

						case 3:

							if(flagM1 == 1 && flagM2 == 1){
								printf("confirma cambios? s/n:  ");
								fflush(stdin);
								scanf("%c", &confirma);

							}else if(flagM1 == 1 && flagM2 == 0){
								printf("No puede salir sin antes ingresar precio Aerolineas Latam\n ");
							}else{
								printf("No puede salir sin antes ingresar precio Aerolineas Argentinas\n ");
							}
							break;
						}
					}
				} while (confirma != 's');

				retorno = 1;
			} else {
				printf("No puede ingresar precio sin antes agregar los Kilometros");
				retorno = 0;
			}

	return retorno;
}

void mostrarCostosAerolinea(float precioAerolineas, float aerolineaDebito, float aerolinaCredito, float aerolineaBitcoin, float aerolineaUnitario){
	printf("\n\nPRECIO AEROLINEA:$%.2f", precioAerolineas);
	printf("\nPrecio con Tarjeta de Debito %.2f",aerolineaDebito);
	printf("\nPrecio con Tarjeta de Credito %.2f", aerolinaCredito);
	printf("\nPrecio pagando con Bitcoins %.4f",aerolineaBitcoin);
	printf("\nPrecio Unitario %.3f",aerolineaUnitario);

}
void mostrarCostosLatam(float precioLatam, float latamDebito, float latamCredito,float latamBitcoin, float latamUnitario ){

	printf("\n\nPRECIO LATAM:$%.2f", precioLatam);
	printf("\nPrecio con Tarjeta de Debito %.2f", latamDebito);
	printf("\nPrecio con Tarjeta de Credito %.2f",latamCredito);
	printf("\nPrecio pagando con Bitcoins %.4f",latamBitcoin);
	printf("\nPrecio Unitario %.3f",latamUnitario);
	printf("\n");
}
void cargaForzada(){
	int kmCargaForzada = 7090;
	float precioAerolineasF = 162965 ;
	float precioLatamF = 159339;

	float tajertaDebitoA;
	float tajertaCreditoA;
	float bicoinA;
	float unitatioA;
	float tajertaDebitoL;
	float tajertaCreditoL;
	float bicoinL;
	float unitatioL;

	float diferencia = diferenciaPrecio(precioAerolineasF, precioAerolineasF);

	tajertaDebitoA = calcularTarjetaDebito(precioAerolineasF);
	tajertaCreditoA = calcularTarjeCredito(precioAerolineasF);
	bicoinA = calcularBitcoin(precioAerolineasF);
	unitatioA = calculararUnitario(kmCargaForzada, precioAerolineasF);

	tajertaDebitoL = calcularTarjetaDebito(precioLatamF);
	tajertaCreditoL = calcularTarjeCredito(precioLatamF);
	bicoinL = calcularBitcoin(precioLatamF);
	unitatioL = calculararUnitario(kmCargaForzada, precioLatamF);

	printf("KMs Ingresados: $%d km \n\n", kmCargaForzada);
	printf("Precio Aerolineas %.2f", precioAerolineasF);

	printf("\na)Precio con tarjeta de debito: %.2f", tajertaDebitoA);
	printf("\nb)Precio con tarjeta de credito: %.2f", tajertaCreditoA);
	printf("\nc)Precio pagado con Bitcoin: %.2f BTC", bicoinA);
	printf("\nd)Mostrar precio Unitario: %.2f", unitatioA);

	printf("\n\nPrecio Latam $%.2f", precioLatamF);
	printf("\na)Precio con tarjeta de debito: %.2f",tajertaDebitoL);
	printf("\nb)Precio con tarjeta de credito: %.2f",tajertaCreditoL);
	printf("\nc)Precio pagado con Bitcoin: %.2f BTC",bicoinL);
	printf("\nd)Mostrar precio Unitario: %.2f", unitatioL);
	printf("\n\n");
	printf("\nLa diferencia de precio es: %.2f", diferencia);

}
