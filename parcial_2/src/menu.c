
#include "menu.h"

//PROTOTIPOS STATICS:



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int menu_mainMenu(LinkedList* list, LinkedList* listJuegos, LinkedList* listMultijugador) //FUNCION PRINCIPAL DEL MENU:
{

int opcionIngresadaPorUser;

int estado= -1;


	do{

		puts("\n-----Sistema de menu: por favor elija una opcion:------\n");

		puts("1. INCORPORAR ARCADE.\n");
		puts("2. MODIFICAR ARCADE. \n");
		puts("3. ELIMINAR ARCADE.\n");
		puts("4. IMPRIMIR ARCADES: Ordenados por nombre de juego.\n");
		puts("5. Generar archivo con JUEGOS (solo el nombre de los juegos, sin repetir). \n");
		puts("6. Generar un archivo: arcades “Multijugador” que contenga solo los juegos para mas de 1 jugador.\n");
		puts("7. Actualizar cantidad de fichas(Duplica la cantidad de la misma).\n");
		puts("8. SALIR.\n");

		if(utn_pedirInt(&opcionIngresadaPorUser, 1, 8, 3, "Escoja una opcion del menu:\n", "ERROR AL INGRESAR LA OPCION")==0)
		{
			estado=0;

			switch(opcionIngresadaPorUser)
			{
				case 1:  //1. ALTA ARCADE

					if(controller_addArcade(list)==0)
					{
						puts("Alta del ARCADE realizada con exito");

						if(controller_saveAsText("arcades.csv", list)==0)
						{
							puts("Archivo actualizado.\n");
						}
						else
						{
							puts("Error al actualizar el archivo.");
						}
					}
					else
					{
						puts("Error al realizar el alta de Arcade.");
					}

					break;

				case 2:  //MODIFICAR ARCADE

						controller_ListArcade(list);

						if(controller_editArcade(list)==0)
						{
							puts("modificacion del Arcade realizada con exito.\n");

							if(controller_saveAsText("arcades.csv", list)==0)
							{
								puts("Archivo actualizado.\n");
							}
							else
							{
								puts("Error al actualizar el archivo.");
							}
						}
						else
						{
							puts("Error al realizar la modificacion del Arcade.\n");
						}

						break;

				case 3:  //3.BAJA ARCADE

					if(controller_ListArcade(list)==0)
					{
						if(controller_removeArcade(list)==0)
						{
							puts("baja del Arcade realizada con exito.\n");

							if(controller_saveAsText("arcades.csv", list)==0)
							{
								puts("Archivo actualizado.\n");
							}
							else
							{
								puts("Error al actualizar el archivo.");
							}
						}
						else
						{
							puts("error al realizar la baja del Arcade.\n");
						}
					}

					break;

				case 4: //4 ORDENAR E IMPRIMIR

					if(controller_sortArcadeForName(list)!=-1)
					{
						if(controller_ListArcade(list)==0)
						{
							puts("\nLista ordenada por nombre de juegos completada!\n");
						}
					}

					break;

				case 5: //5 Generar archivo con JUEGOS (solo el nombre de los juegos, sin repetir).

					if(juegos_saveGamesFromText("juegos.txt", list)!= -1)
					{
						puts("Archivo de juegos (sin repetir) creado correctamente.\n");
					}
					else
					{
						puts("Error al generar el archivo de texto para juegos (sin repetir).\n");
					}

					break;

				case 6: //6 Generar un archivo: arcades “Multijugador” que contenga solo los juegos para mas de 1 jugador. (FILTER)

						listMultijugador = ll_filter(list, arcade_esMultijugadorFilter); //arreglar.

						if(listMultijugador !=NULL)
						{
							//if(juegos_saveAsText("multijugador.csv", listMultijugador)==0)  //no hace falta usar nueva funcion xq el archivo tiene que tener las mismas caracteristicas q el de arcade.

							if(controller_saveAsText("multijugador.csv", listMultijugador)==0)	//LO GUARDO EN EL ARCHIVO. (al ser nuevo, va a generarse un txt nuevo.)
							{
								puts("Creando archivo de arcades multijugador.\n");
							}
							else
							{
								puts("Error al guardar actualizar el archivo.\n");
							}
						}

					break;

				case 7:   //7 Actualizar cantidad de fichas(Duplica la cantidad de la misma).

					if (ll_map(list, arcade_multiplicarFichasMap)==0)  //actualiza la cantidad de fichas.
					{
						if(controller_saveAsText("arcades.csv", list)==0)  //LO GUARDO EN EL ARCHIVO.
						{
							puts("Actualizando capacidad de fichas en el archivo correctamente.\n");
						}
						else
						{
							puts("Error al guardar actualizar el archivo.\n");
						}
					}
					else
					{
						puts("Error al realizar el mappeo de fichas.\n");
					}

					break;

				case 8:   //bye byee!

					puts("bye byee!\n");

					break;

			}         //final del switch
		}            //final if para elegir opcion

		}while(opcionIngresadaPorUser!=8);

	return estado;
}

