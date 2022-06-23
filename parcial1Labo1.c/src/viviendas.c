/*
 * viviendas.c
 *
 *  Created on: 25 may 2022
 *      Author: Antonella Calabrese
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "input-UTN.h"
#include "viviendas.h"
#include "censistas.h"
#include "catastro.h"

#define TRUE 0
#define FALSE 1
#define TAM 20000

int inicializarVivienda(eVivienda* lista, int tam)
{
	int allOk = -1;
	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	        	(*(lista+i)).isEmpty=1;
	        }
	        allOk = 0;
	    }
	return allOk;
}

// ///////////////////ALTA VIVIENDA/////
int buscarLibre(eVivienda* lista, int tam)
{
	int indice= -1;
	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	            if((*(lista+i)).isEmpty)
	            {
	                indice = i;
	                break;
	            }
	        }
	    }
	return indice;
}


int altaVivienda(eVivienda* lista,eCensista* listaC,eCatastro* listaCat, int tam,int tamC,int tamCat, int* pId)
{
	int allOk=0;
	int indice;
	eVivienda auxVivienda;


		if(lista != NULL && tam>0 && pId != NULL)
		{
			system("cls");
			printf("-----------------------------\n");
			printf("         ALTA VIVIENDA       \n");
			printf("-----------------------------\n");

			indice=buscarLibre(lista, tam);
			if(indice== -1)
			{
				printf("No hay espacio en el sistema\n");
			}
			else
			{
				auxVivienda.idVivienda=*pId;
				(*pId)++;

				pedirEntero(&auxVivienda.idCatastro,"ingrese id de catastro: 1000/avellaneda - 1001/lanus - 1002/quilmes - 1003/la plata - 1004/Lomas de Zamora \n","el catastro ingresado no existe",1000,1004);

				pedirCadena(auxVivienda.calle, "ingrese calle : \n");
				validarLetras(auxVivienda.calle);
				primerLetraMayuscula(auxVivienda.calle);

				pedirEntero(&auxVivienda.cantidadPersonas, "Ingrese la cant de personas: \n", "error", 1,1000000);

				pedirEntero(&auxVivienda.cantidadHabitaciones, "Ingrese cantidad de habitaciones: \n", "error",1,10);

				pedirEntero(&auxVivienda.tipoVivienda, "Ingrese tipo de vivienda: 1: Casa - 2: Departamento - 3: Casilla 4: Rancho \n", "error", 1,4);

				pedirEntero(&auxVivienda.legajoCensista,"ingrese numero de legajo: 100/ana - 101/juan - 102/sol \n","el censista ingresado no existe",100,102);

				auxVivienda.isEmpty=0;


				lista[indice]=auxVivienda;



			}
			allOk=1;
		}
	return allOk;
}

void mostrarVivienda(eVivienda unaVivienda)
{
	eTipoVivienda tipos[4]={{1,"Casa"},{2,"Departamento"},{3,"Casilla"},{4,"Rancho"}};

	for(int i=0;i<4;i++)
	{
		if(unaVivienda.tipoVivienda == tipos[i].tipoVivienda)
		{
			printf(" %3d   %14d    %19s     %15d     %23d     %22s     %20d      \n",
						unaVivienda.idVivienda,
						unaVivienda.idCatastro,
						unaVivienda.calle,
						unaVivienda.cantidadPersonas,
						unaVivienda.cantidadHabitaciones,
						tipos[i].descripcion,
						unaVivienda.legajoCensista
						);
		}
	}
}



int mostrarViviendas(eVivienda* lista, int tam)
{
	int allOk=0;
	int flag=1;

	if(lista != NULL && tam>0)
	{
		system("cls");
		printf("------------------------------------------------------------------------------------------------------------------------------\n");
		printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
		printf("------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");
		for(int i=0; i<tam; i++)
		{
			if(!(*(lista+i)).isEmpty)
			{
				mostrarVivienda((*(lista+i)));
				flag=0;
			}
		}
		if(flag)
		{
			printf("No hay viviendas para dar el alta. \n");
		}
		allOk=1;
	}
	return allOk;
}


// ////////////MODIFICACION///
int menuModificacion()
{
	int opcion;
	printf("----------------------------------------------\n");
	printf("  Ingrese una de las opciones para modificar \n");
	printf("----------------------------------------------\n");
	printf("1. ID catastro \n");
	printf("2. Calle \n");
	printf("3. Cantidad de personas \n");
	printf("4. Cantidad de habitaciones \n");
	printf("5. Tipo de vivienda \n");
	printf("6. Legajo Censista \n");

	scanf("%d", &opcion);
	return opcion;
}

int buscarViviendaId(eVivienda* lista, int tam, int idVivienda)
{
	int indice=-1;

	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	        	if((*(lista+i)).idVivienda == idVivienda && lista[i].isEmpty == 0)
	        	{
	        		indice = i;
	        		break;
	        	}
	        }
	    }
	return indice;
}

int modificacionVivienda(eVivienda* lista, int tam)
{
	int allOk=0;
	int id;
	int indice;
	char confirma;
	int auxIdCatastro;
	char auxCalle[25];
	int auxCantidadPersonas;
	int auxCantidadHabitaciones;
	int auxTipoVivienda ;
	int auxLegajoCensista;

	if(lista!=NULL && tam>0)
	{
		system("cls");
		mostrarViviendas(lista, tam);
		printf("  Ingrese el ID a modificar: \n");
		scanf("%d", &id);
		indice=buscarViviendaId(lista, tam, id);
		if(indice==-1)
		{
			printf("no hay viviendas con ID ingresado. %d\n", id);
		}else
		{
			mostrarVivienda(lista[indice]);

			printf("confirma modificacion?: s/n \n");
			fflush(stdin);
			scanf("%c", &confirma);
			if(confirma=='s')
			{
				switch(menuModificacion())
				{
					case 1:
						pedirEntero(&auxIdCatastro, "ingrese id de catastro: 1000/avellaneda - 1001/lanus - 1002/quilmes - 1003/la plata - 1004/Lomas de Zamora \n","error, ingrese un catastro valido",1000,1004);
						(*(lista+indice)).idCatastro=auxIdCatastro;
						break;
					case 2:
						pedirCadena(auxCalle, "Ingrese nueva calle: \n");
						validarLetras(auxCalle);
						primerLetraMayuscula(auxCalle);
						strcpy((*(lista+indice)).calle, auxCalle);
						break;
					case 3:
						pedirEntero(&auxCantidadPersonas, "Ingrese nueva cantidad de personas: \n","error, ingrese un numero valido",1,20);
						(*(lista+indice)).cantidadPersonas=auxCantidadPersonas;
						break;

					case 4:
						pedirEntero( &auxCantidadHabitaciones,"Ingrese nueva cantidad de habitaciones: \n", "error, ingrese un numero valido", 1,10);
						(*(lista+indice)).cantidadHabitaciones=auxCantidadHabitaciones;
						break;

					case 5:
						pedirEntero(&auxTipoVivienda, "Ingrese nuevo tipo de vivienda: 1: Casa - 2: Departamento - 3: Casilla 4: Rancho  \n","error, ingrese una opcion valida",1,4);
						(*(lista+indice)).tipoVivienda= auxTipoVivienda;
						break;
					case 6:
						pedirEntero(&auxLegajoCensista,"ingrese numero de legajo: 100/ana - 101/juan - 102/sol \n","el censista ingresado no existe",100,102);
						(*(lista+indice)).legajoCensista=auxLegajoCensista;
						break;
					default:
						printf("opcion invalida. \n");
				}
				allOk=1;
			}else{
				printf("la modificacion se ha cancelado. \n");
			}
		}
	}
	return allOk;
}


// /////////////   BAJA VIVIENDA  ////////////////////////

int bajaVivienda(eVivienda* lista, int tam)
{
	int allOk;
	int id;
	int indice;
	char confirma;

	if(lista!=NULL && tam>0)
	{
		system("cls");

		printf("Ingrese ID: \n");
		scanf("%d", &id);

		indice=buscarViviendaId(lista, tam, id);

		if(indice==-1)
		{
			printf("No hay viviendas ingresadas con ID: %d\n", id);
		}else
		{
			mostrarVivienda(*(lista+indice));
			printf("confirma Baja?: s/n");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		if(confirma=='s')
		{
			(*(lista+indice)).isEmpty=1;
			allOk=1;
		}else
		{
			printf("La baja ha sido cancelada.");
		}

	}
	return allOk;

}


int flagReset(eVivienda* lista, int tam, int* flag)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if((*(lista+i)).isEmpty == 0)
            {
                *flag = 1;
                todoOk = 1;
                break;
            }
            else
            {
                *flag = 0;
            }
        }
    }
    return todoOk;
}




// //////PUNTO D: Hacer un único listado de todas las viviendas ordenados por calle y ante igualdad de calle por cantidad de personas. ////

int ordenarViviendaPorCalle(eVivienda* lista, int tam, int orden)
{
	eVivienda auxVivienda;
	int allOk=0;

	if(lista!=NULL && tam>0)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if(orden==1)
				{
					if((strcmp((*(lista+i)).calle , (*(lista+j)).calle )>0) || (strcmp((*(lista+i)).calle, (*(lista+j)).calle)==0 && (*(lista+i)).cantidadPersonas >(*(lista+j)).cantidadPersonas))
					{
						auxVivienda=(*(lista+i));
						(*(lista+i))=(*(lista+j));
						(*(lista+j))=auxVivienda;
					}
				}else
				{
					if(orden==0)
					{
						if((strcmp((*(lista+i)).calle, (*(lista+j)).calle)<0) || (strcmp((*(lista+i)).calle, (*(lista+j)).calle)==0 && (*(lista+i)).cantidadPersonas<(*(lista+j)).cantidadPersonas))
						{
							auxVivienda=(*(lista+i));
							(*(lista+i))=(*(lista+j));
							(*(lista+j))=auxVivienda;
						}
					}
				}
			}
		}mostrarViviendas(lista,tam);

		allOk=1;
	}
	return allOk;
}

int submenuListado(){
	int opcion;

	printf("Elija una opcion: \n");
	printf("1- orden ascendente. \n");
	printf("0- orden descendente. \n");

	scanf("%d", &opcion);

	return opcion;
}


int submenuTipoLocalidad(){
	int opcion;

	printf("Elija una opcion:  \n");
	printf("1- Avellaneda.     \n");
	printf("2- Lanús.          \n");
	printf("3- Quilmes         \n");
	printf("4- La Plata        \n");
	printf("5- Lomas de Zamora \n");

	scanf("%d", &opcion);

	return opcion;
}

int submenuTipoVivienda()
{
	int opcion;

	printf("Elija una opcion:  \n");
	printf("1- casa.           \n");
	printf("2- departamento.   \n");
	printf("3- casilla.         \n");
	printf("4- rancho.          \n");

	scanf("%d", &opcion);

	return opcion;
}

int submenuEligirCensista(){
	int opcion;

	printf("1- Ana. \n");
	printf("2- Juan.\n");
	printf("3- Sol. \n");

	scanf("%d", &opcion);

	return opcion;
}


int informarLista(eVivienda* lista, eCensista* listaC ,eCatastro* listaCat,int tamCat, int tam, int tamC)
{


	int allOk;
	int opcion;
	int orden;


	if(lista != NULL && tam>0 )
	{
		system("cls");
		printf("-------------------------\n");
		printf("     ****INFORME****     \n");
		printf("-------------------------\n");
		printf(">>  1. Listar viviendas: \n");
		printf(">>  2. Listar datos de Catastro. \n");
		printf(">>  3. Elegir un tipo de vivienda para mostrar todos los datos de la vivienda, nombre del censista y datos de catastro del tipo seleccionado.\n");
		printf(">>  4. Elegir una Localidad y mostrar todos los datos de la vivienda y nombre del censista de la Localidad seleccionada.\n");
		printf(">>  5. Cantidad de viviendas censadas en la localidad de Avellaneda. \n");
		printf(">>  6. Elegir un censista y mostrar todas las viviendas que censó con los datos de catastro.\n");
		printf(">>  7. Cantidad de viviendas de tipo “casa” censadas. \n");
		printf(">>  8. Cantidad de viviendas de tipo “departamento” de la localidad de Lanús. \n");

		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				orden=submenuListado();
				ordenarViviendaPorCalle(lista,tam,orden);
				break;

			case 2:
				mostrarCatastros(listaCat, tamCat);
				break;
			case 3:
				elegirTipoVivienda(lista,listaC,listaCat,tam,tamC,tamCat);
				break;
			case 4:
				elegirTipoLocalidad(lista,listaC,listaCat,tam,tamC,tamCat);
				break;
			case 5:
				cantViviendasCensadasAvellaneda(lista, listaCat,tam,tamCat);
				break;
			case 6:
				elegirCensista(lista,listaC,listaCat,tam,tamC,tamCat);
				break;
			case 7:
				cantDeTipoCasaCensadas(lista,tam);
				break;
			case 8:
				cantDepartamentosEnLanus(lista,listaCat,tam,tamCat);
				break;
		}allOk=1;
	}
	return allOk;
}

/*1-Elegir un tipo de vivienda y mostrar todos los datos de la vivienda, nombre del censista y datos de
catastro del tipo seleccionado.*/

