/*
 * arcade.c
 *
 *  Created on: 17 oct. 2021
 *      Author: Joa


 4) INCORPORAR ARCADE
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
fichas, ID del salón al que pertenece (Validar que exista) y nombre del juego que contiene (hasta 63 caracteres). 1. le muestro lista de salones al user 2. le pido q ingrese el id, 3. busco el salon por el buscarId, ese numero lo guardo en una variable y se lo paso al idSalon del ARCADE.
Se generará un ID único para gestionar los ARCADE.

5) MODIFICAR ARCADE
Se imprime la lista de arcades con los ID y datos que lo componen.                                           //imprimir arcade
Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.    //id del arcade
Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya   //(if(isEmpty==0){ for(i=0;i<arcade_len;i++) printf(\n Juego: %s\n, pList[i]->nombre)
cargados en el sistema y se permitirá ingresar un texto con el nombre del nuevo juego.

6) ELIMINAR ARCADE
Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la información del salón y el
juego que contiene.
Se ingresa un ID y previo a dar de baja se deberá solicitar confirmación, imprimiendo el arcade a dar de baja y
confirmando si está seguro dar de baja esté mismo.

7) IMPRIMIR ARCADES
Se imprime la lista de arcades con ID, y sus datos.

8) IMPRIMIR JUEGOS
Se imprime la lista de juegos que contienen todos los arcades sin repetir

 */

#include "arcade.h"

//PROTOTIPOS STATICS:

static int GenerarIdNuevoArcade(void);


//__________________________________________________________________________________________________________________________________
//CODIGOS:
//__________________________________________________________________________________________________________________________________



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PRIMER PASO:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que inicializa el array de entidad y modifica el campo ISEMPTY en 1, que significa que esta libre para usar.
* \ param puntero del array entidad.
* * \ param tamaño del puntero array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int arc_initArcades(Arcades* list, int len)
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
* * \ param tamaño del puntero array entidad.
* \ return retorna[-1]ERROR o la direccion de memoria del primer array con posicion libre que encuentre.
*/

int arc_findEmptyArcade(Arcades list[],int len)
{
	int i;
	int indexLibre=-1;
if (list!=NULL && len>0)
{
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==LIBRE)//vacio
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
*
* 4) INCORPORAR ARCADE
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
fichas, ID del salón al que pertenece (Validar que exista) y nombre del juego que contiene (hasta 63 caracteres).
Se generará un ID único para gestionar los ARCADE.

1. le muestro lista de salones al user
2. le pido q ingrese el id
3. busco el salon por el buscarId, ese numero lo guardo en una variable y se lo paso al idSalon del ARCADE.
*
*
*/

