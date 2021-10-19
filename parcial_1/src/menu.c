/*
 * menu.c
 *
 *  Created on: 17 oct. 2021
 *      Author: Joa
 *
 *

 1) ALTA DE SAL�N
Se deber� dar de alta un sal�n con los siguientes datos: Nombre, direcci�n y tipo.
Se generar� un ID �nico para gestionar los SALONES.
Este sal�n se imprimir� por pantalla si el alta es correcta.

2) ELIMINAR SAL�N
Se imprime la lista de salas listando ID, nombre y direcci�n.
Se ingresa un ID y la misma generar� la baja del sal�n, junto con todos los arcades que lo componen.

3) IMPRIMIR SALONES
Se imprime la lista completa de salas con todos sus datos. Nombre, direcci�n y tipo.

4) INCORPORAR ARCADE
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad m�xima de
fichas, ID del sal�n al que pertenece (Validar que exista) y nombre del juego que contiene (hasta 63 caracteres).
Se generar� un ID �nico para gestionar los ARCADE.

 5) MODIFICAR ARCADE
Se imprime la lista de arcades con los ID y datos que lo componen.                                           //imprimir arcade
Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.    //id del arcade
Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya   //(if(isEmpty==0){ for(i=0;i<arcade_len;i++) printf(\n Juego: %s\n, pList[i]->nombre)
cargados en el sistema y se permitir� ingresar un texto con el nombre del nuevo juego.

6) ELIMINAR ARCADE
Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la informaci�n del sal�n y el
juego que contiene.
Se ingresa un ID y previo a dar de baja se deber� solicitar confirmaci�n, imprimiendo el arcade a dar de baja y
confirmando si est� seguro dar de baja est� mismo.

7) IMPRIMIR ARCADES
Se imprime la lista de arcades con ID, y sus datos.

8) IMPRIMIR JUEGOS
Se imprime la lista de juegos que contienen todos los arcades sin repetir
 */



#include "menu.h"



//PROTOTIPOS STATICS:
static int selecCampoModificar (int* campoSeleccionado);
static void mostrarCampos (void);
static int obtenerCantidadJugadores (int* NuevacantidadJugadores);
static int obtenerNombre (char* nuevoNombreDelJuego);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
  \ brief funcion que engloba las subfunciones para la MODIFICACION: 1. imprime la pantalla, 2. le pide un id al usuario y 3. busca segun su id para luego 4. ingresar a un submenu que pregunta al usuario que campo especifico desea modificar, y por ultimo vuelve a imprimir la pantalla con los cambios realizados.
* \ param puntero del array entidad.
* * \ param tama�o del array entidad.
* \ return VOID
*/
void menu_modificarMenuArcade(Arcades* list , int len)
{
	int idElegido; //el id elegido en la funcion pedirIdAlUsuario
	int indexDelId; //indice del array donde esta el ID elegido

	if(list!=NULL && len>=0)
	{

		if (arc_pedirIdAlUsuarioArcade(&idElegido) == 0)  // 1) pedirle al usuario que ingrese un id
		{
			indexDelId = arc_findArcadeById (list,len,idElegido);  // 2) hacer funcion q busque por id (en donde ESTA ocupada la posicion)

					if(indexDelId != -1 )
					{
						menu_modificarOpcionesArcade(&list[indexDelId], len); // 3) llamar a funcion q modifica el campo en especifico
					}
		}
	}
}

/*
  \ brief funcion que realiza, mediante funciones STATIC (para evitar que el cliente deba modificar TODOS los campos a la hora de hacer la modificacion) pregunta que campo desea modificar el usuario y lo cambia.
* \ param puntero del array entidad..
* \ return retorna[-1]ERROR o [0]EXITO
*/

