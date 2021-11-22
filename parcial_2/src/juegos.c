//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "juegos.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Juegos* juego_new()
{
	Juegos* punteroAuxJuego=(Juegos*)malloc(sizeof(Juegos));

	return punteroAuxJuego;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Juegos* new_juegosParametros(char* name)
{
	Juegos* auxJuegos = malloc(sizeof(Juegos));

	if(auxJuegos!=NULL&&name!=NULL)
	{
		juegos_setNombreJuego(auxJuegos, name);
	}

	return auxJuegos;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int noRepeatGames(LinkedList* this, char* pArcade)
{
	Juegos* juegoAux;

	int retorno=0;

	char nombreJuego[LEN_JUEGO];

	if(this!=NULL && pArcade!=NULL)
	{
		for(int i=0;i<ll_len(this);i++)
		{
			juegoAux = (Juegos*) ll_get(this, i);

			juegos_getNombreJuego(juegoAux, nombreJuego);

			if(juegoAux!=NULL)
			{
				if(strnicmp(nombreJuego, pArcade, LEN_JUEGO)==0)  //strnI  es para ignorar las diferencias entre MAYUS y minusculas.
				{
					retorno=0;

					break;
				}
			}
		}
	}

	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int juegos_setNombreJuego(Juegos* this,char* nombreJuego)
{
	int retorno=-1;

	if(this!=NULL && nombreJuego!=NULL)
	{
			retorno=0;

			strncpy(this->juego,nombreJuego,LEN_JUEGO);
	}

	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int juegos_getNombreJuego(Juegos* this,char* nombreJuego)
{
	int retorno= -1;

	if(this!=NULL && nombreJuego!=NULL)
	{
		retorno=0;

		strncpy(nombreJuego, this->juego,LEN_JUEGO);
	}

	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

int juegos_saveAsText(char* path , LinkedList* pArrayListJuegos) //NO HACE FALTA PARA EL CASE 6 : "con el mismo formato que arcades.csv (incluida la cabecera)"
 {

	int estado= -1;

	Juegos* pJuegoAux = juego_new();

	char auxJuego[LEN_JUEGO];

	FILE* f = fopen(path,"w");

	if(f!=NULL)
	{
		fprintf(f,"Juegos: \n");

		for(int i=0; i<ll_len(pArrayListJuegos); i++)
		{
			pJuegoAux = ll_get(pArrayListJuegos, i);

			if(pJuegoAux!=NULL)
			{
				juegos_getNombreJuego(pJuegoAux, auxJuego);

				fprintf(f,"%s\n",auxJuego);

				estado=0;
			}
		}
			fclose(f);
	}
		return estado;
 }

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int juegos_saveGamesFromText(char* path, LinkedList* this)
{
	int estado = 0;
	int bandera;

	char auxNombreJuego[LEN_JUEGO];

	char auxNombreJuego2[LEN_JUEGO];

	Arcade* pAuxiliarJuego;

	Arcade* pAuxiliarJuego2;

	FILE* archivo = NULL;

	if(this != NULL)
	{
		archivo = fopen(path, "w");

		if(archivo != NULL)
		{
			for(int i = 0; i < ll_len(this); i++)
			{
				bandera = -1;

				pAuxiliarJuego = ll_get(this, i);

				if(pAuxiliarJuego != NULL)
				{
					arcade_getJuego(pAuxiliarJuego, auxNombreJuego);

					for(int index2 = i+1; index2 < ll_len(this); index2++)
					{
						pAuxiliarJuego2 = ll_get(this, index2);

						if(pAuxiliarJuego2 != NULL)
						{
							arcade_getJuego(pAuxiliarJuego2, auxNombreJuego2);

							if(stricmp(auxNombreJuego, auxNombreJuego2) == 0) //con "i" para ignorar mayusculas
							{
								bandera = 0;
								break;
							}
						}
					}

					if(bandera == -1)
					{
						fprintf(archivo,"%s\n", auxNombreJuego);
					}
				}
				else
				{
					estado = -1;
					break;
				}
			}

			fclose(archivo);
		}
		else
		{
			estado = -1;
		}
	}
	else
	{
		estado = -1;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
