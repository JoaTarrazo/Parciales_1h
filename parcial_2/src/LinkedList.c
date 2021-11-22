//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "LinkedList.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STATICS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static Node* getNode(LinkedList* this, int nodeIndex);

static int addNode(LinkedList* this, int nodeIndex,void* pElement);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCIONES:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LinkedList* ll_newLinkedList(void)
{
	LinkedList* this;

	this= (LinkedList*)malloc(sizeof(LinkedList));

	    if(this!=NULL)
	    {
	    	this->pFirstNode=NULL;

	    	this->size=0;
	    }

	    return this;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_len(LinkedList* this)
{
	int returnAux = -1;

	    if(this!=NULL)
	    {
	    	returnAux=this->size;
	    }

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node * nodoAuxiliar=NULL;  //si la lista esta vacia, nunca entra al for y por ende se retorna "nodoAuxiliar= this->pFirstNode" que contiene un NULL.

	int i;

		if(this!= NULL && nodeIndex >= 0 && ll_len(this) > nodeIndex)// si la lista esta vacia, nunca entra al for y por ende se retorna "nodoAuxiliar= this->pFirstNode" que contiene un NULL.
		{
			nodoAuxiliar= this->pFirstNode;  //igualo el nodo creado en NULL, al PRIMER nodo de la lista.

			for(i=0; i<nodeIndex; i++)  //itero hasta uno menos del indice pedido ya que el anterior nodo apuntara a ese indice.
			{
				nodoAuxiliar=nodoAuxiliar->pNextNode;    //El nodo ira obteniendo el valor del siguiente nodo y asi sucesivamente hasta llegar a uno menos q el indice
			}
		}

	    return nodoAuxiliar;  //retorno la direc de memoria del nodo.
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;

    Node* pNodo;

    //creo el nuevo nodo

    if(this!=NULL && nodeIndex>=0 && nodeIndex <= this->size)
    {
    	pNodo = (Node*)malloc(sizeof(Node));

    	if(pNodo!=NULL)
    	{
    		pNodo->pElement = pElement; //esto pasa siempre.

    		//diferenciar los 3 casos:

    		if(nodeIndex==0) //me quieren agregar el nodo en la primer posicion
    		{
    			pNodo->pNextNode = this->pFirstNode;

    			this->pFirstNode = pNodo;//pNodo tiene la direc de su ubicacion(malloc)

    			this->size++;
    		}
    		else //son los del medio Y EL ULTIMO.
    		{
    			 Node* pNodoAux2;

    			pNodoAux2 = test_getNode(this, (nodeIndex-1));

    			pNodo->pNextNode = pNodoAux2->pNextNode;

    			pNodoAux2->pNextNode = pNodo;

    			this->size++;
    		}

    		returnAux = 0;
    	}
    }

    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	return addNode(this,nodeIndex,pElement);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_add(LinkedList* this, void* pElement)
{

	int returnAux = -1;

    int index=ll_len(this);

    if(index>=0)
    {
    	if(addNode(this, index,pElement)==0)
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/*

int ll_add(LinkedList* this, void* pElement)
{
      int retAux = -1;

        if(this!=NULL)
        {
        	retAux = addNode(this, this->size, pElement);  //retorna lo mismo que retornaria el addNode.
        }

        return retAux;
}

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* ll_get(LinkedList* this, int index)
{
	void * returnAux=NULL;

	int len = ll_len(this);

		Node* nodoAuxiliar;

		if(this!=NULL && index >= 0 && len > index)
		{
			nodoAuxiliar=getNode(this, index);

			returnAux=nodoAuxiliar->pElement;
		}

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_set(LinkedList* this, int index,void* pElement)
{

	int returnAux = -1;

		int i;

		Node* nodoAuxiliar=(Node*)malloc(sizeof(Node));

		if(this!=NULL && index >= 0 && ll_len(this) > index)
		{
			nodoAuxiliar=this->pFirstNode;

			for(i=0; i<index; i++)
			{
				nodoAuxiliar=nodoAuxiliar->pNextNode;
			}

			nodoAuxiliar->pElement=pElement;

			returnAux=0;
		}


	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_remove(LinkedList* this, int index)
{

	int returnAux = -1;

	Node* nodoABorrar;

	Node* nodoAnterior;

		if(this!=NULL && index >= 0 && ll_len(this) > index)
		  {
			if(index==0)
			{
				nodoABorrar=this->pFirstNode;

				this->pFirstNode=nodoABorrar->pNextNode;

				free(nodoABorrar);
			}
			else
			{
				nodoABorrar=getNode(this,index);

				nodoAnterior=getNode(this,index-1);

				nodoAnterior->pNextNode=nodoABorrar->pNextNode;

				free(nodoABorrar);
			}
				this->size--;

				returnAux=0;
		  }

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_clear(LinkedList* this)
{

	int returnAux = -1;

	    int i;

	    if(this!=NULL)
	    {
	        for(i=0; i<ll_len(this); i++)
	        {
	        	ll_remove(this,0);
	        }

	        returnAux=0;

	    }

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_deleteLinkedList(LinkedList* this)
{

	int returnAux = -1;

	    if(this!=NULL)
	    {
	    	ll_clear(this);

	    	free(this);

	    	returnAux=0;
	    }

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_indexOf(LinkedList* this, void* pElement)
{

	int returnAux = -1;

	void* PunteroElementoAux;

	int i;

	    if(this!=NULL)
	    {
	        for(i=0; i<ll_len (this); i++)
	        {
	        	PunteroElementoAux=ll_get(this,i);

	        	if(PunteroElementoAux == pElement)
	        	{
	        		returnAux=i;

	        		break;
	        	}
	        }
	    }

	    return returnAux;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_isEmpty(LinkedList* this)
{

	int returnAux = -1;

	    if(this!=NULL)
	    {
	    	if(this->size == 0)
	    	{
	    		returnAux=1;

	    	}
	    	else
	    	{
	    		returnAux=0;
	    	}
	    }

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_push(LinkedList* this, int index, void* pElement)
{

	int returnAux = -1;

	int len= ll_len(this);

	    if(this!= NULL && index >= 0 && index <= len)
	    {
	        if(addNode(this, index, pElement)==0)
	        {
	        	returnAux=0;
	        }
	    }

	     return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* ll_pop(LinkedList* this,int index)
{

	 void* returnAux = NULL;

	 void* pElementAux;

	   pElementAux= ll_get(this,index);

	    if(pElementAux!=NULL)
	    {
	    	returnAux = pElementAux;
	    }

	    ll_remove(this,index);

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_contains(LinkedList* this, void* pElement)
{

	int returnAux = -1;

	int indexAux;

	    if(this!=NULL)
	    {
	    	returnAux=0;

	        indexAux = ll_indexOf(this,pElement);

	        if(indexAux>=0)
	        {
	        	returnAux= 1;
	        }
	    }

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_containsAll(LinkedList* this,LinkedList* this2)
{

	int returnAux = -1;

	    int lenghtUno;

	    void* pElementoUno;

	    if(this!= NULL && this2!= NULL)
	    {
	    	returnAux=0;

	        lenghtUno = ll_len(this);

			for(int i=0; i<lenghtUno; i++)
			{
				returnAux=1;

				pElementoUno=ll_get(this2,i);

				if(ll_contains(this, pElementoUno)==0)
				{
					returnAux=0;

					break;
				}
			}
		}

	    return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LinkedList* ll_subList(LinkedList* this, int from, int to)
{

	LinkedList* cloneArray = NULL;

	void* elementoAux;

	int len=ll_len(this);

	    if(this!= NULL && from >= 0 && to <= len)
	    {
	    	cloneArray=ll_newLinkedList();

	    	for (int i=from; i<to; i++)
	    	{
	    		elementoAux=ll_get(this,i);

	    		ll_add(cloneArray,elementoAux);
	    	}
	    }

	    return cloneArray;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LinkedList* ll_clone(LinkedList* this)
{

	LinkedList* cloneArray = NULL;

	void* elementoAux;

	int len= ll_len(this);

	    if(this!= NULL && len > 0)
	    {
	    	cloneArray=ll_newLinkedList();

	    	for (int i=0;i<len;i++)
	    	{
	    		elementoAux=ll_get(this, i);

	    		ll_add(cloneArray, elementoAux);
	    	}
	    }

	    return cloneArray;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{

    int returnAux =-1;

    int i;

    int flagSwap=1;

    int len =ll_len(this);

    void *pElementoUno;

    void *pElementoDos;

    	if (this!=NULL && pFunc!=NULL)
    	{
    		if(order == 0 || order == 1)
    		{
    			if(len>=2)
    			{
    				while(flagSwap==1)
    				{
    					flagSwap=0;

    					for(i=0;i<=len;i++)
    					{
    						pElementoUno=ll_get(this,i);

    						pElementoDos=ll_get(this,i+1);

    						if(pElementoUno!= NULL && pElementoDos!= NULL)
    						{
    							if (order == 1)
    							{
    								if(pFunc(pElementoUno, pElementoDos)>0)
    								{
    									ll_set(this, i, pElementoDos);

    									ll_set(this, i+1, pElementoUno);

    									flagSwap=1;
    								}
    							}
    							else
    							{
    								if(order==0)
    								{
    									if(pFunc(pElementoUno, pElementoDos)<0)
    									{
    										ll_set(this, i, pElementoDos);

    										ll_set(this, i+1, pElementoUno);

    										flagSwap=1;
    									}
    								}
    							}
    						}
    					}
    				}

    				returnAux=0;
    			}
    			else
    			{
    				returnAux=0;
    			}
    		}
    	}

        return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Extras:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ll_map (LinkedList* this, int (*pFunc)(void*))
{
	int returnAux=-1;

	void* aux;

	if(this!=NULL && pFunc!=NULL)
	{
		for(int i=0; i<ll_len(this); i++)
		{
			aux = ll_get(this, i);

			if(aux!=NULL)
			{
				if(pFunc(aux)==0)
				{
				returnAux=0;
				}
			}
		}
	}

	return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))  //ya clona y devuelve una lista con el filtro hecho.
{
	//int returnAux = -1;

	int retornoFuncionCriterio;

	void* pListaOriginal;

	LinkedList* listaFiltrada = NULL;

	if(this!=NULL && pFunc !=NULL)
	{
		listaFiltrada = ll_newLinkedList();

		if(listaFiltrada != NULL)
		{
			for(int i=0; i<ll_len(this); i++)
			{
				pListaOriginal = ll_get(this, i);

				retornoFuncionCriterio = pFunc(pListaOriginal);

				if(retornoFuncionCriterio == 0) //entidades que tienen cantidadJugadores>1
				{
					ll_add(listaFiltrada, pListaOriginal); //las guardo en la nueva lista de linkedlist (listaFiltrada)
				}
			}
		}
	}

	return listaFiltrada;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