int menu_modificarOpcionesArcade(Arcades* list, int lenArcade)
{
	int estado = -1;
	int campoModificado; //1:CANTIDAD D JUGADORES 2:NOMBRE DEL JUEGO

	int auxCantidadJugadores;
	char auxNombre[NOMBRE_LEN];

	if (list != NULL)
	{
		if (selecCampoModificar(&campoModificado) == 0)
		{
			estado = 0; //eligio bien entre las opciones 1 y 2

			switch (campoModificado)
			{
				case 1:

					if (obtenerCantidadJugadores(&auxCantidadJugadores) == 0)
					{
						list->cantidadJugadores = auxCantidadJugadores;
					}
					break;

				case 2:

						for(int i=0;i<lenArcade;i++)
						{
							if(list[i].isEmpty == OCUPADO)
							{
								printf("\n JUEGO: %s \n",list[i].nombre);
							}
						}

						if (obtenerNombre(auxNombre) == 0)
						{
							strncpy(list->nombre,auxNombre,sizeof(list->nombre));
						}

					break;
			}//switch
		}
	}

	return estado;
}

/*
  \ brief funcion STATIC que simplemente despliega mediante la subFuncion selecCampoModificar un submenu y le da la opcion al user a elegir cual campo cambiar mediante un getINT.
* \ param puntero que se utiliza para cargar la opcion elegida del usuario hacia fuera de la funcion mediante referencia.
* \ return retorna[-1]ERROR o [0]EXITO
*/
static int selecCampoModificar (int* campoSeleccionado)
{
	int estado = -1;
	int auxCampoSeleccionado;

	mostrarCampos(); //funcion que muestra los campos a modificar:

	if (utn_pedirInt(&auxCampoSeleccionado,1,2,3,"\nElegi una opcion para modificar\n","Error al elegir la opcion") == 0)
	{
		estado = 0;
		*campoSeleccionado = auxCampoSeleccionado;
	}
	else
	{
		puts("Eligio muchas veces una opcion incorrecta, por favor, reintentelo mas tarde");
	}
	return estado;
}

/*
  \ brief funcion STATIC que muestra por printfs un submenu de opciones de campo para modificar posteriormente.
* \ param VOID
* \ return VOID
*/
static void mostrarCampos (void)
{
	printf("\n 1: CANTIDAD DE JUGADORES:");
	printf("\n 2: NOMBRE DEL JUEGO:");
}

/*
  \ brief funcion STATIC que cambia el campo del array entidad SECTOR mediante un getINT.
* \ param puntero del valor ingresado por el usuario para su nuevo sector mediante referencia.
* \ return retorna[-1]ERROR o [0]EXITO
*/

static int obtenerCantidadJugadores (int* nuevacantidadJugadores)
{
	int estado = -1;
	int auxCantidadJugadores;
	if(utn_pedirInt(&auxCantidadJugadores,1,8,3,"Ingrese la cantidad de jugadores a modificar (1 minimo - 8 maximo)","Error") == 0)
	{
		estado = 0;
		*nuevacantidadJugadores = auxCantidadJugadores;
	}
	return estado;
}


/*
  \ brief funcion STATIC que cambia el campo del array entidad NAME mediante un getINT.
* \ param puntero del valor ingresado por el usuario para su nuevo nombre mediante referencia.
* \ return retorna[-1]ERROR o [0]EXITO
*/

static int obtenerNombre (char* nuevoNombreDelJuego)
{
	int estado = -1;
	char auxNombre[NOMBRE_LEN];


	if(utn_pedirTexto(auxNombre, sizeof(auxNombre),3, "Ingrese el nombre del juego nuevamente: ", "Error") == 0)
	{
		estado=0;

		strncpy(nuevoNombreDelJuego, auxNombre, 63);

	}
	return estado;
}


