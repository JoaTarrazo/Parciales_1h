
#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"

#include "Arcade.h"
#include "Controller.h"
#include "linkedList.h"
#include "utn_pedirTipo.h"
#include "validaciones.h"
#include "parser.h"
#include "juegos.h"


int menu_mainMenu(LinkedList* list, LinkedList* listJuegos, LinkedList* listMultijugador);

#endif /* MENU_H_ */
