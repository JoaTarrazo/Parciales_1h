
#include "Arcade.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ABM:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Arcade* arcade_new()
{
	Arcade* punteroAuxArcade=(Arcade*)malloc(sizeof(Arcade));

	return punteroAuxArcade;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoSonidoStr, char* CantidadJugadoresStr, char* capacidadFichasStr, char* nombreSalonStr, char* nombreJuegoStr)
{

	Arcade* pArcade = NULL;

	pArcade = arcade_new();

	if (pArcade != NULL && idStr  != NULL && nacionalidadStr != NULL  && tipoSonidoStr != NULL && CantidadJugadoresStr != NULL && capacidadFichasStr != NULL && nombreSalonStr != NULL && nombreJuegoStr != NULL)
	{
		arcade_setId(pArcade,atoi(idStr));

		arcade_setNacionalidad(pArcade, nacionalidadStr);

		arcade_setTipoSonido(pArcade, atoi(tipoSonidoStr));

		arcade_setCantidadJugadores(pArcade, atoi(CantidadJugadoresStr));

		arcade_setCapacidadFichas(pArcade, atoi(capacidadFichasStr));

		arcade_setSalon(pArcade, nombreSalonStr);

		arcade_setJuego(pArcade, nombreJuegoStr);

	}
		return pArcade;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_delete(Arcade* this,LinkedList* linkedList,int index)
{

	int estado = -1;

	   if(this != NULL && linkedList != NULL && ll_len(linkedList) > 0 && index >= 0)
	   {
	       free(this);

	       ll_remove(linkedList, index);

	       puts("Arcade eliminado correctamente");

	       estado = 0;
	   }

	   return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_findById(LinkedList* pArray,int id, int* indiceDeId)
{
	int retorno= -1;

	Arcade *pAux;

	int idAux;

	if(pArray!=NULL&&indiceDeId!=NULL)
	{
		for(int i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray, i);

			if(pAux!=NULL)
			{
				arcade_getId(pAux, &idAux);

				if(idAux==id)
				{
					*indiceDeId=i;

					retorno=0;

					break;
				}
			}
		}
	}
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int arcade_generarID(LinkedList* this)  //MODIFICAR por la de idMAXIMO.
{
	int id;
	int lenList;
	int estado= -1;

	if(this!=NULL)
	{
		lenList = ll_len(this);

		id = lenList ++;

		estado = id;
	}
		return estado;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_generarIdMaximo(LinkedList* this)
{
    int retorno = -1;

    int i;

    int idAux;

    int idMax=0;

    Arcade *pAuxArcade;

    if(this != NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
        	pAuxArcade = ll_get(this, i);

            if(i == 0)
            {
                arcade_getId(pAuxArcade, &idMax);
            }
            else
            {
                arcade_getId(pAuxArcade, &idAux);

                if(idAux > idMax)
                {
                    idMax = idAux;
                }
            }
        }

        retorno = idMax + 1;
    }

    return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_imprimirArcade(Arcade* this)
{
	int estado = -1;

	int id;

	char nacionalidad[268];

	int tipoSonido;
	char auxTipoSonidoChar[25];

	int cantidadJugadores;

	int capacidadFichas;

	char salonName[LEN_SALON];

	char juegoName[LEN_JUEGO];

	if(this!=NULL)
	{
		if(arcade_getId(this, &id)==0)
		{
			if(arcade_getNacionalidad(this, nacionalidad)==0)
			{
				if(arcade_getTipoSonido(this, &tipoSonido)==0)
				{
					if(arcade_getCantidadJugadores(this, &cantidadJugadores)==0)
					{
						if(arcade_getCapacidadFichas(this, &capacidadFichas)==0)
						{
							if(arcade_getSalon(this, salonName)==0)
							{
								if(arcade_getJuego(this, juegoName)==0)
								{
									 switch(tipoSonido)
									{
										case 0:

											sprintf(auxTipoSonidoChar, "%d", tipoSonido);

											strncpy(auxTipoSonidoChar, "MONO", 25);

											break;

										case 1:

											sprintf(auxTipoSonidoChar, "%d", tipoSonido);

											strncpy(auxTipoSonidoChar, "ESTEREO", 25);

											break;
									}

									estado = 0;

									printf("\n ID: %d   -  Nacionalidad: %s  -   Tipo sonido: %s   -     Cantidad jugadores: %d  -   Capacidad fichas: %d    -     Salon: %s   -     Juego: %s     -\n",id, nacionalidad, auxTipoSonidoChar, cantidadJugadores, capacidadFichas, salonName, juegoName);
								}
							}
						}
					}
				}
			}
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_sortArcadeForGame(void* pElemento1, void* pElemento2)
{
	int valor;

	   Arcade* juego1 = (Arcade*) pElemento1;

	   Arcade* juego2 = (Arcade*) pElemento2;

	   char auxNombre1[LEN_JUEGO];

	   char auxNombre2[LEN_JUEGO];


	   if(arcade_getJuego(juego1,auxNombre1)!=-1)
	   {
		  if(arcade_getJuego(juego2,auxNombre2)!=-1)
		   {
			   valor = strcmp(auxNombre1,auxNombre2);
		   }
	   }

	return valor;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SETTERS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_setId(Arcade* this,int id)
{
	int estado = -1;

	char auxId[28];

	sprintf (auxId, "%d", id); // sprintf(VARIABLE CHAR DONDE VAS A METER ESE DATOS * , *%D , VARIABLE QUE QUERES TRANSFORMAR);

	if (this != NULL && id >=0)
	{
		if (esNumerica(auxId) == 0)
		{
			estado = 0;

			this->id = atoi(auxId);
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
	int estado=-1;

	if(this!=NULL && nacionalidad!=NULL)
	{
		if(esTexto(nacionalidad)==0)
		{
			estado=0;

			strncpy(this->nacionalidad, nacionalidad, LEN_NACIONALIDAD);
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_setTipoSonido(Arcade* this,int tipoSonido)
{
	int estado=-1;

	char auxTipoSonido[28];

	sprintf(auxTipoSonido, "%d", tipoSonido);

	if(this!=NULL && tipoSonido>=0)

		if(esNumerica(auxTipoSonido)==0)
		{
			estado=0;

			this->tipoSonido = atoi(auxTipoSonido);
		}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_setCantidadJugadores(Arcade* this,int cantJugadores)
{
	int estado=-1;

	char auxCantJugadores[268];

	//puts("estoy en el set");

	sprintf(auxCantJugadores, "%d", cantJugadores);

	if(this!=NULL && cantJugadores>=0)
	{
		//puts("pase la verificacion es de NULL");

		if(esNumerica(auxCantJugadores)==0)
		{
			estado=0;

			//puts("pase la verificacion es numerica");

			this->cantidadJugadores = atoi(auxCantJugadores);
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_setCapacidadFichas(Arcade* this,int capFichas)
{
	int estado=-1;

	char auxCapFichas[268];

	sprintf(auxCapFichas, "%d", capFichas);

	if(this!=NULL && auxCapFichas>=0)
	{
		if(esNumerica(auxCapFichas)==0)
		{
			estado=0;

			this->capacidadFichas = atoi(auxCapFichas);
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_setSalon(Arcade* this,char* salonName)
{
	int estado=-1;

	if(this!=NULL && salonName!=NULL)
	{
		if(esSalon(salonName, LEN_SALON)==0)
		{
			estado=0;

			strncpy(this->salon, salonName, LEN_SALON);
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_setJuego(Arcade* this,char* juegoName)
{
	int estado=-1;

		if(this!=NULL && juegoName!=NULL)
		{
			if(esTexto(juegoName)==0)
			{
				estado=0;

				strncpy(this->juego, juegoName, LEN_JUEGO);
			}
		}

		return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GETTERS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_getId(Arcade* this, int* id)
{
	int estado=-1;

	if(this!=NULL && id!=NULL)
	{
		estado=0;

		*id = this->id;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int estado=-1;

	if(this!=NULL && nacionalidad!= NULL)
	{
		estado=0;

		strncpy(nacionalidad, this->nacionalidad, LEN_NACIONALIDAD);
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_getTipoSonido(Arcade* this, int* tipoSonido)
{
	int estado=-1;

	if(this!=NULL && tipoSonido!=NULL)
	{
		estado=0;
		*tipoSonido = this->tipoSonido;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_getCantidadJugadores(Arcade* this,int* cantJugadores)
{
	int estado = -1;

	if (this != NULL && cantJugadores != NULL)
	{
		estado = 0;

		*cantJugadores = this->cantidadJugadores;
	}

		return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_getCapacidadFichas(Arcade* this,int* capFichas)
{
	int estado = -1;

	if (this != NULL && capFichas != NULL)
	{
		estado = 0;
		*capFichas = this->capacidadFichas;
	}

		return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_getSalon(Arcade* this,char* salonName)
{
	int estado=-1;

	if(this!=NULL && salonName!= NULL)
	{
		estado=0;

		strncpy(salonName, this->salon, LEN_SALON);
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_getJuego(Arcade* this,char* juegoName)
{
	int estado=-1;

	if(this!=NULL && juegoName!= NULL)
	{
		estado=0;

		strncpy(juegoName, this->juego, LEN_JUEGO);
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_esMultijugadorFilter(void* pAuxiliar)
{
	int returnAux = -1;

	int cantidadJugadoresAux;

	Arcade* pArcade;

	if(pAuxiliar!= NULL)
	{
		pArcade = (Arcade*)pAuxiliar;

		if(arcade_getCantidadJugadores(pArcade, &cantidadJugadoresAux)==0)
		{
			if(cantidadJugadoresAux>1)
			{
				returnAux = 0;
			}
			else
			{
				returnAux= -1;
			}
		}
	}

	return returnAux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int arcade_multiplicarFichasMap(void* pAuxiliar)
{

	Arcade* pArcade;

	int returnAux = -1;

	int capacidadFichasAux;

	if(pAuxiliar!=NULL)
	{
		pArcade = (Arcade*)pAuxiliar;

		if(arcade_getCapacidadFichas(pArcade, &capacidadFichasAux)==0)
		{
			if(capacidadFichasAux >0)
			{
				capacidadFichasAux = capacidadFichasAux * 2;

				if(arcade_setCapacidadFichas(pArcade, capacidadFichasAux)==0)
				{
					returnAux = 0;
				}
			}
		}
	}
	return returnAux;
}


