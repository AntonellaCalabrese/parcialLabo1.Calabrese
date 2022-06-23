/*
 * controller.c
 *
 *  Created on: 20 jun 2022
 *      Author: antonella
 */

/*
 * controller.c
 *
 *  Created on: 18 jun 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#include "servicios.h"
#include "utn.h"
#include "linkedList.h"
#include "controller.h"
#include "parser.h"

/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief Carga los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * @param path Nombre del archivo a cargar.
 * @param pArrayListaServicios Puntero a la lista de servicios.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_loadFromText(LinkedList* pArrayListaServicios)
{
	int todoOk = 0;
	FILE* f;
	char path[20];

	if(pArrayListaServicios != NULL)
	{
	    ll_clear(pArrayListaServicios);
	    printf("Ingrese el nombre del archivo a cargar. -servicios.csv-\n");
        fflush(stdin);
        gets(path);

		f = fopen(path, "r");

        if(f != NULL)
        {
        	parser_ServicioFromText(f, pArrayListaServicios);
            printf("Lista cargada exitosamente!!\n");
            todoOk = 1;
        }
        else
        {
            printf("No existe una lista con ese nombre.\n");
        }
	}

    return todoOk;
}

/**
 * @fn int controller_MostrarServicios(LinkedList*)
 * @brief funcion para mostrar los datos de los Servicio
 *
 * @param pArrayListaServicios Puntero a la lista de Servicio.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk
 */
int controller_MostrarServicios(LinkedList* pArrayListaServicios)
{
	int todoOk = 0;
	eServicios* newServicio ;
	if(pArrayListaServicios != NULL)
	{
		printf("                         *** Listado del Servicio ***\n");
		printf("-----------------------------------------------------------------------------------------------------------\n");
		printf("|Id   |descripcion       |Tipo Servicio       |Precio  Unitario       |Cantidad       |Total Servicio      \n");
		printf("-----------------------------------------------------------------------------------------------------------\n");


		for(int i = 0; i < ll_len(pArrayListaServicios); i++)
		{
			newServicio = ll_get(pArrayListaServicios, i);
			if(newServicio != NULL)
			{
				servicio_mostrarServicio(newServicio);
				todoOk = 1;
			}
		}
	}
    return todoOk;
}

/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief Guarda los datos de los servicios en el archivo data.csv (modo texto).
 *
 * @param path Nombre del archivo a guardar.
 * @param pArrayListaServicios Puntero a la lista de servicios.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListaServicios)
{
	int todoOk=0;
	FILE* f;
	int id_servicio;
	char descripcion[120];
	int tipoServicio;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	eServicios* nuevoServicio;

	if(path != NULL && pArrayListaServicios != NULL)
	{
		f = fopen(path, "w");

		nuevoServicio = newServicio();

		fprintf(f, "id_servicio,descripcion,tipoServicio,precioUnitario,cantidad,totalServicio\n");

		for(int i = 0; i < ll_len(pArrayListaServicios); i++)
		{
			nuevoServicio = ll_get(pArrayListaServicios, i);
			if(nuevoServicio != NULL)
			{
				servicio_getId(nuevoServicio, &id_servicio);
				servicio_getDescripcion(nuevoServicio, descripcion);
				servicio_getTipoServicio(nuevoServicio, &tipoServicio);
				servicio_getPrecioUnitario(nuevoServicio, &precioUnitario);
				servicio_getCantidad(nuevoServicio, &cantidad);
				servicio_getTotalServicio(nuevoServicio, &totalServicio);

				fprintf(f, "%d,%s,%d,%f,%d,%f\n",id_servicio,descripcion,tipoServicio,precioUnitario,cantidad,totalServicio);
				todoOk = 1;
			}
			else
			{
				todoOk = 0;
				break;
			}
		}
		fclose(f);
	}
    return todoOk;
}
// punto 3

/**
 * @fn int controller_asignarTotales(LinkedList*)
 * @brief funcion para asignar el precio total de los servicios
 *
 * @param pArrayListaServicios  Puntero a la lista de servicios.
 * @return retorna 1 si todo salio bien
 */
int controller_asignarTotales(LinkedList* pArrayListaServicios)
{
    int todoOk = 0;

    if(pArrayListaServicios != NULL)
    {
        ll_map(pArrayListaServicios, asignarTotales);
        printf("Se asigno correctamente el total calculado a cada servicio\n");
        todoOk = 1;
    }
    return todoOk;
}

// punto 4
/**
 * @fn int controller_FiltroTipoMinorista(LinkedList*)
 * @brief funcion para filtrar los servicios de tipo Minorista
 *
 * @param pArrayListaServicios  Puntero a la lista de servicios.
 * @return retorna 1 si todo salio bien, 0 si salio mal
 */
int controller_FiltroTipoMinorista(LinkedList* pArrayListaServicios)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaServicios != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaServicios, servicios_filtrarTipoMinorista);
        controller_MostrarServicios(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("servicioTipoMinorista.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

/**
 * @fn int controller_FiltroTipoMayorista(LinkedList*)
 * @brief funcion para filtrar los servicios de tipo mayorista
 *
 * @param pArrayListaServicios  Puntero a la lista de servicios.
 * @return  retorna 1 si todo salio bien, 0 si salio mal
 */
int controller_FiltroTipoMayorista(LinkedList* pArrayListaServicios)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaServicios != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaServicios, servicios_filtrarTipoMayorista);
        controller_MostrarServicios(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("servicioTipoMayorista.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

/**
 * @fn int controller_FiltroTipoExportar(LinkedList*)
 * @brief funcion para filtrar los servicios de tipo Exportar
 *
 * @param pArrayListaServicios  Puntero a la lista de servicios.
 * @return retorna 1 si todo salio bien, 0 si salio mal
 */
int controller_FiltroTipoExportar(LinkedList* pArrayListaServicios)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaServicios != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaServicios, servicios_filtrarTipoExportar);
        controller_MostrarServicios(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("servicioTipoExportar.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

// punto 5

/**
 * @fn int controller_sortDescripcion(LinkedList*)
 * @brief funcion para ordenar de manera ascendente las descripciones del servicio
 *
 * @param pArrayListaServicios  Puntero a la lista de servicios.
 * @return retorn 1 si todo salio bien, si salio mal 0
 */
int controller_sortDescripcion(LinkedList* pArrayListaServicios)
{
	int todoOk = 0;
	int criterio;


	if(pArrayListaServicios != NULL)
	{
		criterio = menuDeSort();
		if(ll_isEmpty(pArrayListaServicios) == 0)
		{
			ll_sort(pArrayListaServicios, servicio_SortDescripcion, criterio);
            controller_MostrarServicios(pArrayListaServicios);
            printf("Ordenamiento de manera Ascendente exitoso!!!\n");
            todoOk = 1;
		}
		else
		{
			printf("La lista esta vacia y no se puede ordenar\n");
			todoOk=0;
		}

		ll_deleteLinkedList(pArrayListaServicios);

	}
    return todoOk;
}

