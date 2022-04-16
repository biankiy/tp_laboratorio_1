/*
 ============================================================================
 Name        : tp_[1].c
 Author      : Bianca Micaela Gimenez 1G
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Practico numero 1 Laboratorio I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "bian.h"
#include "calculos.h"
#include "utn.h"


int main(void) {
	setbuf(stdout, NULL);

	int kilometro;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;

	char confirma = 'n';

	float precioAerolineas =0;
	float precioLatam = 0;
	int opcion;
	float diferencia;

	float latamDebito;
	float latamCredito;
	float latamBitcoin;
	float latamUnitario;

	float aerolineaDebito;
	float aerolinaCredito;
	float aerolineaBitcoin;
	float aerolineaUnitario;



	do {
		cartel(kilometro, precioAerolineas, precioLatam, flag1, flag2);
		utn_getNumero(&opcion, "Ingrese una Opcion: ","Error, ingrese del 1-6\n", 1, 6, 0);

		switch (opcion)
		{
			case 1:
				utn_getNumero(&kilometro, "Ingresar Kilometros", "Error, ingrese nuevamente\n", 0, 99999, 3);

				flag1 = 1;

				break;
			case 2:
				if(menuIngresoDeVuelos(opcion, flag1, &precioAerolineas, &precioLatam) == 1){
					flag2 = 1;
				}else{
					printf(" ,Algo salio mal");
				}
				break;
			case 3:
				if(flag1 == 1 && flag2 == 1){
					calcularCostosMenu();
					latamDebito = calcularTarjetaDebito(precioLatam);
					latamCredito = calcularTarjeCredito(precioLatam);
					latamBitcoin = calcularBitcoin(precioLatam);
					latamUnitario = calculararUnitario(kilometro, precioLatam);

					aerolineaDebito = calcularTarjetaDebito(precioAerolineas);
					aerolinaCredito = calcularTarjeCredito(precioAerolineas);
					aerolineaBitcoin = calcularBitcoin(precioAerolineas);
					aerolineaUnitario = calculararUnitario(kilometro, precioAerolineas);

					diferencia = diferenciaPrecio(precioLatam, precioAerolineas);
					flag3 = 1;
				}else {
					printf("No puede calcular los coston sin antes ingresar la opciones anteriores");
				}

				break;
			case 4:
				if( flag1 == 1 && flag2 == 1 && flag3 == 1)
				{
					mostrarCostosAerolinea(precioAerolineas, aerolineaDebito, aerolinaCredito, aerolineaBitcoin, aerolineaUnitario);
					mostrarCostosLatam(precioLatam, latamDebito, latamCredito, latamBitcoin, latamUnitario);
					printf("\nLa diferencia de precio es: %.2f", diferencia);
				}else{
					printf("\nNo puede mostrar los resultados sin antes ingresar la opcion 1,2,3 ");
				}

				break;
			case 5:

					do{

						printf("Si existen datos cargados previamente se sobreescribiran, Desea continuar de todos modos? s/n");
						fflush(stdin);
						scanf("%c",&confirma);

						printf("Muestro: %c",confirma);


						if(confirma == 's')
						{
							cargaForzada();
							printf("\n\nLa carga de datos forzada se ha realizada correctamente\n");

							confirma='n';
							break;
						}
					}while(confirma != 'n');

					break;

		}

	} while (opcion != 6 );

	return EXIT_SUCCESS;
}