int elegirTipoVivienda(eVivienda* lista, eCensista* listaC,eCatastro* listaCat, int tam , int tamC, int tamCat)
{

	int allOk=0;

	switch(submenuTipoVivienda())
	{
		case 1:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).tipoVivienda == 1 && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
					printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
					printf("------------------------------------------------------------------------------------------------------------------------------\n");
					printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

					mostrarVivienda(lista[i]);

					printf("nombre del censista: %s \n",
					listaC[i].nombre);

					printf(" id:%d   localidad:%s     manzana:%d     parcela:%d    \n",
							(*(listaCat+i)).idCatastro,
							(*(listaCat+i)).localidad,
							(*(listaCat+i)).manzana,
							(*(listaCat+i)).parcela);
					}
				}
			}
		break;
		case 2:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).tipoVivienda == 2 && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda((*(lista+i)));

						printf("nombre del censista: %s \n",
								(*(listaC+i)).nombre);

						printf(" id:%d   localidad:%s     manzana:%d     parcela:%d    \n",
								(*(lista+i)).idCatastro,
								(*(listaCat+i)).localidad,
								(*(listaCat+i)).manzana,
								(*(listaCat+i)).parcela);
					}
				}
			}
			break;
		case 3:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).tipoVivienda == 3 && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda(lista[i]);

						printf("nombre del censista: %s \n",
								(*(listaC+i)).nombre);

						printf(" id:%d   localidad:%s     manzana:%d     parcela:%d    \n",
								(*(lista+i)).idCatastro,
								(*(listaCat+i)).localidad,
								(*(listaCat+i)).manzana,
								(*(listaCat+i)).parcela);
					}
				}
			}
			break;
		case 4:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).tipoVivienda == 4 && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda((*(lista+i)));

						printf("nombre del censista: %s \n",
								(*(listaC+i)).nombre);

						printf(" id:%d   localidad:%s     manzana:%d     parcela:%d    \n",
								(*(lista+i)).idCatastro,
								(*(listaCat+i)).localidad,
								(*(listaCat+i)).manzana,
								(*(listaCat+i)).parcela);
					}
				}
			}
			break;
	}allOk=1;

	return allOk;

}

