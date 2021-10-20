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

//ALTAS FORZADAS:
sal_altaForzada(listSalon, SALONES_LEN, 0, "sacoa", "gesell", 1);
sal_altaForzada(listSalon, SALONES_LEN, 1, "coto", "temperley", 0);
sal_altaForzada(listSalon, SALONES_LEN, 2, "JUMBO", "don bosco", 0);
sal_altaForzada(listSalon, SALONES_LEN, 3, "disney", "pais de nunca jamas", 1);

arc_altaForzada(listArcade, ARCADES_LEN, 0, "argentina", 0, 4, 50, 0, "mario bros");
arc_altaForzada(listArcade, ARCADES_LEN, 1, "peru", 0, 1, 50, 0, "dragon ball z");
arc_altaForzada(listArcade, ARCADES_LEN, 2, "bolivia", 1, 2, 40, 0, "sonic");
arc_altaForzada(listArcade, ARCADES_LEN, 3, "argentina", 1, 4, 70, 0, "sunset");
arc_altaForzada(listArcade, ARCADES_LEN, 4, "pakistan", 0, 2, 1, 1, " crash bandicoop");
arc_altaForzada(listArcade, ARCADES_LEN, 5, "argelia", 0, 3, 4, 1, "warcraft");
arc_altaForzada(listArcade, ARCADES_LEN, 6, "usa", 1, 1, 90, 2, "pacman");
arc_altaForzada(listArcade, ARCADES_LEN, 7, "usa", 0, 1, 43, 2, "demonio de tazmania");
arc_altaForzada(listArcade, ARCADES_LEN, 8, "inglaterra", 0, 4, 2, 2, "jumanji");
arc_altaForzada(listArcade, ARCADES_LEN, 9, "francia", 1, 4, 20, 2, "tinytoons");
arc_altaForzada(listArcade, ARCADES_LEN, 10, "alemania", 0, 3, 99, 2, "pitufos");
arc_altaForzada(listArcade, ARCADES_LEN, 11, "usa", 0, 2, 5, 2, "picapiedras");
arc_altaForzada(listArcade, ARCADES_LEN, 12, "suiza", 1, 4, 55, 3, "contra");

//LLAMO AL PRIMER MENU:
menu_mainMenu(listSalon, listArcade, SALONES_LEN, ARCADES_LEN);



	return EXIT_SUCCESS;
}
