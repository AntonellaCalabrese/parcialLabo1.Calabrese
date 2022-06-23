/*
 * censistas.c
 *
 *  Created on: 20 may 2022
 *      Author: Antonella Calabrese
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input-UTN.h"
#include "censistas.h"

void inicializarCensista(eCensista* listaC)
{

	eCensista aux[]= {
					{100, "Ana", 34, "1203-2345"},
					{101, "Juan", 24, "4301-54678"},
					{102, "Sol", 47, "5902-37487"}
					};

	for(int i=0;i<3;i++)
	{
		listaC[i]=aux[i];
	}

}

void mostrarCensista(eCensista censista)
{

	printf(" %4d   %13s     %11d     %14s    \n",
		censista.legajoCensista,
		censista.nombre,
		censista.edad,
		censista.telefono
		);

}

int mostrarCensistas(eCensista* listaC, int tamC)
{
	int allOk=0;

	if(listaC != NULL && tamC>0)
	{
		system("cls");
		printf("------------------------------------------------------------\n");
		printf("               ***LISTADO CENSISTAS***                      \n");
		printf("------------------------------------------------------------\n");
		printf("| legajo |     nombre      |     edad     |     telefono    \n");
		for(int i=0; i<tamC; i++)
		{
			mostrarCensista((*(listaC+i)));
		}
		allOk=1;
	}
	return allOk;
}