/*2-Elegir una Localidad y mostrar todos los datos de la vivienda y nombre del censista de la
Localidad seleccionada.*/

int elegirTipoLocalidad(eVivienda* lista, eCensista* listaC,eCatastro* listaCat, int tam , int tamC, int tamCat)
{
	int allOk=0;


	switch(submenuTipoLocalidad())
	{
		case 1:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).idCatastro == 1000  && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda(lista[i]);

						printf("nombre del censista de la localidad seleccionada: %s \n",
						listaC[i].nombre);

					}
				}
			}
		break;
		case 2:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).idCatastro == 1001  && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda((*(lista+i)));

						printf("nombre del censista de la localidad seleccionada: %s \n",
								(*(listaC+i)).nombre);

					}
				}
			}
			break;
		case 3:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).idCatastro == 1002  && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda((*(lista+i)));

						printf("nombre del censista de la localidad seleccionada: %s \n",
								(*(listaC+i)).nombre);

					}
				}
			}
			break;
		case 4:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).idCatastro == 1003  && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda((*(lista+i)));

						printf("nombre del censista de la localidad seleccionada: %s \n",
								(*(listaC+i)).nombre);

					}
				}
			}
			break;
		case 5:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamCat; j++)
				{
					if((*(lista+i)).idCatastro == 1004  && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda((*(lista+i)));

						printf("nombre del censista de la localidad seleccionada: %s \n",
								(*(listaC+i)).nombre);

					}
				}
			}
			break;
	}allOk=1;

	return allOk;
}

