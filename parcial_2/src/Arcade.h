
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"

#include "LinkedList.h"
#include "utn_pedirTipo.h"
#include "validaciones.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DEFINES:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define LEN_NACIONALIDAD 128
#define LEN_SALON 128
#define LEN_JUEGO 63

#define MONO 0
#define ESTEREO 1

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STRUCT:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct
{
    int id;
    char nacionalidad[LEN_NACIONALIDAD];
    int tipoSonido;
    int cantidadJugadores;
    int capacidadFichas;
    char salon[LEN_SALON];
    char juego[LEN_JUEGO];

}Arcade;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ABM:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Arcade* arcade_new();


//Arcade* arcade_newParametros(char* idStr,char* nacionalidad,char* tipoSonido, char* cantidadJugadores, char* capacidadFichas, char* salon, char* juego);

Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoSonidoStr, char* CantidadJugadoresStr, char* capacidadFichasStr, char* nombreSalonStr, char* nombreJuegoStr);


int arcade_delete(Arcade* this,LinkedList* linkedList,int index);


int arcade_findById(LinkedList* pArray,int id, int* indiceDeId);


int arcade_imprimirArcade(Arcade* this);


int arcade_generarID(LinkedList* this);


int arcade_sortArcadeForGame(void* pElemento1, void* pElemento2);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SETTERS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_setId(Arcade* this,int id);


int arcade_setNacionalidad(Arcade* this,char* nacionalidad);


int arcade_setTipoSonido(Arcade* this,int tipoSonido);


int arcade_setCantidadJugadores(Arcade* this,int cantJugadores);


int arcade_setCapacidadFichas(Arcade* this,int capFichas);


int arcade_setSalon(Arcade* this,char* salonName);


int arcade_setJuego(Arcade* this,char* juegoName);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GETTERS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_getId(Arcade* this,int* id);


int arcade_getNacionalidad(Arcade* this,char* nacionalidad);


int arcade_getTipoSonido(Arcade* this, int* tipoSonido);


int arcade_getCantidadJugadores(Arcade* this,int* cantJugadores);


int arcade_getCapacidadFichas(Arcade* this,int* capFichas);


int arcade_getSalon(Arcade* this,char* salonName);


int arcade_getJuego(Arcade* this,char* juegoName);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FILTERS Y MAPS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_esMultijugadorFilter(void* pAuxiliar);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_multiplicarFichasMap(void* pAuxiliar);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // employee_H_INCLUDED
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////