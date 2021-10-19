/*
 * informes.c
 *
 *  Created on: 17 oct. 2021
 *      Author: Joa
 */

#include "informes.h"


// A) Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón.

int inf_A_salonConMuchosArcades(Arcades* listArcade, int lenArcade, Salones* listSalon, int lenSalon)
{
	int estado= -1;
	int contadorArcade=0;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade >=0 && lenSalon>=0)

		for(int i=0;i<lenSalon;i++)
		{
			if(listSalon[i].isEmpty==0)
			{
				for(int y=0; y<lenArcade;y++)
				{
					if(listArcade[i].isEmpty==0 && listSalon[i].idSalon == listArcade[y].idSalon )
					{
						contadorArcade++;
					}
				}
				if(contadorArcade>4)
				{
					printf("ID:%d  -  NOMBRE: %s  -   DIRECCION: %s  -  TIPO DE SALON: %d  - \n,", listSalon[i].idSalon,listSalon[i].nombre, listSalon[i].direccion, listSalon[i].tipo);
					estado=0;
				}
			}
		}

	return estado;
}

// B) Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y
// nombre del salón al que pertenece.

int inf_B_contarYMostrarArcadesMultiJugador(Arcades* listArcade, int lenArcade, Salones* listSalon , int lenSalon)
{
	int estado = -1;

	if(listArcade != NULL && lenArcade > 0 && listSalon != NULL && lenSalon > 0)
	{
		estado = 0;

		for(int i = 0; i < lenArcade; i++)
		{
			if(listArcade[i].isEmpty == 0 && listArcade[i].cantidadJugadores > 2)
			{
				int indiceDelIdBuscado;

				indiceDelIdBuscado = sal_buscarSalonPorId(listSalon, lenSalon, listArcade[i].idSalon);

				printf("\n Arcade ID: %d   -   Cantidad de jugadores: %d   - Nombre del juego: %s   -    Nombre del salón: %s   -\n", listArcade[i].idArcade, listArcade[i].cantidadJugadores, listArcade[i].nombre, listSalon[indiceDelIdBuscado].nombre);
			}
		}
	}

	return estado;
}


//C) Listar toda la información de un salón en específico ingresando su ID. Imprimir nombre,
//tipo y dirección y cantidad de arcades que posee.

int inf_C_informarSalonCompleto(Salones* listSalon, int lenSalon, Arcades listArcade, int lenArcade)
{
	int estado= -1;

	if(listSalon!=NULL && listArcade!=NULL && lenSalon>=0 && lenArcade>=0)
	{
		int idIngresado;
		int indiceDelId;
		int contadorArcade=0;

		if(sal_pedirIdSalonAlUsuario(&idIngresado)==0)
		{
			indiceDelId= sal_buscarSalonPorId(listSalon, lenSalon, idIngresado);

			if(indiceDelId> -1 && listSalon[indiceDelId].isEmpty == OCUPADO)
			{
				estado=0;
				printf("Nombre del Salon: %s   -   Tipo: %d   -   Direccion: %s  -\n",listSalon[indiceDelId].nombre,listSalon[indiceDelId].tipo, listSalon[indiceDelId].direccion);

				for(int i=0; i<lenArcade;i++)
				{
					if(listArcade[i].isEmpty == OCUPADO && listArcade[i].idSalon == idIngresado)
					{
						contadorArcade++;
					}
				}

				printf("La cantidad de Arcades que pose el salon es de: %d   -", contadorArcade); //fuera del for para no repetir el mensaje.
			}
		}
	}

	return estado;
}


//D) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos
//los arcades con sus datos junto con el nombre del juego que lo compone.

int inf_D_informarArcadesDeUnSalon(Salones* listSalon, int lenSalon, Arcades listArcade, int lenArcade)
{
	int estado=-1;

	if(listSalon!=NULL && listArcade!=NULL && lenSalon>=0 && lenArcade>=0)
	{
		int idElegido;

		int indiceDelId;

		if(sal_pedirIdSalonAlUsuario(&idElegido)==0)
		{
			indiceDelId = sal_buscarSalonPorId(listSalon, lenSalon, idElegido);

			if(indiceDelId>-1 && listSalon[indiceDelId].isEmpty==OCUPADO)
			{
				estado=0;

				printf("\n Nombre del Salon: %s   -   tipo de salon: %d  -\n", listSalon[indiceDelId].nombre, listSalon[indiceDelId].tipo);

				puts("--------Arcades que contiene el salon:---------");

				for(int i=0; i<lenArcade;i++)
				{
					if(listArcade[i].isEmpty == OCUPADO && listArcade[i].idSalon == idElegido)
					{
						printf("Nacionalidad: %s  -  Nombre del juego: %s  -   Cantidad de jugadores: %d   -   capacidad de fichas: %d  -  ID: %d   - ",listArcade[i].nacionalidad, listArcade[i].nombre, listArcade[i].cantidadJugadores, listArcade[i].capacidadFichas, listArcade[i].idArcade);
					}
				}
			}
		}
	}
	return estado;
}



//E) Imprimir el salón con más cantidad de arcades, indicando todos
//los datos del salón y la cantidad de arcades que posee.

int inf_E_SalonConMasArcades(Arcades* listArcade, int lenArcade, Salones* listSalon, int lenSalon)
{
	int estado=-1;

	//doble bucle for //  if (listArcade[index].idSalon == listSalon[i].idSalon) contadorArcades++  // sacar maximo de arcades(?)

	return estado;
}

//F) Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos que puede
//recaudar el salón (sumar cantidad de fichas máximo de cada arcade del salón y multiplicarla por el valor en pesos
//ingresado)

/* NO TIEMPO A COMPLETARLO:

int inf_F_BilletinGenerado(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade)
{
	int estado = -1;

	int cont = 0;
	int billetinMaximoGenerado;
	int contador;
	int precioIngresado;

		if(listSalon != NULL && lenSalon > 0 && listArcade!=NULL && lenArcade >0)
		{
			estado = 0;

			sal

			utn_pedirFloat(&precioIngresado, 1, 20, 3, "ingrese el valor por ficha del juego", "error al ingresar el valor");

			for(int i = 0; i < lenArcade; i++)
			{
				if(listArcade[i].isEmpty == 0 && listArcade[i].idSalon == idIngresado)
				{
					contador
				}
			}

			billetinMaximoGenerado = contador * precioIngresado;
			puts("--------------------------------------");
			printf("El salon #%d acumularía $%d\n", id, valMax);
			puts("--------------------------------------");
		}
	return estado;
}

*/


//G) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen

int inf_G_buscarYcontarJuegos (Arcades* list, int len)
{
	int retorno = -1;
	int i;
	int contadorArcade = 0;

	char nombreJuegoABsucar[NOMBRE_LEN];

	if (list != NULL && len > 0)
	{
		if(utn_pedirTexto(nombreJuegoABsucar, len, 3, "Ingrese el nombre del juego que desea buscar", "Error al ingresar el juego")==0)
		{
			for (i=0; i<len;i++)
			{
				if (list[i].isEmpty == OCUPADO)
				{
					strcpy(nombreJuegoABsucar, list[i].nombre);

					strlwr(nombreJuegoABsucar); //convierto en minuscula para evitar errores a la hora de buscar por MAYUS

					if(strncmp(list[i].nombre, nombreJuegoABsucar,sizeof(list[i].nombre))==0)    //==0 (son iguales)   ==1 (si es mayor)  ==-1(si es menor)
					{
						contadorArcade++;
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}




