/*
========================================================================================================================================================



1) INCORPORAR ARCADE
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
fichas, Nombre del salón al que pertenece y nombre del juego que contiene (hasta 63 caracteres).
Se generará un ID único para gestionar los ARCADE. Actualizar el archivo CSV con el arcade agregado

2) MODIFICAR ARCADE
Se imprime la lista de arcades con los ID y datos que lo componen.
Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
cargados en el sistema y se permitirá ingresar un texto con el nombre del nuevo juego. Actualizar el archivo CSV con
el arcade modificado.

3) ELIMINAR ARCADE
Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la información del salón y el
juego que contiene.
Se ingresa un ID y previo a dar de baja se deberá solicitar confirmación, imprimiendo el arcade a dar de baja y
confirmando si está seguro dar de baja esté mismo. Actualizar el archivo CSV con el arcade aeliminado.

4) IMPRIMIR ARCADES ordenados por nombre de juego
Se imprime la lista de arcades con ID, y sus datos.

5) Generar archivo con JUEGOS
Se generará un archivo .txt con los nombres de los juegos (uno por linea) sin repetir.

6) Generar un archivo con arcades “Multijugador” (mas de 1 jugador)
Se generará un archivo “multijugador.csv” con el mismo formato que arcades.csv (incluida la cabecera), que
contenga solo los arcades que tengan mas de 1 jugador.

7) Actualizar cantidad de fichas
La empresa compró una actualizacion para que los arcades soporten el doble de fichas, por lo que debe
actualizarse el valor de fichas en el archivo. Al elegir esta opcion, se duplicará el valor de cantidad de fichas de todos los arcades

========================================================================================================================================================

DATOS:

TIPOS DE SONIDO PARA ARCADE: MONO // ESTÉREO.

Tratar a el “tipo” sonido como valor numéricos relacionado con DEFINE.

Un arcade solo pertenece a un solo salón.

Un arcade solo contiene un juego.

Utilizar LinkedList para la lista de arcades.
.
Implementar y utilizar la funcion ll_filter para el punto 7.

Implementar y utilizar la funcion ll_sort para el punto 5.

Implementar y utilizar la funcion ll_map para el punto 8.

Generar un ID auto incrementable para cada entidad.

========================================================================================================================================================
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/


#include <stdio.h>
#include <stdlib.h>

#include "Arcade.h"
#include "LinkedList.h"
#include "Controller.h"
#include "menu.h"
#include "juegos.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{

	setbuf(stdout,NULL);

	LinkedList* list = ll_newLinkedList();  //creo una lista de linkedList.

	LinkedList* listJuegos = ll_newLinkedList();  //creo una lista de linkedList para los juegos (case 5).

	LinkedList* listMultijugador = ll_newLinkedList(); //creo una lista de linkedList para los juegos multijugador (case 6).

	if(controller_loadFromText("arcades.csv", list)==0)  //INICIALIZO Y CARGO EL ARCHIVO A LA LINKED LIST.
	{
		puts("\n-------------BIENVENIDO-------------\n");

		puts("Cargando archivo de ARCADES.....COMPLETADO!\n");  //DOY AVISO DE SI LA FUNCION INICIO BIEN Y DESPLIEGO EL MENU.

		if(menu_mainMenu(list,listJuegos, listMultijugador) == -1)
		{
			puts("error, se terminaron los reintentos para escojer opcion del menu, por favor, espere 30 segundos para volver a intentarlo (?)");
		}
	}

	return EXIT_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
