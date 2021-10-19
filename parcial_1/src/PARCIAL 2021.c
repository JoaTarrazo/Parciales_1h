/*
 ============================================================================
 Name        : PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

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
Se imprime la lista de arcades con los ID y datos que lo componen.
Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
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

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"
#include "salon.h"
#include "arcade.h"
#include "informes.h"
#include "menu.h"



int main(void)
{

	setbuf(stdout,NULL);

Salones listSalon[SALONES_LEN];
Arcades listArcade[ARCADES_LEN];

//INICIO LAS LISTAS: (ISEMPTY = 1)
sal_initSalones(listSalon, SALONES_LEN);
arc_initArcades(listArcade, ARCADES_LEN);

//LLAMO AL PRIMER MENU:
menu_mainMenu(listSalon, listArcade, SALONES_LEN, ARCADES_LEN);



	return EXIT_SUCCESS;
}
