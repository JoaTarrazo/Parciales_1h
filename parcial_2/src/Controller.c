#include "Controller.h"


static int modificarCantidadJugadores (int* pCantidadJugadores);


static int modificarNombreJuego (char pNombre[]);


static int opcionAModificar (int* opcion);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArcade)
{
    int estado = -1;

    FILE* pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
    	if(parser_ArcadeFromText(pFile, pArrayListArcade)==0)
    	{
    		estado = 0;
    	}
    	else
    	{
    		puts("error al cargar el archivo en modo TEXTO\n");
    	}

    	fclose(pFile);
    }

	return estado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addArcade(LinkedList* pArrayListArcade)
{
	int estado= -1;

	char auxId[68];
	char auxNacionalidad[LEN_NACIONALIDAD];
	char auxTipoSonido[68];
	char auxCantidadJugadores[68];
	char auxCapacidadFichas[68];
	char auxSalon[LEN_SALON];
	char auxJuego[LEN_JUEGO];

	int idInt;
	int tipoSonidoInt;
	int cantidadJugadoresInt;
	int capacidadFichasInt;

	Arcade* nuevoArcade;

	if(pArrayListArcade!=NULL)
	{
			if(utn_pedirTexto(auxNacionalidad, LEN_NACIONALIDAD, 3, "Ingrese la nacionalidad de su ARCADE \n", "Error al ingresar la nacionalidad.\n")==0)
			{
				if(utn_pedirInt(&tipoSonidoInt, 0, 1, 3, "Ingrese el tipo de sonido de su ARCADE: (0) MONO / (1) ESTEREO \n", "Error al ingresar el tipo de sonido.\n")==0)
				{
					if(utn_pedirInt(&cantidadJugadoresInt, 1, 4, 3, "Ingrese la cantidad de jugadores para su ARCADE: (min 1 / max 4)\n", "Error al ingresar la cantidad de jugadores.\n")==0)
					{
						if(utn_pedirInt(&capacidadFichasInt, 1, 100, 3, "Ingrese la capacidad de fichas que tolera su ARCADE: (min 1 / max 100)\n", "Error al ingresar la capacidad de fichas.\n")==0)
						{
							if(utn_pedirTexto(auxSalon, LEN_SALON, 3, "Ingrese el nombre del salon donde colocara su ARCADE. \n", "Error al ingresar el salon.\n")==0)
							{
								if(utn_pedirTexto(auxJuego, LEN_JUEGO, 3, "Ingrese el nombre de su JUEGO para su ARCADE. \n", "Error al ingresar el juego.\n")==0)
								{
									idInt = arcade_generarIdMaximo(pArrayListArcade);

									if(idInt != -1)
									{
										sprintf(auxId,"%d",idInt);   // sprintf(VARIABLE CHAR DONDE VAS A METER ESE DATOS * , *%D , VARIABLE QUE QUERES TRANSFORMAR);

										sprintf(auxTipoSonido,"%d",tipoSonidoInt);

										sprintf(auxCantidadJugadores,"%d",cantidadJugadoresInt);

										sprintf(auxCapacidadFichas,"%d",capacidadFichasInt);

										nuevoArcade = arcade_newParametros(auxId,auxNacionalidad, auxTipoSonido, auxCantidadJugadores, auxCapacidadFichas, auxSalon, auxJuego); //Setea los valores que ingreso el usuario en un nuevo Empleado.

										if(nuevoArcade!=NULL)
										{
											ll_add(pArrayListArcade, nuevoArcade);  //lo agrego en la linkedList.

											estado=0;
										}
									}
								}
							}
						}
					}
				}
			}
		}

	return estado;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editArcade(LinkedList* pArrayListArcade)
	{
	    int estado = -1;

	    int idIngresado;

	    int opcionElegida;

	    int auxCantidadJugadores;

	    char auxJuego[LEN_JUEGO];

	    int idEncontrado;

	    Arcade* arcadeAux;

	    Arcade* arcadeAuxJuegos; //para el case 2 (mod juego) printear los juegos.

	    char auxJuegoPrintf[LEN_JUEGO]; //para el case 2 (mod juego) printear los juegos.

	    if (pArrayListArcade != NULL)
	    {
	    	if (utn_pedirInt(&idIngresado,0,1500, 3, "Ingrese el ID del ARCADE que desea modificar\n", "Error al ingresar el ID buscado\n.")==0)
	    	{
	    		if (arcade_findById(pArrayListArcade,idIngresado, &idEncontrado) != -1)
	    		{
	    			if(idEncontrado!= -1)
	    			{
						printf("ID buscado es: %d\n",idIngresado);

						arcadeAux = ll_get(pArrayListArcade, idEncontrado); //obtengo la direccion de memoria del arcade buscado y la guardo en arcadeAux (Arcade*)

						if (opcionAModificar(&opcionElegida)==0)
							{
								switch (opcionElegida)
								{
									case 1:

										if (modificarCantidadJugadores(&auxCantidadJugadores)==0)
										{
											puts("pude entrar a la opcion que desea modificar");

											if(arcade_setCantidadJugadores(arcadeAux, auxCantidadJugadores)==0)
											{
												puts("pude setear lo que me pasaste");

												estado=0;
											}
										}

										break;

									case 2:

										for(int i=0; i<ll_len(pArrayListArcade); i++)
										{

											arcadeAuxJuegos = ll_get(pArrayListArcade, i);

											arcade_getJuego(arcadeAuxJuegos, auxJuegoPrintf);

											printf("\n JUEGO: %s \n",auxJuegoPrintf);
										}

										if (modificarNombreJuego(auxJuego)==0)
										{
											puts("pude entrar a la opcion que desea modificar");
											if(arcade_setJuego(arcadeAux, auxJuego)==0)
											{
												puts("pude setear lo que me pasaste");
												estado=0;
											}
										}

										break;

								}//fin del switch
							}//fin del if opcion
	    				}
	    			}
	    		}
	    	}

		return estado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeArcade(LinkedList* pArrayListArcade)
{
	    int estado = -1;

	    int idElegido;

	    Arcade* auxArcade;

	    int idEncontrado;

	    int seguridad;

	    if(pArrayListArcade != NULL)
	    {
	        if(utn_pedirInt(&idElegido, 0, 1500, 3, "\n Escoja el id del ARCADE a ELIMINAR\n", "\n error al escojer un ID valido\n")==0)
	        {
			   if(arcade_findById(pArrayListArcade, idElegido, &idEncontrado)==0)
			   {
					if(idEncontrado != -1)
					{
						if(utn_pedirInt(&seguridad, 0, 1, 3, "Esta seguro que desea eleminar el ID ingresado (0) SI / (1) NO ?\n", "Error al ingrsar la opcion\n")==0)  //pregunto al user si esta seguro de eliminar el arcade.
						{
							if(seguridad==0)
							{
								auxArcade = ll_get(pArrayListArcade, idEncontrado);

								arcade_delete(auxArcade, pArrayListArcade, idEncontrado);

								estado = 0;
							}
						}
					}
			   }
	        }
	    }

	    return estado;
	}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListArcade(LinkedList* pArrayListArcade)
{
	int estado = -1;

	Arcade* auxArcade;

	if(pArrayListArcade!=NULL)
	{
		int lenList = ll_len(pArrayListArcade);

		for(int i=0; i<lenList; i++)
		{
			auxArcade = ll_get(pArrayListArcade, i);

			if(arcade_imprimirArcade(auxArcade)==0)
			{
				estado = 0;
			}
		}
	}

    return estado;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortArcadeForName(LinkedList* pArrayListArcade)
{
	int estado = -1;

	int lenList;

	int opcion;

	lenList = ll_len(pArrayListArcade);

	if(pArrayListArcade!=NULL &&  lenList>0)
	{
		if(utn_pedirInt(&opcion, 0, 1, 3, "Ingrese 0: si desea ordenar de forma ascendente o 1: forma descendente.\n", "Error al elegir la opcion")==0)
		{
			estado = ll_sort(pArrayListArcade, arcade_sortArcadeForGame, opcion);

			printf("estado vale: %d", estado);
		}
	}

	return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListArcade)
 {

	int estado= -1;

	Arcade* pArcadeAux = arcade_new();

	int idAux;

	char auxNacionalidad[LEN_NACIONALIDAD];

	int auxTipoSonido;

	int auxCantidadJugadores;

	int auxCapacidadFichas;

	char auxSalon[LEN_SALON];

	char auxJuego[LEN_JUEGO];

	FILE* f = fopen(path,"w");

	if(f!=NULL)
	{
		fprintf(f,"ID, Nacionalidad, Tipo sonido, Cantidad jugadores, Capacidad fichas, Salon, Juego \n");

		for(int i=0; i<ll_len(pArrayListArcade); i++)
		{
			pArcadeAux = ll_get(pArrayListArcade,i);

			if(pArcadeAux!=NULL)
			{
				arcade_getId(pArcadeAux,&idAux);

				arcade_getNacionalidad(pArcadeAux, auxNacionalidad);

				arcade_getTipoSonido(pArcadeAux,&auxTipoSonido);

				arcade_getCantidadJugadores(pArcadeAux,&auxCantidadJugadores);

				arcade_getCapacidadFichas(pArcadeAux,&auxCapacidadFichas);

				arcade_getSalon(pArcadeAux, auxSalon);

				arcade_getJuego(pArcadeAux, auxJuego);

				fprintf(f,"%d, %s, %d, %d, %d, %s, %s \n",idAux,auxNacionalidad,auxTipoSonido, auxCantidadJugadores, auxCapacidadFichas, auxSalon, auxJuego);

				estado=0;
			}
		}
			fclose(f);
	}
		return estado;
 }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SOLO JUEGOS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

int controller_saveAsTextJuegos(char* path , LinkedList* pArrayListArcadeJuegos) //ADAPTAR A UN SOLO CAMPO (NOMBRE JUEGO)
 {

	int estado= -1;

	Arcade* pArcadeAuxJuego = arcade_new();

	char auxJuego[LEN_JUEGO];

	FILE* f = fopen(path,"w");

	if(f!=NULL)
	{
		fprintf(f,"JUEGOS: \n");

		for(int i=0; i<ll_len(pArrayListArcadeJuegos); i++)
		{
			pArcadeAuxJuego = ll_get(pArrayListArcadeJuegos,i);

			if(pArcadeAuxJuego!=NULL)
			{
				arcade_getJuego(pArcadeAuxJuego, auxJuego);

				fprintf(f,"%s\n",auxJuego);

				estado=0;
			}
		}
			fclose(f);
	}

		return estado;
 }

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EXTRAS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int opcionAModificar (int* opcion)
{
	int estado = -1;

	int opcionElegida;

	puts("A continuacion, debe escoger que campo desea modificar:\n");
	puts("1. Cantidad de jugadores:");
	puts("2. Nombre del juego.");


	if (utn_pedirInt(&opcionElegida,1,2,3, "\nSeleccion una opcion para modificar:\n", "Error al escojer la opcion")==0)
	{
		 *opcion = opcionElegida; //igualo la opcion que eligieron a la opcion Puntero que voy a mandar.

		 estado = 0;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int modificarNombreJuego (char pNombre[])
{
	int estado = -1;

	char auxNombreJuego[LEN_JUEGO];

	if (utn_pedirTexto(auxNombreJuego, LEN_JUEGO, 3, "Ingrese el nuevo nombre del juego:\n", "Error al ingresar el nuevo nombre del juego") == 0)
	{
		estado = 0;

		strncpy(pNombre, auxNombreJuego, LEN_JUEGO);
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int modificarCantidadJugadores (int* pCantidadJugadores)
{
	int estado = -1;

	int auxCantidadJugadores;

	if (utn_pedirInt(&auxCantidadJugadores,1,4,3, "Ingrese la nueva cantidad de jugadores para su ARCADE:\n", "Error al ingresar la cantidad de jugadores nueva.\n")== 0)
	{
		estado = 0;

		*pCantidadJugadores = auxCantidadJugadores;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
