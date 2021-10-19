/*
 ============================================================================
 Name        : PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 1) ALTA DE SALÓN
Se deberá dar de alta un salón con los siguientes datos: Nombre, dirección y tipo.
Se generará un ID único para gestionar los SALONES.
Este salón se imprimirá por pantalla si el alta es correcta.

2) ELIMINAR SALÓN
Se imprime la lista de salas listando ID, nombre y dirección.
Se ingresa un ID y la misma generará la baja del salón, junto con todos los arcades que lo componen.

3) IMPRIMIR SALONES
Se imprime la lista completa de salas con todos sus datos. Nombre, dirección y tipo.

4) INCORPORAR ARCADE
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
fichas, ID del salón al que pertenece (Validar que exista) y nombre del juego que contiene (hasta 63 caracteres).
Se generará un ID único para gestionar los ARCADE.

5) MODIFICAR ARCADE
Se imprime la lista de arcades con los ID y datos que lo componen.
Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
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
