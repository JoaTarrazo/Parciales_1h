/*
 * validaciones.c
 *
 *  Created on: 4 nov. 2021
 *      Author: Joa
 */

#include "validaciones.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//VALIDACIONES:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esTexto (char cadena[])
{
	int retorno;
	int i;

	retorno=-1;
	i=0;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if((cadena[i]>='A'&&cadena[i]<='z')||cadena[i]==32||cadena[i]=='.'||cadena[i]==',')
			{
				if(cadena[i]>'Z'&&cadena[i]<'a')
				{
					retorno=-1;
					break;
				}
				i++;

			} else
			{
				retorno=-1;
				break;
			}

		}
	}

	return retorno;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esFlotante(char cadena[])
{
	int retorno;
	int i;
	int contadorPuntos;

	retorno=-1;
	i=0;
	contadorPuntos=0;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if(cadena[0]=='-')
			{
				i=1;
			}

			if(cadena[i]<'.'|| cadena[i]>'9'||cadena[i]=='/')
			{
				retorno=-1;
				break;
			}
			if(cadena[i]=='.')
			{
				contadorPuntos++;
			}
			i++;
		}
	}

	if(contadorPuntos>1)
	{
		retorno=-1;
	}

	return retorno;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esNumerica(char cadena[])
{
	int estado= -1;
	int i=0;

	if (cadena!=NULL && strlen(cadena)>0)
	{
		estado=0;

		 while (cadena[i]!='\0') //for(i=0; i<strlen(cadena);i++)
		{
			if(cadena[i]>'9' || cadena[i]<'0') //esta mal.
			{
				if(i==0)
				{
					if(cadena[0]!='-')
					{
						estado=-1;
						break;
					}
					else
					{
						estado=-1;
						break;
					}
				}
			}
			i++;
		}
	}
	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esSalon(char* cadena, int lenCadena)
{
	int retorno = -1;

	int i;

		i=0;

		if(cadena!=NULL&&strlen(cadena)>0)
		{
			retorno=0;

			while(cadena[i]!='\0')
			{
				if((cadena[i]>='A'&&cadena[i]<='z')||cadena[i]==32||cadena[i]=='.'||cadena[i]==',' || cadena [i]==' ' || cadena [i] >= '0' || cadena [i] <= '9')
				{
					if(cadena[i]>'Z'&&cadena[i]<'a')
					{
						retorno=-1;
						break;
					}

					i++;
				}
				else
				{
					retorno=-1;
					break;
				}
			}
		}
		return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
