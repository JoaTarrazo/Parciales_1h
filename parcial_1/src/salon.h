/*
 * salon.h
 *
 *  Created on: 17 oct. 2021
 *      Author: Joa
 */

#ifndef SALON_H_
#define SALON_H_
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"

#include "utn_pedirTipo.h"


#define SALONES_LEN     100
#define NOMBRE_LEN      63
#define DIRECCION_LEN   63
#define SHOPPING        0
#define LOCAL           1
#define OCUPADO         0
#define LIBRE           1


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ESTRUCTURAS:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Salones
{
	char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	int isEmpty;     //0 OCUPADO          1 LIBRE
	int idSalon;
	int tipo;        //0 =  SHOPPING      1=LOCAL
};
typedef struct Salones Salones;

//__________________________________________________________________________________________________________________________________
//PROTOTIPOS:
//__________________________________________________________________________________________________________________________________


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ALTA:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int sal_initSalones(Salones* list, int len);

int sal_findEmpty(Salones list[],int len);

int sal_altaSalon(Salones* list);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//BAJA:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int sal_imprimirSalones(Salones* pList);

int sal_pedirIdSalonAlUsuario(int* id);

int sal_buscarSalonPorId(Salones* pList, int len, int id);

int sal_bajaSalones(Salones* list, int len, int id);



#endif /* SALON_H_ */
