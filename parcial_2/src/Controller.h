#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"

#include "LinkedList.h"
#include "Arcade.h"
#include "utn_pedirTipo.h"
#include "parser.h"


int controller_loadFromText(char* path , LinkedList* pArrayListArcade);


int controller_addArcade(LinkedList* pArrayListArcade);


int controller_editArcade(LinkedList* pArrayListArcade);


int controller_removeArcade(LinkedList* pArrayListArcade);


int controller_ListArcade(LinkedList* pArrayListArcade);


int controller_sortArcadeForName(LinkedList* list);


int controller_saveAsText(char* path , LinkedList* pArrayListArcade);


int controller_saveAsTextJuegos(char* path , LinkedList* pArrayListArcadeJuegos);





#endif /* CONTROLLER_H_ */
