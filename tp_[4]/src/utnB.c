
#include "utnB.h"




void MostrarUnEnteroCriterio(char simbolo[],int numero,int criterio)
{
    if(criterio)
    {
        printf(" %d%s",numero,simbolo);// 10|
    }else{
        printf("%d%s\n",numero,simbolo);//10
                        //9..
    }
}
void PedirChar(char mensaje[],char* caracter)
{
	printf("%s\n",mensaje);
	fflush(stdin);
	scanf("%c",caracter);
}

void ConfirmaDatos(char* caracter,char* mensaje,int intentos)
{
	do
	{
		PedirChar(mensaje,caracter);
		intentos--;
	}while(*caracter != 'S' && *caracter != 'S' && *caracter != 'N'  && *caracter != 'n' && intentos==0);
}

void getString(char cadena[],char mensaje[],int tam)
{
    char auxiliar[tam];
    
    printf("%s\n", mensaje);
    fflush(stdin);
   scanf("%s", auxiliar);

    strcpy(cadena, auxiliar);
}

int PedirNumeroEntero(char mensaje[]){
    int numero;

    printf("%s\n",mensaje);
    scanf("%d",&numero);
    return numero;
}

//---------------------

void PedirNumeroEnteroPuntero(int* numero,char mensaje[])
{
    printf("%s\n",mensaje);
    scanf("%d",numero);
}

void PedirNumeroEnteroExcluyente(int numeroExcluyente,int* numero,char mensaje[],char mensajeError[])
{
    printf("%s \n",mensaje);//"Ingrese un numero dentro del rango %d - %d : \n"
    scanf("%d",numero);

    while(*numero == numeroExcluyente){

        printf("%s \n",mensajeError);
        scanf("%d",numero);
    }
}

void PedirNumeroEnteroConRangoPuntero(int* numero,char mensaje[],char mensajeError[],int min, int max)
{
    printf("\n%s ",mensaje);//"Ingrese un numero dentro del rango %d - %d : \n"
    printf("%d - %d : \n",min,max);
    scanf("%d",numero);

    while(*numero<min || *numero>max){

        printf("%s ",mensajeError);
        printf("%d - %d : \n",min,max);
        scanf("%d",numero);
    }
}

int getInt(char mensaje[],char mensajeError[],int* inputInt,int reintentos)
{
	int retorno;
	char auxCad[256];

	retorno=0;
	if(getStringNumeros(mensaje,mensajeError,auxCad,strlen(auxCad),reintentos)==1)
	{
		*inputInt= atoi(auxCad);
		retorno=1;
	}
	return retorno;
}


int getFloat(char mensaje[],char mensajeError[],float* inputFloat,int reintentos)
{
	int retorno;
	char auxCad[256];

	retorno=0;
	if(getStringNumeroFlotante(mensaje,mensajeError,auxCad,strlen(auxCad),reintentos)==0)
	{
		*inputFloat= atof(auxCad);
		retorno=1;
	}

	return retorno;
}

void mostrarEntero (char mensaje[],int numero){
    printf("%s\n",mensaje);
    printf("%d",numero);
}

void MostrarArrayEnteros(int lista[],int tam)
{
	printf("Listado de numeros \n");
	if(lista != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			//printf("%d - ", lista[i]);
			mostrarEntero("| ", lista[i]);
		}
		printf("\n\n");
	}
	else
	{
		printf("--No hay elementos que mostrar--\n");
	}

}

int DeterminarParidad(int numero)
{
	int esPar;

	esPar=0;
	if(numero %2 == 0 )
	{
		esPar=1;
	}
	return esPar;
}



int esNumerico(char cadena[])
{
    int i;
    int retorno;
    
    retorno=1;
    for(i=0 ;cadena[i] != '\0';i++ )
    {
        if(!(isdigit(cadena[i]) ))		//(cadena[i]<'0' || cadena[i]> '9')
        {
            retorno=0;
        }
    }
    return retorno;
}

