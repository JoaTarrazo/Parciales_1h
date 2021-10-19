/*
 * menu.h
 *
 *  Created on: 17 oct. 2021
 *      Author: Joa
 */

#ifndef MENU_H_
#define MENU_H_


#include <stdio.h>
#include <stdlib.h>


#include "salon.h"
#include "arcade.h"
#include "informes.h"
#include "utn_pedirTipo.h"


void menu_modificarMenuArcade(Arcades* list , int len);

int menu_modificarOpcionesArcade(Arcades* list, int lenArcade);

int menu_mainMenu(Salones* listSalon, Arcades* listArcade, int lenSalon, int lenArcade);

#endif /* MENU_H_ */


