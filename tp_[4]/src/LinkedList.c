#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if (this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;


    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 *
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodoActual;	//para guardar el puntero en caso de obtenerlo
	int len;
	int i; // variable de control

	pNodoActual=NULL;	//inicializo en caso de no encontrarlo
	len= ll_len(this); // tamanio de la lista

	if(this != NULL)
	{
		if (nodeIndex >= 0 && nodeIndex < len) // valido el indice del nodo a encontrar
		{
			pNodoActual = this->pFirstNode; //guardo la direccion del primer nodo , el nodo de la "cabecera"
			for( i=0 ; i< nodeIndex ; i++)  //recorro hasta el index del puntero a obtener
			{
				pNodoActual= pNodoActual->pNextNode; // apunto a la proxima direccion hasta llegar a nodeIndex
			}
		}
	}
    return pNodoActual;
}



/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int retorno;
	int len;

	Node* nuevoNodo;
	Node* anteriorNodo;

	retorno=-1;

	if(this != NULL )
	{
		len=ll_len(this);

		nuevoNodo=(Node*)malloc (sizeof(Node));

		if(nodeIndex>=0 && nodeIndex<=len)
		{
			nuevoNodo->pElement=pElement;
			if(nodeIndex ==0 )
			{
				nuevoNodo->pNextNode=this->pFirstNode;
				this->pFirstNode=nuevoNodo;

			}else{

				anteriorNodo=getNode(this, nodeIndex-1);

				if(anteriorNodo != NULL)
				{
					nuevoNodo->pNextNode=anteriorNodo->pNextNode;
					anteriorNodo->pNextNode= nuevoNodo;
				}
			}
		}
		retorno=0;
		this->size++;
	}
	return retorno;
}



/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno;
    int len;

    retorno= -1;

    if(this != NULL)
    {
    	len=ll_len(this);

    	addNode(this, len, pElement);

    	retorno=0;
    }
    return retorno;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux;
    Node* nodoObtenerDato;
    int len;
    returnAux = NULL;

    if(this != NULL)
    {
    	len= ll_len(this);
    	if(index>=0 && index < len)
    	{
    		nodoObtenerDato=getNode(this, index);
    		returnAux= nodoObtenerDato->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno;
    int len;
    Node* nodoObtenerDato;

    retorno= -1;

    if(this != NULL)
    {
    	len= ll_len(this);

    	if(index>=0 && index < len)
    	{
    		nodoObtenerDato=getNode(this, index);
    		nodoObtenerDato->pElement= pElement;
    		retorno=0;
    	}
    }
    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int retorno;
	int len;

	Node* nodoAEliminar;
	Node* nodoAnterior;

	retorno=-1;
	if(this != NULL)
	{
		len= ll_len(this);
		if(index>=0 && index < len)
		{
			nodoAEliminar=(Node*)getNode(this, index);

			if(nodoAEliminar != NULL )
			{
				if(index==0)
				{
					this->pFirstNode = nodoAEliminar->pNextNode;
				}else{
					nodoAnterior=(Node*)getNode(this, index-1);

					if( nodoAnterior != NULL)
					{
						nodoAnterior->pNextNode=nodoAEliminar->pNextNode;
					}
				}
				free(nodoAEliminar);
				this->size--;
				retorno=0;
			}
		}
	}
	return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int retorno;
	Node* nodoAux;
	int len;
	int i;

	retorno = -1;
	if(this != NULL)
	{
		len= ll_len(this);
		for(i= 0 ; i <len ; i++)
		{
			nodoAux=(Node*)getNode(this, i);
			if(nodoAux != NULL)
			{
				free(nodoAux);
				this->size--;
			}
			retorno=0;
		}
	}
	return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if( this != NULL)
    {
    	free(this);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */

int ll_indexOf(LinkedList* this, void* pElement)
{
	int retorno;
	int len;
	retorno=-1;

	if(this != NULL)
	{
		len= ll_len(this);
		for(int i=0; i<len ; i++)
		{
			/*nodoAux=(Node*) getNode(this, i);
			if(nodoAux->pElement == pElement)
			{
				retorno= i;
				break;
			}*/
			if(ll_get(this, i)== pElement)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;

}


/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL )
    {
    	if(ll_len(this)!=0)
    	{
    		returnAux=0;
    	}else{
    		returnAux=1;

    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
    	len = ll_len(this);
    	if((index>=0 && index<= len))
    	{
    		if(addNode(this, index, pElement)==0)
    		{
    			returnAux=0;
    		}
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;

    if(this != NULL)
	{
		len = ll_len(this);
		if(index>=0 && index<= len)
		{

			returnAux=ll_get(this, index);
			ll_remove(this, index);
		}
	}
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    //int len;

    if(this != NULL)
   	{
   		//len = ll_len(this);
   		if(ll_indexOf(this, pElement) != -1)
   		{
   			returnAux=1;
   		}else{
   			returnAux=0;
   		}
   		/*for(int i=0; i<len ; i++)
   		{
   			if(ll_get(this, i)==pElement)
   			{
   				returnAux=1;
   			}else{
   				returnAux=0;
   			}
   		}*/
   	}
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this1,LinkedList* this2)
{
    int returnAux;
    int len1;

    returnAux = -1;
    void* pElement_this2;

    if(this1 != NULL && this2 != NULL)
    {
    	len1 = ll_len(this1);

    	returnAux= 1;
    	for(int i=0; i<len1 ; i++)
    	{
			pElement_this2=ll_get(this2, i);//guardo el elemento de la segunda lista para verificar si esta en la lista1

			if(ll_contains(this1, pElement_this2)==0) //si estan contenidos
			{
				returnAux= 0;
				break;
			}
    	}

    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList *cloneArray = NULL;
	void *pElement;
//crea una nueva lista con el rango pasado [no incluye el ultimo elemento]
	if (!(this == NULL || from < 0 || from > ll_len(this) || to <= from || to > ll_len(this)))
	{
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL)
		{
			for (int i = from; i < to; i++)
			{
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
		}
	}
	return cloneArray;
}













/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;


    if(this != NULL )
    {
    	len=ll_len(this);
    	cloneArray= ll_subList(this, 0, len);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len;
    int i;
    int j;

    void* element1;
    void* element2;

    if(this != NULL && pFunc!= NULL && (order ==0 || order==1))//order>=0 && order<=1)
    {
    	len= ll_len(this);
    	for(i=0; i<len-1; i++)
    	{
    		for(j= i+1 ; j<len; j++)
    		{
    			element1 = ll_get(this, i);
				element2 = ll_get(this, j);

				if ((pFunc(element1, element2) > 0 && order)
				 || (pFunc(element1, element2) < 0 && !order))
				{
					ll_set(this, i, element2);
					ll_set(this, j, element1);
				}
    		}
    	}
    	returnAux=0;
    }

    return returnAux;

}

