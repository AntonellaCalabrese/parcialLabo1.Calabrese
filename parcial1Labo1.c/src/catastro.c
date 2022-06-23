/*
 * catastro.c
 *
 *  Created on: 16 jun 2022
 *      Author: antonella
 */

#include <stdio.h>
#include <stdlib.h>
#include "catastro.h"
#include "viviendas.h"
#include <string.h>

void inicializarHardCatastro(eCatastro* listaCat)
{
	eCatastro aux[]= {
						{1000, "Avellaneda", 28, 1540},
						{1001, "Lanús", 43, 1789},
						{1002, "Quilmes", 32, 1624},
						{1003, "La Plata", 67, 1677},
						{1004, "Lomas de Zamora", 32, 1923}
					};

	for(int i=0;i<5;i++)
	{
		listaCat[i]=aux[i];
	}



}


void mostrarCatastro(eCatastro catastro)
{

	printf(" %4d   %13s     %11d     %14d    \n",
		catastro.idCatastro,
		catastro.localidad,
		catastro.manzana,
		catastro.parcela
		);

}

int mostrarCatastros(eCatastro* listaCat, int tamCat)
{
	int allOk=0;

	if(listaCat != NULL && tamCat>0)
	{
		system("cls");
		printf("------------------------------------------------------------\n");
		printf("               ***LISTADO CATASTRO***                      \n");
		printf("------------------------------------------------------------\n");
		printf("| id  |     localidad      |     manzana     |     parsela    \n");
		for(int i=0; i<tamCat; i++)
		{
			mostrarCatastro((*(listaCat+i)));
		}
		allOk=1;
	}
	return allOk;
}



int listarCatastroPorLocalidad(eCatastro* lista, int tam, int orden)
{
	eCatastro auxCatastro;
	int allOk=0;

	if(lista!=NULL && tam>0)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if(orden==1)
				{
					if((strcmp((*(lista+i)).localidad , (*(lista+j)).localidad )>0) || (strcmp((*(lista+i)).localidad, (*(lista+j)).localidad)==0 ))
					{
						auxCatastro=(*(lista+i));
						(*(lista+i))=(*(lista+j));
						(*(lista+j))=auxCatastro;
					}
				}else
				{
					if(orden==0)
					{
						if((strcmp((*(lista+i)).localidad, (*(lista+j)).localidad)<0) || (strcmp((*(lista+i)).localidad, (*(lista+j)).localidad)==0 ))
						{
							auxCatastro=(*(lista+i));
							(*(lista+i))=(*(lista+j));
							(*(lista+j))=auxCatastro;
						}
					}
				}
			}
		}mostrarCatastros(lista,tam);

		allOk=1;
	}
	return allOk;
}

int ListarCatastros(eCatastro* listaCat,int tamCat)
{
	int allOk=0;
	int order;

	if(listaCat != NULL && tamCat>0 )
	{
		system("cls");
		printf("--------------------------------------------\n");
		printf("     ****Listar datos de Catastro.****      \n");
		printf("--------------------------------------------\n");

		printf("Elija una opcion: \n");
		printf("1- orden ascendente. \n");
		printf("0- orden descendente. \n");

		scanf("%d", &order);

		switch(order)
		{
			case 1:
				listarCatastroPorLocalidad(listaCat, tamCat,order);
				break;
		}allOk=1;
	}
	return allOk;
}
