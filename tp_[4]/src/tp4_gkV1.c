#include <stdio.h>
#include <stdlib.h>
#include "menues.h"

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
 *
 * GIMENEZ, BIANCA MICAELA
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);

	char salir = 'n';
	char confirma;

	int estado;

	int flagAperturaTXT=0;
	int flagAperturaBin=0;


	LinkedList* lista = ll_newLinkedList();

	    do
	    {
	       switch(Menu_MainABM())
	       {
	       	   case 1:

	       		 if(flagAperturaTXT==0 && flagAperturaBin==0)
				   {
					   ConfirmaDatos(&confirma,"\nDesea cargar el Archivo TXT ? Se actualizaran los datos, confirma? s|n\n", 3);

					   if(confirma=='s'|| confirma=='S')
					   {
							//ll_clear(lista);
							if(controller_loadFromText("data.csv",lista)==1)
							{
								flagAperturaTXT=1;
							}
							else{
								printf("ERROR, No es posible cargar el Archivo TXT!!!\n\n");
							}
					   }else{
						   printf("Carga de datos Anulada!!!\n\n");;
					   }
				   }else{
					   printf("Los datos han sido cargados!!!\n;");
				   }
				   break;

	       case 2:

	    	   if(flagAperturaBin==0 && flagAperturaTXT==0)
			   {
				   ConfirmaDatos(&confirma,"\nDesea cargar el Archivo BIN ? Se actualizaran los datos, confirma? s|n\n", 3);
				   printf("confirma == %c\n",confirma);
				   if(confirma=='s'|| confirma=='S')
				   {
						//ll_clear(lista);
						if(controller_loadFromBinary("data.bin",lista)==1)
						{
							flagAperturaBin=1;
						}
						else{
							printf("ERROR, No es posible cargar el Archivo BIN!!!\n\n");
						}
				   }else{
					   printf("Carga de datos Anulada!!!\n\n");;
				   }
			   }else{
				   printf("Los datos han sido cargados!!!\n");
			   }
	    	   break;


	      case 3:
	    	  	  if(ll_isEmpty(lista) != -1)
	    	  	  {
	    	  		controller_addEmployee(lista);
	    	  	  }
	    	  	  break;

	       case 4:
	           if(!ll_isEmpty(lista))
	           {
	        	   estado=controller_editEmployee(lista);
	               MostrarMensajesRetornoFunciones(estado, "No se pudo realizar la Modificacion, el empleado no existe", "Se han modificado los datos", "El usuario cancelo la modificacion", " ");

	           }else
			   {
				   printf("No hay empleados que mostrar\n\n");
			   }
	        break;

	       case 5:
	    	   if(!ll_isEmpty(lista))
	    	   {
	               estado=controller_removeEmployee(lista);
	               MostrarMensajesRetornoFunciones(estado, "No se pudo realizar la baja, el empleado no existe", "Se han realizado la baja con exito", "El usuario cancelo la baja del empleado", " ");
	    	   }else
				   {
					   printf("No hay empleados que eliminar\n\n");
				   }
	        break;

	       case 6:
	    	   if(!ll_isEmpty(lista))
	    	  {
	               controller_ListEmployee(lista);
	           }
	           else
	           {
	               printf("No hay empleados que mostrar\n\n");
	           }
	            printf("\n");
	        break;


	       case 7:
	           if(!ll_isEmpty(lista))
	           {
	               estado=controller_sortEmployee(lista);
	               MostrarMensajesRetornoFunciones(estado, "ERROR,No se pudieron guardar los datos en el txt","Los datos se guardaron correctamente en el archivo TXT", "El usuario cancelo la baja del empleado", " ");
	           }
	           else
			   {
				   printf("--ERROR, NO HAY EMPLEADOS QUE ORDENAR---\n\n");
			   }
	        break;

	       case 8:

	    	   if(!ll_isEmpty(lista) )
			   {
				   estado=controller_saveAsText("data.csv",lista);
	               MostrarMensajesRetornoFunciones(estado, "ERROR,No se pudieron guardar los datos en el txt","Los datos se guardaron correctamente en el archivo TXT", "El usuario cancelo la escritura del archivo", " ");

	               if(estado==1)
	               {
	            	   estado=controller_saveAsBinary("data.bin",lista);
		    	       MostrarMensajesRetornoFunciones(estado, "ERROR,No habra consistencia de datos entre los archivos TXT y BIN","Archivos de Datos Bin y TxT sincronizados", " ", " ");

	               }
			   }else
			   {
				   printf("No hay empleados cargados para ser guardados,ingrese al menos uno\n");
			   }
			   break;

			   break;
	       case 9:
	    	   if(!ll_isEmpty(lista) )
			   {
				   estado= controller_saveAsBinary("data.bin",lista);
	    	       MostrarMensajesRetornoFunciones(estado, "ERROR,No se pudieron guardar los datos en el bin","Los datos se guardaron correctamente en el archivo BIN", "El usuario cancelo la escritura del archivo", " ");

	    	       if(estado==1)
	    	       {
					   estado=controller_saveAsText("data.csv",lista);
					   MostrarMensajesRetornoFunciones(estado, "ERROR,No habra consistencia de datos entre los archivos TXT y BIN","Archivos de Datos Bin y TxT sincronizados", " ", " ");

				  }

			   }else
			   {
				   printf("No hay empleados cargados para ser guardados,ingrese al menos uno\n");
			   }
	        break;

	       case 10:
	    	   Cartel(">>> SALIDA <<< ");
	    	   ConfirmaDatos(&confirma,"\n Confirma salida? s / n\n", 3);

	    	   if(confirma=='s'|| confirma == 'S')
	    	   {

	    		   printf("--Hasta luego !!--\n\n");
					system("pause");
					salir='s';
			 } break;
	       default:
	        printf("Ingrese una opcion valida\n");
	        break;
	  }


	    }while(salir != 's');

	    ll_deleteLinkedList(lista);

	    return EXIT_SUCCESS;
	}



