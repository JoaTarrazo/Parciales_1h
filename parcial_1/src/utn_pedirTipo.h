/*
 * utn_pedirTipo.h
 *
 *  Created on: 13 sep. 2021
 *      Author: Joa
 */

#ifndef UTN_PEDIRTIPO_H_
#define UTN_PEDIRTIPO_H_
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PROTOTIPOS:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int utn_pedirFloat(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);

int utn_pedirInt(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);

int utn_pedirChar(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError);

int utn_pedirTexto(char pResultado[],int len, int reintentos, char* variableTexto, char* textoError);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////












#endif /* UTN_PEDIRTIPO_H_ */