// 3-Cantidad de viviendas censadas en la localidad de Avellaneda.
int cantViviendasCensadasAvellaneda(eVivienda* lista,eCatastro* listaCat,int tam, int tamCat)
{
	int allOk=0;
	int contadorViviendasAvellaneda=0;

	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tamCat; j++)
		{
			if((*(lista+i)).idCatastro == 1000  && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro==(*(listaCat+j)).idCatastro)
			{
				contadorViviendasAvellaneda++;
			}
		}
	}printf("la cantidad de viviendas censadas en Avellenda son: %d \n",contadorViviendasAvellaneda);

	return allOk;
}

//4-Elegir un censista y mostrar todas las viviendas que censó con los datos de catastro.

int elegirCensista(eVivienda* lista,eCensista* listaC,eCatastro* listaCat,int tam, int tamC, int tamCat)
{
	int allOk=0;

	switch(submenuEligirCensista())
	{
		case 1:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamC; j++)
				{
					if((*(lista+i)).legajoCensista == 100  && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoCensista==(*(listaC+j)).legajoCensista)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda((*(lista+i)));

						printf(" id:%d   localidad:%s     manzana:%d     parcela:%d    \n",
								(*(lista+i)).idCatastro,
								(*(listaCat+i)).localidad,
								(*(listaCat+i)).manzana,
								(*(listaCat+i)).parcela);

					}
				}
			}break;
		case 2:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamC; j++)
				{
					if((*(lista+i)).legajoCensista == 101  && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoCensista==(*(listaC+j)).legajoCensista)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda(lista[i]);

						printf(" id:%d   localidad:%s     manzana:%d     parcela:%d    \n",
								(*(lista+i)).idCatastro,
								(*(listaCat+i)).localidad,
								(*(listaCat+i)).manzana,
								(*(listaCat+i)).parcela);

					}
				}
			}
			break;
		case 3:
			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamC; j++)
				{
					if((*(lista+i)).legajoCensista == 102  && (*(lista+i)).isEmpty==0 && (*(lista+i)).legajoCensista==(*(listaC+i)).legajoCensista)
					{
						printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf("                                                    ***LISTA VIVIENDAS***                                                     \n");
						printf("------------------------------------------------------------------------------------------------------------------------------\n");
						printf("|  id Vivenda   |   id Catastro   |     calle      |     cant Personas     |     cant Habitaciones     |     tipo de vivienda     |     legajoCensista     \n");

						mostrarVivienda((*(lista+i)));

						printf(" id:%d   localidad:%s     manzana:%d     parcela:%d    \n",
								(*(lista+i)).idCatastro,
								(*(listaCat+i)).localidad,
								(*(listaCat+i)).manzana,
								(*(listaCat+i)).parcela);

					}
				}
			}
			break;
	}allOk=1;

	return allOk;
}

