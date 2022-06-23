/*
 * input-UTN.c
 *
 *  Created on: 19 may 2022
 *      Author: Antonella Calabrese
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "censistas.h"

int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos){
	int retorno=-1;
	int bufferInt;

	do{
		if(pResultado != NULL && mensaje != NULL && msjError != NULL && min<= max && reintentos>0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);
			if(bufferInt>=min && bufferInt<=max){
				*pResultado=bufferInt;
				retorno=0;
				break;
			}else{
				printf("%s", msjError);
				reintentos--;
			}
		}
	}while(reintentos>=0);
	return retorno;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
    int retorno = -1;
    int numeroIngresado;

    if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *entero = numeroIngresado;
        retorno = 0;
    }

    return retorno;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
    int retorno = -1;
    float numeroIngresado;

    if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%f", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%f", &numeroIngresado);
        }

        *flotante = numeroIngresado;
        retorno = 0;
    }

    return retorno;
}

int pedirCadena(char* cadena, char* mensaje)
{
    int retorno = -1;

    if(cadena != NULL && mensaje != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(cadena);

        retorno = 0;
    }
    return retorno;
}

int primerLetraMayuscula(char name[])
{

	int i = 0;
	int error = -1;

	if(name != NULL)
	{
		strlwr(name);
		name[0] = toupper(name[0]);

		while(name[i] != '\0')
		{
		   if(name [i] == ' ')
		   {
			   name [i + 1] = toupper(name[i+1]);
		   }

		   i++;
		}
		    //puts(name);
	  error = 0;
	}
    return error;
}

int validarLetras(char string[])
{
    int i = 0;
    int error = 0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if(string[i] != ' ' && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
            {
                error= -1;

                while(error < 0)
                {
                    printf("ERROR, Se debe ingresar letras unicamente: ");
                    fflush(stdin);
                    gets(string);
                    error = 0;
                    i = 0;
                }
            }
            i++;
        }
    }

    return error;
}