int esNumericoFlotante(char cadena[])
{
	int retorno;
	int cantPuntos;

	retorno=1;
	cantPuntos=0;
	for(int i=0 ; cadena[i] != '\0';i++)
	{
		if(cadena[i]== '.' && cantPuntos ==0)
		{
			cantPuntos++;
			continue;
		}
		if(cadena[i] <'0' || cadena[i] > '9')
		{
			retorno=0;
		}
	}
	return retorno;
}

int esTelefonoCuit(char cadena[])
{
	int i;
    int retorno;
    int contadorGuiones;

    contadorGuiones=0;
    
    for(i=0 ;cadena[i] != '\0';i++ )
    {
    	if(!( (isspace(cadena[i])) || (isdigit(cadena[i])) || (cadena[i] == '-')) )
    	{
            retorno=0;
        }
    	if(cadena[i]=='-')
		{
			contadorGuiones+=1;
		}
    }
    if(	contadorGuiones>0 && contadorGuiones<3)  //los celulares y cuits usan dos guiones
    {
    	retorno=1;
    }
    return retorno;
}
 
int esAlfaNumerico(char cadena[])
{
    int i;
    int retorno;
    
    retorno=1;
    for(i=0 ;cadena[i] != '\0';i++ )
    { //  if((cadena[i]!= ' ') && (cadena[i]< 'a'|| cadena[i]> 'z') && ( cadena[i]< 'A'|| cadena[i]> 'Z') && (cadena[i]<'0' || cadena[i]> '9') )
        if( !((isspace(cadena[i])) || (isalpha(cadena[i])) || isdigit(cadena[i])) )
    	{
           retorno=0;
        }
    }
    return retorno;
}       
    

int esSoloLetras(char cadena[])
{
    int retorno;
    
    retorno=1;
    for(int i=0 ;cadena[i] != '\0';i++ )
    {
    	if(!( isspace(cadena[i]) || isalpha(cadena[i]) ))
    	{//optimizaDA //funciona if( ! ( (cadena[i] == ' ') || ( cadena[i]>'a'&& cadena[i]< 'z') || ( cadena[i]> 'A'|| cadena[i]< 'Z')) )
             retorno=0;
        }
    }
    return retorno;
}

/*-------------------*/

int getStringNumeros(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
    char aux[lenInput];
    int retorno;

    retorno=1;

    getString(aux,mensaje,lenInput);
    reintentos--;
    while( reintentos != 0 && (esNumerico(aux)==0) )
    {
    	getString(aux,mensajeError,lenInput);
    	reintentos--;
    	retorno=0;
    }
    strcpy(input,aux);

    return retorno;
}

int getStringSoloLetras(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
    char aux[lenInput];
    int retorno;

    retorno=1;

    getString(aux,mensaje,lenInput);

    reintentos--;
    while( reintentos != 0 && (esSoloLetras(aux)==0) )
    {
    	getString(aux,mensajeError,lenInput);

    	reintentos--;
    	retorno=0;
    }
    strcpy(input,aux);

    return retorno;
}



int getStringAlfaNumerico(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
    char aux[lenInput];
    int retorno;

    retorno=1;

    getString(aux,mensaje,lenInput);
    reintentos--;
    while( reintentos != 0 && (esAlfaNumerico(aux)==0) )
    {
    	getString(aux,mensajeError,lenInput);
    	reintentos--;
    	retorno=0;
    }

    strcpy(input,aux);


    return retorno;
}


int getStringTelefonoCuit(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
    char aux[lenInput];
    int retorno;

    retorno=1;

    getString(aux,mensaje,lenInput);
    reintentos--;
    while( reintentos != 0 && (esTelefonoCuit(aux)==0) )
    {
    	getString(aux,mensajeError,lenInput);
    	reintentos--;
    	retorno=0;
    }
    strcpy(input,aux);

    return retorno;
}

