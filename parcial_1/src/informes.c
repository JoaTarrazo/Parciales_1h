/*
 * informes.c
 *
 *  Created on: 17 oct. 2021
 *      Author: Joa
 */

#include "informes.h"


// A) Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón.

/*
  \ brief funcion que funcion que recorre ambos arrays con doble for, y relaciona y notifica los arcades correspondientes a un salon, siempre y cuando supere los 4 arcades.
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

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
					printf("\nID:%d  -  NOMBRE: %s  -   DIRECCION: %s  -  TIPO DE SALON: %d  - \n,", listSalon[i].idSalon,listSalon[i].nombre, listSalon[i].direccion, listSalon[i].tipo);
					estado=0;
				}
			}
		}

	return estado;
}

// B) Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y
// nombre del salón al que pertenece.

/*
  \ brief funcion que busca todos los arcades que sean para mas de 2 jugadores, e indica algunos de sus campos.
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

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

/*
  \ brief funcion que muestra todos los datos de un salon en especifico solo iongresando su id.
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

int inf_C_informarSalonCompleto(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade)
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
				printf("\n Nombre del Salon: %s   -   Tipo: %d   -   Direccion: %s  -\n",listSalon[indiceDelId].nombre,listSalon[indiceDelId].tipo, listSalon[indiceDelId].direccion);

				for(int i=0; i<lenArcade;i++)
				{
					if(listArcade[i].isEmpty == OCUPADO && listArcade[i].idSalon == idIngresado)
					{
						contadorArcade++;
					}
				}

				printf("\n La cantidad de Arcades que pose el salon es de: %d   -\n", contadorArcade); //fuera del for para no repetir el mensaje.
			}
		}
	}

	return estado;
}


//D) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos
//los arcades con sus datos junto con el nombre del juego que lo compone.

/*
  \ brief funcion que muestra los arcades correspondientes a un salon, ingresando el id del salon.
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

int inf_D_informarArcadesDeUnSalon(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade)
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
						printf("\n Nacionalidad: %s  -  Nombre del juego: %s  -   Cantidad de jugadores: %d   -   capacidad de fichas: %d  -  ID: %d   - \n",listArcade[i].nacionalidad, listArcade[i].nombre, listArcade[i].cantidadJugadores, listArcade[i].capacidadFichas, listArcade[i].idArcade);
					}
				}
			}
		}
	}
	return estado;
}

//E) Imprimir el salón con más cantidad de arcades, indicando todos
//los datos del salón y la cantidad de arcades que posee.

/*
  \ brief funcion que imprime el salon que contiene mas arcades cargados con su id salon.
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

int inf_E_SalonConMasArcades(Arcades* listArcade, int lenArcade, Salones* listSalon, int lenSalon)
{
	int estado = 0;
	int i;
	int e;
	int idConMasArcades;
	int contadorArcades;
	int contadorConMasArcades;
	int flag = 0;

	if(listArcade != NULL && lenArcade > 0 && listSalon != NULL && lenSalon > 0)
	{
		estado = 0;

		for(i = 0; i < lenSalon; i++)
		{
			if(listSalon[i].isEmpty == 0)
			{
				contadorArcades = 0;
				for(e = 0; e < lenArcade; e++)
				{
					if(listArcade[e].isEmpty == 0 && listArcade[e].idSalon == listSalon[i].idSalon)
					{
						contadorArcades++;
					}
				}
				if(flag == 0 || contadorArcades > contadorConMasArcades)
				{
					idConMasArcades = i;
					contadorConMasArcades = contadorArcades;
					flag = -1;
				}
			}
		}
		printf("\n ID del salon: %d  -  Nombre del salon: %s  -  Direccion del salon: %s  -  tipo: %d  -  cantidad de ARCADES que tiene el salon: %d \n",listSalon[idConMasArcades].idSalon, listSalon[idConMasArcades].nombre,listSalon[idConMasArcades].direccion, listSalon[idConMasArcades].tipo,contadorConMasArcades);
	}

	return estado;
}

//F) Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos que puede
//recaudar el salón (sumar cantidad de fichas máximo de cada arcade del salón y multiplicarla por el valor en pesos
//ingresado)

/*
  \ brief funcion que calcula el monto exacto de ingresos en pesos que puede generar haciendo el calculo de la capacidad de fichas totales y pidiendole un precio por ficha al user. (se le pide un id al user para el salon a calcular en especifico)
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

int inf_F_BilletinGenerado(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade)
{
	int estado = -1;

	float billetinMaximoGenerado;
	float precioIngresado;
	int idIngresado;
	int acumuladorDeFichas;

		if(listSalon != NULL && lenSalon > 0 && listArcade!=NULL && lenArcade >0)
		{
			estado = 0;

			if(utn_pedirInt(&idIngresado, 0, 100, 3, "ingrese el ID del salon que desea calcular", "Error al ingresar el ID")==0)
			{
				if(utn_pedirFloat(&precioIngresado, 1, 20, 3, "ingrese el valor por ficha del juego", "error al ingresar el valor")==0)
				{
					for(int i = 0; i < lenArcade; i++)
					{
						if(listArcade[i].isEmpty == 0 && listArcade[i].idSalon == idIngresado)
						{
							acumuladorDeFichas= acumuladorDeFichas + listArcade[i].capacidadFichas;
						}
					}
				}
			}

			billetinMaximoGenerado = (float)acumuladorDeFichas * precioIngresado;

			printf("\n El salon que corresponde al ID: %d,  puede acumular: $ %.2f \n",idIngresado ,billetinMaximoGenerado );
		}

	return estado;
}

//G) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen

/*
  \ brief funcion que pide el nombre de un juego al usuario y lo busca en todos los arcades para ver cuantos arcades en total contienen ese juego ingr4esado.
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

int inf_G_buscarYcontarJuegos (Arcades* list, int len)
{
	int estado = -1;
	int contadorArcade = 0;
	char nombreAux[63];
	int i;


	char nombreJuegoABuscar[NOMBRE_LEN];

	if (list != NULL && len > 0)
	{
		if(utn_pedirTexto(nombreJuegoABuscar, NOMBRE_LEN, 3, "Ingrese el nombre del juego que desea buscar", "Error al ingresar el juego")==0) //TENIA el LEN del arcade en la funcion.
		{
			printf("\n Usted ingreso: %s  - \n",nombreJuegoABuscar);
			strlwr(nombreJuegoABuscar);
			estado=0;
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty ==0)
				{
					strncpy(nombreAux, list[i].nombre,sizeof(nombreAux));

					strlwr(nombreAux);

					if(strncmp(nombreJuegoABuscar, nombreAux,sizeof(nombreJuegoABuscar))==0)
					{
						contadorArcade++;

					}
				}
			}
			printf("\nla cantidad de arcades que contienen ese juego son: %d\n",contadorArcade);
		}
	}
	return estado;
}

// H)  Un  salón se  encuentra  equipado  por completo  si posee  al menos  8  arcades  de  mas  de 2  jugadores.  Listar los
//salones que cumplan con este mínimo de requisito.

/*
  \ brief funcion que muestra los salones COMPLETOS (con + de 8 arcades asociados de juegos para mas de 2 jugadores)
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

int inf_H_SalonFull(Arcades *listArcade, int lenArcade, Salones *listSalon, int lenSalones)
{
	int estado=-1;
	int i;
	int e;
	int contador=0;

		if(listArcade != NULL && lenArcade>=0)
		{
			for(i=0;i<lenSalones; i++)
			{
				if(listSalon[i].isEmpty==0)
				{
					contador=0; //lo reinicio por vuelta
					for(e=0; e<lenArcade; e++)
					{
						if(listArcade[e].isEmpty==0 && listArcade[e].idSalon == listSalon[i].idSalon && listArcade[e].cantidadJugadores >2 )
						{
							contador++;
						}
					}
					if(contador > 8)
					{
						printf("\n id salon: %d -  cantidad de arcades es de: %d \n",listSalon[i].idSalon,contador);
						estado=0;
					}
				}
			}
		}
		return estado;
	}




//I) Imprimir el promedio de arcades por salón. (Cantidad de arcades totales / Cantidad de salones totales).

/*
  \ brief funcion que calcula el promedio de arcades por salon : arcades % salones.
* \ param
* * \ param
* * \ param
* \ return retorna[-1]ERROR o [0]EXITO
*/

int inf_I_promedioArcadePorSalon(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade)
{
	int estado= -1;
	int i;
	int e;
	int contadorSalon=0;
	int contadorArcade=0;
	float promedio=0;

	if(listSalon != NULL && lenSalon > 0 && listArcade!=NULL && lenArcade >0)
	{
		estado=0;

		for(i=0;i<lenSalon;i++)
		{
			if(listSalon[i].isEmpty==0)
			{
				contadorSalon++;
			}
		}
		for(e=0; e<lenArcade;e++)
		{
			if(listArcade[e].isEmpty==0)
			{
				contadorArcade++;
			}
		}

		promedio = (float)contadorArcade / contadorSalon;

		printf("\n El promedio de arcades por salon es de: %f  -\n", promedio);
	}
	return estado;
}
