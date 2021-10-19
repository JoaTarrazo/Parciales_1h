/*
 * utn_pedirTipo.c
 *
 *  Created on: 13 sep. 2021
 *      Author: Joa
 */


#include "utn_pedirTipo.h"
#include "string.h"
#include "ctype.h"

//prototipo de la static: es local y no se puede usar en el main, solo ayuda a las otras funciones (funcion dentro de funcion)
static int myGets(char pResultado[], int len);
static int esNumerica(char cadena[]);
static int esFlotante(char cadena[]);
static int esTexto (char cadena[]);

//codigos:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_pedirFloat(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esFlotante(bufferCadenaAux)==0)
				{
					buffer=atof(bufferCadenaAux);
					if(buffer>=min&&buffer<=max)
					{
						retorno = 0; // OK
						*pResultado=buffer;
						break;
					}else
					{
						printf("%s\n",textoError);
					}

				} else
				{
					printf("%s\n",textoError);
				}

			}

		}
	}
	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_pedirInt(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNumerica(bufferCadenaAux)==0)
				{
					buffer=atoi(bufferCadenaAux);
					if(buffer>=min&&buffer<=max)
					{
						retorno = 0; // OK
						*pResultado=buffer;
						break;
					}
					else
					{
						printf("%s\n",textoError);
					}
				}
				else
				{
					printf("%s\n",textoError);
				}
			}
		}
	}
	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_pedirChar(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError)
{
	char buffer;
	int retorno=-1;
	int i;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			fflush(stdin);
			scanf("%c", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-1;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_pedirTexto(char pResultado[], int len, int reintentos, char* mensaje, char* mensajeError)
{
	int retorno=-1;
	char bufferCadenaAux[128];
	int i;

	if(pResultado != NULL && reintentos >0 && len>0 && mensaje != NULL && mensajeError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",mensaje);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esTexto(bufferCadenaAux)==0)
				{

					retorno = 0; // OK
					strncpy (pResultado,bufferCadenaAux,len);
					break;
					}else
					{
						printf("%s\n",mensajeError);
					}

				} else
				{
					printf("%s\n",mensajeError);
				}

			}
	}
	return retorno;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCIONES STATIC PARA INCLUIR EN LAS FUNCIONES PRINCIPALES:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//funcion myGets (verifica y cambia el \n (enter) ingresado por el usuario al ingresar el dato por fgets, y lo remplaza por un \0.

static int myGets(char pResultado[], int len)
{
	int retorno=-1;
	int indexFinal;
	fflush(stdin);

	if(fgets(pResultado,len,stdin)!=NULL)
	{
		// borro el \n del final
		indexFinal = strlen(pResultado)-1;
		if(pResultado[indexFinal] == '\n')
		{
			pResultado[indexFinal] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

//Funcion que recibe una cadena de caracteres y verifica que sean todos numeros, en caso de serlo retorna -1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int esNumerica(char cadena[]) //FUNCIONA!
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static int esFlotante(char cadena[])
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int esTexto (char cadena[])
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