int arc_altaArcade(Arcades* list, Salones* listSalon, int lenSalon)
{
	int retorno=-1;
	char auxNacionalidad[NACIONALIDAD_LEN];
	char auxNombre[NOMBRE_LEN];
	int auxTipo;
	int auxCantidadJugadores;
	int auxCapacidadFichas;

	int idDelSalonElegido;
	int indiceDelIdSalonElegido;

	if(list!=NULL)
		{
			for(int i=0; i < lenSalon; i++)
			{
				if(listSalon[i].isEmpty == OCUPADO)
				{
					sal_imprimirSalones(&listSalon[i]); //le muestro los salones en ALTA para que el user elija en cual poner su arcade
				}
			}

				puts("escoja un ID del SALON en donde quiera incorporar su ARCADE");

				if(sal_pedirIdSalonAlUsuario(&idDelSalonElegido)==0)
				{
					indiceDelIdSalonElegido = sal_buscarSalonPorId(listSalon, lenSalon,idDelSalonElegido);

					while(indiceDelIdSalonElegido == -1)
					{
						puts("ERROR, escoja un ID del SALON en donde quiera incorporar su ARCADE");
						sal_pedirIdSalonAlUsuario(&idDelSalonElegido);
						indiceDelIdSalonElegido = sal_buscarSalonPorId(listSalon, lenSalon,idDelSalonElegido);
					}

					list->idSalon=idDelSalonElegido;
					puts("Arcade asociado al salon correctamente");
				}

			if(utn_pedirTexto(auxNacionalidad, NACIONALIDAD_LEN ,3, "Ingrese la nacionalidad del ARCADE \n", "Error\n")==0)
			{
				if(utn_pedirTexto(auxNombre,NOMBRE_LEN,3,"ingrese el nombre del juego del ARCADE \n ","error")==0)
				{
					if(utn_pedirInt(&auxTipo,0,1,3,"Ingrese con valor NUMERICO el tipo de audio del ARCADE:  (0):MONO  (1): ESTEREO \n","error\n")==0)
					{
						if(utn_pedirInt(&auxCantidadJugadores,1,4,3,"Ingrese la cantidad maxima de jugadores para el ARCADE(1 minimo - 4 maximo) \n","error\n")==0)
						{
							if(utn_pedirInt(&auxCapacidadFichas,1,100,3,"Ingrese la cantidad maxima de FICHAS para el ARCADE(1 minima - 100 maxima) \n","error\n")==0)
							{
								strncpy(list->nacionalidad,auxNacionalidad,sizeof(list->nacionalidad));
								strncpy(list->nombre,auxNombre,sizeof(list->nombre));
								list->tipo = auxTipo;
								list->cantidadJugadores =auxCantidadJugadores;
								list->idArcade=GenerarIdNuevoArcade();
								list->isEmpty=0;
								retorno=0; // bien
							}
						}
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

static int GenerarIdNuevoArcade(void)
{
	static int contador=0;

	return contador++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MODIFICACION [utn_imprimirPantalla, pedirID(utn_pedirInt), utn_findEmployeeById, utn_menu(subMenu Switch para elegir que campo modificar),ADDEmployee, utn_imprimirPantalla]
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que imprime las posiciones del array que ESTEN OCUPADAS, osea que su ISEMPTY sea igual a 0.
* \ param puntero del array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int arc_imprimirArcade(Arcades* pList, int len)
{
	int estado =-1;

	if(pList!=NULL && len>=0)
	{
		for(int i; i<len; i++)
		{
			if(pList[i].isEmpty ==OCUPADO)
			{
				printf("\n NACIONALIDAD: %s  -   NOMBRE DEL JUEGO: %s  -   TIPO DE SONIDO: %d  -   CANTIDAD DE JUGADORES: %d   -   CAPACIDAD DE FICHAS: %d   -   ID ARCADE: %d  -   ID SALON AL QUE PERTENECE: %d  - \n" ,pList[i].nacionalidad,pList[i].nombre,pList[i].tipo,pList[i].cantidadJugadores, pList[i].capacidadFichas , pList[i].idArcade, pList[i].idSalon);

				estado = 0;
			}
		}
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que, mediante la funcion input de pedir INT, le pide un ID al usuario, el cual luego, mediante otra funcion, buscara a un arcade con ese ID ingresado.
* \ param puntero del id donde quiero guardar el ID que ingrese el usuario.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int arc_pedirIdAlUsuarioArcade(int* id)
{
	int idAux;
	int estado=-1;

	if(utn_pedirInt(&idAux,0,1000,3,"ingrese el ID del ARCADE a buscar:\n","ERROR\n")==0)
	{
		estado=0;
		*id=idAux;
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que busca un arcade especifico dentro del array mediante su campo de ID ingresado en la funcion de pedir id al usuario.
* \ param puntero del array entidad.
* \ param tamaño del array.
* \param id que ingreso el usuario en la anterior funcion.
* \ return retorna[-1]ERROR o RETORNA EL INDICE de donde el for encontro al id que coincide con el id del campo del array entidad.
*/

int arc_findArcadeById(Arcades* pList, int len, int id)
{
	int estado= -1;
	int i;

	if(pList!=NULL && len>0 && id>0)
	{
		for(i=0;i<len;i++)
		{
			if(pList[i].idArcade==id && pList[i].isEmpty==OCUPADO)
			{
				estado = i; //igualo el estado a la posicion donde se encontro el ID y despues lo retorno.
				break;
			}
		}
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//BAJA:[utn_imprimirPantalla, PedirId(utn_pedirInt), utn_findEmployeeById, funcionBajaLogica, utn_imprimirPantalla]
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que realiza la baja de un empleado, accediendo a su indice mediante la igualacion del ID, y le cambia al campo ISEMPTY el valor a 1 (libre nuevamente)
* \ param puntero del array entidad.
* * \ param tamaño del array entidad.
* * \ param id ingresado por el usuario para buscar al cliente a dar de baja.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int arc_removeArcade(Arcades* list, int len, int id)
{
	int estado= -1;

	int indiceDelIdEncontrado;

	indiceDelIdEncontrado = arc_findArcadeById(list,len,id);

	if(indiceDelIdEncontrado!=-1)
	{
		estado=0;

		int respuesta;

		utn_pedirInt(&respuesta, 0, 1, 3, "Estas seguro que desea realizar la baja? (0)=SI  (1)=NO", "ERROR en la opcion elegida");

		if(respuesta==0)
		{
		list[indiceDelIdEncontrado].isEmpty=1; //vacio
		}
		else
		{
			puts("BAJA CANCELADA");
			estado = -1;
		}
	}
	else
	{
		puts("error al buscar el ID");
	}

	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EXTRAS:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que imprime los juegos de un arcade sin repetir los nombres, mediante la funcion strcmp que detecta los campos de texto iguales.
* \ param
* * \ param
* * \ param
* \ return VOID
*/

int arc_imprimirJuegos(Arcades* list, int len)
{
	int estado = -1;
	int flag;  // 0: no se repitieron    -1: se repitieron

	if(list != NULL && len > 0)
	{
		estado = 0;

		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				flag = 0; //reinicio la flag a NO REPETIDOS

				for(int e = i+1; e < len; e++)
				{
					if(strcmp(list[i].nombre, list[e].nombre) == 0)
					{
						flag = -1; //si se repiten, EN ESTA ITERACION, la flag queda en -1 y no imprime el juego (esta repetido)
					}
				}

				if(flag == 0)
				{
					printf("\n JUEGO:  - %s -\n",list[i].nombre);
				}
			}
		}
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

void arc_altaForzada(Arcades* list, int len, int indice, char* nacionalidad, int tipo, int cantidadJugadores, int capacidadFichas, int idSalon, char* nombre)
{

	if(list!=NULL && len>=0 && indice>=0)
	{
		list[indice].isEmpty = 0;
		list[indice].idArcade = GenerarIdNuevoArcade();
		strncpy(list[indice].nacionalidad, nacionalidad, NACIONALIDAD_LEN);
		list[indice].tipo = tipo;
		list[indice].cantidadJugadores = cantidadJugadores;
		list[indice].capacidadFichas = capacidadFichas;
		list[indice].idSalon = idSalon;
		strncpy(list[indice].nombre, nombre, NOMBRE_LEN);
	}
}