//5-Cantidad de viviendas de tipo “casa” censadas.

int cantDeTipoCasaCensadas(eVivienda* lista,int tam)
{
	int allOk=0;
	int contadorViviendasTipoCasa=0;

	for(int i=0; i<tam; i++)
	{
			if((*(lista+i)).tipoVivienda == 1 && (*(lista+i)).isEmpty==0)
			{
				contadorViviendasTipoCasa++;

			}

	}printf("la cantidad de viviendas censadas de tipo Casa son: %d \n",contadorViviendasTipoCasa);

	return allOk;
}

//6-Cantidad de viviendas de tipo “departamento” de la localidad de Lanús.

int cantDepartamentosEnLanus(eVivienda* lista,eCatastro* listaCat,int tam,int tamCat)
{
	int allOk=0;

	int contadorViviendasDepart=0;

	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tamCat; j++)
		{
			if((*(lista+i)).tipoVivienda == 2  && (*(lista+i)).isEmpty==0 && (*(lista+i)).idCatastro == (*(listaCat+j)).idCatastro)
			{
				if(lista[i].idCatastro == 1001)
				{
					contadorViviendasDepart++;
				}

			}
		}
	}printf("la cantidad de viviendas censadas de tipo “departamento” en la localidad de Lanus son: %d \n",contadorViviendasDepart);

	return allOk;
}