int menu_mainMenu(Salones* listSalon, Arcades* listArcade, int lenSalon, int lenArcade) //FUNCION PRINCIPAL DEL MENU:
{
	//MAIN:
	int estado=-1;
	int opcionIngresadaPorUser;

	//SALON:
	int contadorSalon=0;
	int posicionLibreEncontradaSalon;

	int idElegidoSalon;
	int indexABajarSalon;

	//ARCADE:

	//alta:
	int posicionLibreEncontradaArcade;
	int contadorArcade=0;
	//mod:
	int idElegidoArcade;
	int indexAModificarArcade;




	do{

		puts("-----BIENVENIDO-----");

		puts("---Sistema de menu: por favor elija una opcion:---");

		puts("1. ALTA de un Salon.");
		puts("2. BAJA de un Salon.");
		puts("3. IMPRIMIR salones.");
		puts("4. INCORPORAR Arcades.");
		puts("5. MODIFICAR arcades.");
		puts("6. ELIMINAR arcades.");
		puts("7. IMPRIMIR arcades.");
		puts("8. IMPRIMIR juegos.");
		puts("9. OPCIONES AVANZADAS:");
		puts("10. SALIR");

		if(utn_pedirInt(&opcionIngresadaPorUser, 1, 10, 3, "Escoja una opcion del menu:\n", "ERROR AL INGRESAR LA OPCION")==0)
		{
			estado=0;

			switch(opcionIngresadaPorUser)
			{
				case 1: //ALTA SALON

					posicionLibreEncontradaSalon = sal_findEmpty(listSalon, lenSalon);

					if(posicionLibreEncontradaSalon != -1)
					{
						if(sal_altaSalon(&listSalon[posicionLibreEncontradaSalon])==0)
						{
							sal_imprimirSalones(&listSalon[posicionLibreEncontradaSalon]);

							contadorSalon++; //alta con exito
						}
					}
					break;

				case 2: //BAJA SALON

					if(contadorSalon>0) //si hay un salon de alta para bajar....
					{
						for(int i=0; i<lenSalon;i++)
						{
							sal_imprimirSalones(&listSalon[i]);
						}

						if(sal_pedirIdSalonAlUsuario(&idElegidoSalon)!=-1)
						{
							indexABajarSalon = sal_buscarSalonPorId(listSalon, lenSalon, idElegidoSalon);

							if(indexABajarSalon != -1)
							{
								if(sal_bajaSalones(listSalon, lenSalon, indexABajarSalon)!=-1)
								{
									puts("Baja realizada con EXITO");
									contadorSalon--;
								}
							}
						}
					}
					break;

				case 3: //IMPRIMIR SALON
				{
					if(contadorSalon>0) //si hay un salon de alta para mostrar...
					{
						for(int j=0; j<lenSalon; j++)
						{
							sal_imprimirSalones(&listSalon[j]);
						}
					}
					break;
				}


				case 4: //ALTA ARCADE
				{
					if(contadorSalon>0)
					{
						posicionLibreEncontradaArcade = sal_findEmpty(listSalon, lenSalon);

						if(posicionLibreEncontradaArcade != -1)
						{
							if(arc_altaArcade(&listArcade[posicionLibreEncontradaArcade],listSalon ,lenSalon )==0)
							{
								puts("Alta realizada con Exito!");
								contadorArcade++;
							}
							else
							{
								puts("Error al dar el alta del arcade");
							}
						}
					}
					break;
				}

				case 5: //MODIFICAR ARCADE
				{
					puts("ARCADES EN USO ACTUALMENTE:");

						arc_imprimirArcade(listArcade, lenArcade);

					if (arc_pedirIdAlUsuarioArcade(&idElegidoArcade)!= -1)
					{
						indexAModificarArcade = arc_findArcadeById(listArcade, lenArcade, idElegidoArcade); //funcion me retorna el indice a modificar segun su id

						if(indexAModificarArcade!= -1)
							{
								menu_modificarMenuArcade(listArcade , lenArcade);
							}
					}
					break;
				}

				case 6: //BAJA ARCADE
				{
					if(contadorArcade>0)
					{

						arc_imprimirArcade(listArcade, lenArcade);
						puts("---------------- Arcade en uso actualmente ----------------------");

						}
							int idABajarArcade;
							int indexABajarArcade;

								if(arc_pedirIdAlUsuarioArcade(&idABajarArcade)==0)
								{
									indexABajarArcade= arc_findArcadeById(listArcade, lenArcade, idABajarArcade);

									if(indexABajarArcade!= -1)
									{
										puts("La baja del ARCADE corresponde al salon:");

										int idSalonAsociado = listArcade[indexABajarArcade].idSalon;

										int indiceDelSalonAsociado = sal_buscarSalonPorId(listSalon, lenSalon, idSalonAsociado);

										if(indiceDelSalonAsociado!= -1)
										{
											sal_imprimirSalones(&listSalon[indiceDelSalonAsociado]);
										}

										if(arc_removeArcade(listArcade, lenArcade, idABajarArcade)!= -1)
										{
											puts("BAJA de arcade realizada con exito");
											contadorArcade--;
										}
										else
										{
											puts("ERROR");
										}
									}

					}
					break;
				}

				case 7:
				{
					if(contadorArcade>0)
					{
						arc_imprimirArcade(listArcade, lenArcade);
					}
					break;
				}

				case 8:
				{
					if(contadorArcade>0)
					{
						if(arc_imprimirJuegos(listArcade, lenArcade)!=0)
						{
							puts("Error al imprimir los juegos");
						}
					}
					break;
				}

				case 9:
				{
					puts("1. Lista de los salones con m�s de 4 arcades");
					puts("2. Lista de los arcades para m�s de 2 jugadores");
					puts("3. Lista de toda la informaci�n de un sal�n en espec�fico ");
					puts("4. Lista de todos los arcades de un sal�n determinado");
					puts("5. Imprimir el sal�n con m�s cantidad de arcades");
					puts("6. Imprimir el monto m�ximo en pesos que puede recaudar un sal�n segun su capacidad de fichas");
					puts("7. Ingresar el nombre de un juego y ver cuantos arcades lo contienen");
					puts("8. Salir de opciones avanzadas");

					int subMenuOpcion;

				if(utn_pedirInt(&subMenuOpcion, 1, 8, 3, "Escoja una opcion del menu:\n", "ERROR AL INGRESAR LA OPCION")==0)
				{

						switch(subMenuOpcion)
						{
							case 1:
							{
								if(contadorSalon>0 && contadorArcade>0)
								{
									if(inf_A_salonConMuchosArcades(listArcade, lenArcade, listSalon, lenSalon)!=0)
									{
										puts("No hay salon que contenga tantos arcades.");
									}
								}
								break;
							}

							case 2:
							{
								if(contadorSalon>0 && contadorArcade>0)
								{
									if(inf_B_contarYMostrarArcadesMultiJugador(listArcade, lenArcade, listSalon, lenSalon)!=0)
									{
										puts("error al contar los arcades multiplayers");
									}
								}
								break;
							}

							case 3:
							{
								if(contadorSalon>0 && contadorArcade>0)
								{
									if(inf_C_informarSalonCompleto(listSalon, lenSalon, listArcade, lenArcade)!=0)
									{
										puts("error al informar el SALON");
									}
								}
								break;
							}

							case 4:
							{
								if(contadorSalon>0 && contadorArcade>0)
								{
									if(inf_D_informarArcadesDeUnSalon(listSalon, lenSalon, listArcade, lenArcade)!=0)
									{
										puts("error al informar");
									}
								}
								break;
							}

							case 5:
							{
								break;
							}

							case 6:
							{
								break;
							}

							case 7:
							{
								if(contadorSalon>0 && contadorArcade>0)
								{
									if(inf_G_buscarYcontarJuegos(listArcade, lenArcade)!=0)
									{
										puts("Error al buscar el juego");
									}
								}

								break;
							}

							case 8:
							{
								puts("------Cerrando opciones avanzadas------");
								break;
							}

						}
					}
				//final del while submenu

					break;
				}

				case 10:
				{
					puts("bye byee");
					break;
				}



			}//final del switch
		}//final if para elegir opcion

		}while(opcionIngresadaPorUser!=10);

	return estado;
}


