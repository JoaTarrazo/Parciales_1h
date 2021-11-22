#include <stdio.h>
#include <stdlib.h>

#include "parser.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	Arcade* pArcade;

	int estado = -1;

	char idAux[25];
	char auxNacionalidad[LEN_NACIONALIDAD];
	char auxTipoSonido[25];
	char auxCantidadJugadores[25];
	char auxCapacidadFichas[25];
	char auxSalon[LEN_SALON];
	char auxJuego[LEN_JUEGO];

	if(pFile!=NULL && pArrayListArcade!=NULL)
	{
	                   // id, nacionalidad, tipo_sonido ,cant_jug , fichas_max,s alon, game
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,auxNacionalidad,auxTipoSonido,auxCantidadJugadores,auxCapacidadFichas,auxSalon,auxJuego);  //PÁRA LEER LA PRIMERA LINEA.

		do{

			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,auxNacionalidad,auxTipoSonido,auxCantidadJugadores,auxCapacidadFichas,auxSalon,auxJuego)>6)
			{
				if(strcmp(auxTipoSonido, "MONO")==0)
				{
					strcpy(auxTipoSonido, "0");
				}
				else  //cualquier otra cosa que no sea MONO (estereo)
				{
					strcpy(auxTipoSonido, "1");
				}

				pArcade = arcade_newParametros(idAux, auxNacionalidad, auxTipoSonido, auxCantidadJugadores,auxCapacidadFichas,auxSalon,auxJuego);

				if(pArcade!=NULL)
				{
					ll_add(pArrayListArcade, pArcade);

					estado = 0;
				}
				else
				{
					estado=-1;

					break;
				}
			}

		}while(feof(pFile)==0);
	}

    return estado;
}
