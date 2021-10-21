/*
 * salon.c
 *
 *  Created on: 17 oct. 2021
 *      Author: Joa


 1) ALTA DE SAL�N
Se deber� dar de alta un sal�n con los siguientes datos: Nombre, direcci�n y tipo.
Se generar� un ID �nico para gestionar los SALONES.
Este sal�n se imprimir� por pantalla si el alta es correcta.

2) ELIMINAR SAL�N
Se imprime la lista de salas listando ID, nombre y direcci�n.
Se ingresa un ID y la misma generar� la baja del sal�n, junto con todos los arcades que lo componen.

3) IMPRIMIR SALONES
Se imprime la lista completa de salas con todos sus datos. Nombre, direcci�n y tipo.

 */



#include "salon.h"

//PROTOTIPOS STATICS:

static int GenerarIdNuevoSalon(void);


//__________________________________________________________________________________________________________________________________
//CODIGOS:
//__________________________________________________________________________________________________________________________________



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PRIMER PASO:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que inicializa el array de entidad y modifica el campo ISEMPTY en 1, que significa que esta libre para usar.
* \ param puntero del array entidad.
* * \ param tama�o del puntero array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int sal_initSalones(Salones* list, int len)
{
	int estado= -1;

	int i;

	if(list!=NULL && len>0)
	{
		estado=0;

		for(i=0;i<len;i++)
		{
			list[i].isEmpty=LIBRE; //libre
		}
	}

	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ALTA:[findEmpty,addEmployee(con arrayList[return de findEmpty],GenerarIdNuevo(dentro del ADD) LISTO LISTO PEOLA
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que busca, a traves de un for que recorre el array de entidad, las posiciones ISEMPTY iguales a 1 (libres)
* \ param puntero del array entidad.
* * \ param tama�o del puntero array entidad.
* \ return retorna[-1]ERROR o la direccion de memoria del primer array con posicion libre que encuentre.
*/

int sal_findEmpty(Salones list[],int len)
{
	int i;
	int indexLibre=-1;
if (list!=NULL && len>0)
{
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==LIBRE)   //vacio
		{
			indexLibre =i;
			break;
		}
	}
 }
	return indexLibre; //retorno la posicion libre
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que le pide los datos al usuario y los carga, mediante auxiliares que si pasan el testeo y dan todo OK, se igualan a los campos reales del puntero ARRAY entidad.
* \ param puntero del array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*
* char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	int isEmpty;     //0 OCUPADO       //1 LIBRE
	int idSalon;     //0 =  SHOPPING     1=LOCAL
	int tipo;
*/

int sal_altaSalon(Salones* list)
{
	int retorno=-1;
	char auxNombre[NOMBRE_LEN];
	char auxDireccion[DIRECCION_LEN];
	int auxTipo;


	if(list!=NULL)
		{
			if(utn_pedirTexto(auxNombre, NOMBRE_LEN,3, "Ingrese el nombre del SALON \n", "Error\n")==0)
			{
				if(utn_pedirTexto(auxDireccion,DIRECCION_LEN,3,"ingrese la direccion del SALON \n ","error")==0)
				{
						if(utn_pedirInt(&auxTipo,0,1,3,"Ingrese con un valor numerico el TIPO de salon a crear: (0)SHOPPING  (1)LOCAL  \n","error\n")==0)
						{
							strncpy(list->nombre,auxNombre,sizeof(list->nombre));
							strncpy(list->direccion,auxDireccion,sizeof(list->direccion));
							list->tipo = auxTipo;
							list->idSalon = GenerarIdNuevoSalon();	 //genero id UNICO
							list->isEmpty = OCUPADO; //OCUPADO
							retorno=0; // bien
						}
				}
		    }
		}

	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que genera mediante un contador que incrementa, un ID nuevo y unico.
* \ param VOID
* \ return retorna el valor del contador (el id)
*/

static int GenerarIdNuevoSalon(void)
{
	static int contador=0;

	return contador++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//BAJA:[utn_imprimirPantalla, PedirId(utn_pedirInt), utn_findEmployeeById, funcionBajaLogica, utn_imprimirPantalla]
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que imprime las posiciones del array que ESTEN OCUPADAS, osea que su ISEMPTY sea igual a 0.
* \ param puntero del array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int sal_imprimirSalones(Salones* pList)
{
	int estado;

	if(pList->isEmpty ==OCUPADO)
	{
		printf("\n NOMBRE: %s   -   DIRECCION:  %s   -   TIPO: %d   -    ID SALON: %d   - \n" ,pList->nombre,pList->direccion,pList->tipo,pList->idSalon);

		estado = 0;
	}
	else
	{
		estado = -1;
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que, mediante la funcion input de pedir INT, le pide un ID al usuario, el cual luego, mediante otra funcion, buscara a un salon con ese ID ingresado.
* \ param puntero del id donde quiero guardar el ID que ingrese el usuario.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int sal_pedirIdSalonAlUsuario(int* id)
{
	int idAux;
	int estado=-1;

	if(utn_pedirInt(&idAux,0,100,3,"ingrese el ID del SALON a buscar\n","ERROR\n")==0)
	{
		estado=0;
		*id=idAux;
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que busca un salon especifico dentro del array mediante su campo de ID ingresado en la funcion de pedir id al usuario.
* \ param
* \ param
* \param
* \ return retorna[-1]ERROR o RETORNA EL INDICE de donde el for encontro al id que coincide con el id del campo del array entidad.
*/

int sal_buscarSalonPorId(Salones* pList, int len, int id)
{
	int estado= -1;
	int i;

	if(pList!=NULL && len>=0 && id>=0)
	{
		for(i=0;i<len;i++)
		{
			if(pList[i].idSalon==id && pList[i].isEmpty==OCUPADO)
			{
				estado = i; //igualo el estado a la posicion donde se encontro el ID y despues lo retorno.
				break;
			}
		}
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
  \ brief funcion que realiza la baja de un salon, accediendo a su indice mediante la igualacion del ID, y le cambia al campo ISEMPTY el valor a 1 (libre nuevamente)
* \   param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

int sal_bajaSalones(Salones* list, int len, int id)
{
	int estado= -1;

	int indiceDelIdEncontrado;

	indiceDelIdEncontrado = sal_buscarSalonPorId(list,len,id);

	if(indiceDelIdEncontrado != -1)
	{
		estado=0;

		list[indiceDelIdEncontrado].isEmpty=LIBRE; //vacio
	}
	else
	{
		puts("error al buscar el ID");
	}

	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUX:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que carga los datos de manera forzada para hacer las pruebas del programa sin perder tiempo ingresando de manera manual.
* \ param
* * \ param
* * \ param
* \ return VOID
*/

void sal_altaForzada(Salones* list, int len, int indice, char* nombre, char* direccion, int tipo)
{
	if(list!=NULL && len>=0) //etc...tampoco sirve mucho xq yo cargo los datos correctos en el main.
	{
		list[indice].isEmpty = 0;
		list[indice].idSalon = GenerarIdNuevoSalon();
		strncpy(list[indice].nombre, nombre, NOMBRE_LEN);
		strncpy(list[indice].direccion, direccion, DIRECCION_LEN);
		list[indice].tipo = tipo;
	}
}