int getStringNumeroFlotante(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
	char aux[lenInput];
	int retorno;

	retorno=0;

	 getString(aux, mensaje, lenInput);
	 reintentos--;

	 while( reintentos != 0 && (esNumericoFlotante(aux) ==0))
	 {
		 getString(aux, mensajeError, lenInput);
		 strcpy(input,aux);
		 retorno=1;
	}
	 //if(esNumericoFlotante(aux)==1))
	 //{
		 strcpy(input,aux);
//	 }
	return retorno;
}



void MostrarMensaje(char mensaje[])
{
	printf(" %s \n",mensaje);
}

void MostrarMensajesRetornoFunciones(int estado, char mensaje1[],char mensaje2[],char mensaje3[],char mensaje4[])
{
	switch(estado)
	{
		case 0 :
			MostrarMensaje(mensaje1);
		break;

		case 1 :
			MostrarMensaje(mensaje2);
		break;

		case -1 :
			MostrarMensaje(mensaje3);
		break;

		default:
			MostrarMensaje(mensaje4);
		break;
	}
}

void MostrarArrayV4(int* array,int tam)
{
    for(int i=0 ; i<tam ; i++)
    {
        MostrarUnEnteroCriterio(" | ",*(array+i),1);
    }
}



int String_Normalize_AllMinus(char input[])
{
	int retorno;

	retorno=0;
	if( input != NULL && esSoloLetras(input)==1 )
	{
		for (int i = 0; input[i] != '\0'; i++)
		{
			input[i] = tolower(input[i]);
		}
		retorno=1;
	}
	return retorno;
}

int String_Normalize_AllMayus(char input[])
{
	int retorno;

	retorno=0;
	if( input != NULL && esSoloLetras(input)==1 )
	{
		for (int i = 0; input[i] != '\0'; i++)
		{
			input[i] = toupper(input[i]);
		}
		retorno=1;
	}
	return retorno;
}
void String_Normalize_MayusMinus(char input[])
{
	int quantity;
	int i;
	String_Normalize_AllMinus(input);
	input[0] = toupper(input[0]);
	quantity = strlen(input);
	for (i=0;i<quantity;i++){
		if (input[i]==' '){
			input[i+1] = toupper(input[i+1]);
		}
	}
}

void getString_NormalizeName(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos,int criterio)
{
	char auxCadena[lenInput];

	//if(getStringSoloLetras(mensaje, mensajeError, auxCadena, lenInput, reintentos)==1)
	getStringSoloLetras(mensaje, mensajeError, auxCadena, lenInput, reintentos);
	if(esSoloLetras(auxCadena)==1)
	{

		switch(criterio)
		{
			case 0:
					String_Normalize_AllMinus(auxCadena);
					break;

			case 1://Primera mayus lo demas minus
					String_Normalize_MayusMinus(auxCadena);

					break;

			case 2:
					String_Normalize_AllMayus(auxCadena);
					break;
			default:
				printf("No existe el criterio ingresado\n 1- todo minuscula 2- primera mayus luego minus,3- todo mayusculas");
				break;
		}
		strcpy(input,auxCadena);
	}
}

/*
int getString_NormalizeName2(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos,int criterio)
{
	char auxCadena[lenInput];
	int retorno;

	//if(getStringSoloLetras(mensaje, mensajeError, auxCadena, lenInput, reintentos)==1)
	getStringSoloLetras(mensaje, mensajeError, auxCadena, lenInput, reintentos);
	if(esSoloLetras(auxCadena)==1)
	{
		switch(criterio)
		{
			case 0:
					String_Normalize_AllMinus(auxCadena);
					strcpy(input,auxCadena);
					break;

			case 1://Primera mayus lo demas minus
					String_Normalize_MayusMinus(auxCadena);
					strcpy(input,auxCadena);
					break;

			case 2:
					String_Normalize_AllMayus(auxCadena);
					strcpy(input,auxCadena);
					break;
			default:
				printf("No existe el criterio ingresado\n 1- todo minuscula 2- primera mayus luego minus,3- todo mayusculas");
				break;
		}
		//strcpy(input,auxCadena);
		retorno=1;
	}
	return retorno;
}*/



