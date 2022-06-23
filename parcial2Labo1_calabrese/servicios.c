/*
 * servicios.c
 *
 *  Created on: 18 jun 2022
 *      Author: antonella
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "linkedList.h"
#include "utn.h"
#include "servicios.h"
#include <string.h>

eServicios* newServicio()
{
	eServicios* newServicio;

	newServicio = (eServicios*) malloc(sizeof(eServicios));
	if(newServicio != NULL)
	{
		newServicio->id_servicio = 0;
		strcpy(newServicio->descripcion, "-");
		newServicio->tipoServicio= 0;
		newServicio->precioUnitario = 0;
		newServicio->cantidad = 0;
		newServicio->totalServicio = 0;
	}

	return newServicio;
}

eServicios* servicios_NewParametros(char* idStr ,char* descripcionStr, char* tipoServicioStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr)
{
	eServicios* ServicioNuevo;

	ServicioNuevo = newServicio();
	if(ServicioNuevo != NULL)
	{
		if(!(servicio_setId(ServicioNuevo, atoi(idStr))
		   && servicio_setDescripcion(ServicioNuevo, descripcionStr)
		   && servicio_setTipoServicio(ServicioNuevo, atoi(tipoServicioStr))
		   && servicio_setPrecioUnitario(ServicioNuevo, atof(precioUnitarioStr))
		   && servicio_setCantidad(ServicioNuevo, atoi(cantidadStr))
		   && servicio_setTotalServicio(ServicioNuevo, atof(totalServicioStr))
		   ))
		   {
				eliminarServicio(ServicioNuevo);
				ServicioNuevo = NULL;
		   }
	}
	return ServicioNuevo;
}

int servicio_mostrarServicio(eServicios* unServicio)
{
	int allOk=0;
	int id_servicio;
	char descripcion[120];
	int tipoServicio;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	if(unServicio != NULL)
	{
		servicio_getId(unServicio, &id_servicio);
		servicio_getDescripcion(unServicio, descripcion);
		servicio_getTipoServicio(unServicio, &tipoServicio);
		servicio_getPrecioUnitario(unServicio, &precioUnitario);
		servicio_getCantidad(unServicio, &cantidad);
		servicio_getTotalServicio(unServicio, &totalServicio);

		printf("%d    %-25s   %d             %.2f                   %-4d             %.2f\n",id_servicio,descripcion,tipoServicio,precioUnitario,cantidad,totalServicio);
		allOk=1;
	}

	return allOk;
}

void eliminarServicio(eServicios* unServicio)
{
	free(unServicio);
}



int servicio_setId(eServicios* unServicio, int idServicio)
{
	int todoOk = 0;
	if(unServicio != NULL && idServicio > 0)
	{
		unServicio->id_servicio = idServicio;
		todoOk = 1;
	}
	else
	{
		printf("Id Invalido\n");
	}
	return todoOk;
}
int servicio_getId(eServicios* this,int* idServicio)
{
	int todoOk = 0;
	if(this != NULL && idServicio != NULL)
	{
		*idServicio = this->id_servicio;
		todoOk = 1;
	}
	return todoOk;
}

// ///////

int servicio_setDescripcion(eServicios* this,char* descripcionServicio)
{
	int allOk=0;

	if(this != NULL && descripcionServicio != NULL)
	{
		strcpy(this->descripcion,descripcionServicio);
	}
	allOk=1;

    return allOk;
}
int servicio_getDescripcion(eServicios* this, char* descripcionServicio)
{
	int allOk = 0;
	if(this != NULL && descripcionServicio != NULL)
	{
		strcpy(descripcionServicio, this->descripcion);
		allOk = 1;
	}
	return allOk;
}


// ////////

int servicio_setTipoServicio(eServicios* this,int tipoServicio)
{
	int allOk=0;

	if(this != NULL && tipoServicio >0)
	{
		this->tipoServicio = tipoServicio;
	}
	allOk=1;

    return allOk;
}
int servicio_getTipoServicio(eServicios* this, int* tipoServicio)
{
	int allOk = 0;
	if(this != NULL && tipoServicio >0)
	{
		*tipoServicio= this->tipoServicio;
		allOk = 1;
	}
	return allOk;
}

// //////

int servicio_setPrecioUnitario(eServicios* this,float precioUnitario)
{
	int allOk=0;

	if(this != NULL && precioUnitario > 0 && precioUnitario <= 1000000000)
	{
		this->precioUnitario= precioUnitario;
	}
	allOk=1;

    return allOk;
}
int servicio_getPrecioUnitario(eServicios* this, float* precioUnitario)
{
    int allOk=0;

    if(this != NULL && precioUnitario != 0)
    {
    	*precioUnitario=this->precioUnitario;
    	allOk=1;
    }

    return allOk;
}


// ///////////

int servicio_setCantidad(eServicios* this,int cantidadServicio)
{
	int allOk=0;

	if(this != NULL && cantidadServicio > 0 && cantidadServicio <= 100)
	{
		this->cantidad= cantidadServicio;
	}
	allOk=1;

    return allOk;
}
int servicio_getCantidad(eServicios* this, int* cantidadServicio)
{
    int allOk=0;

    if(this != NULL && cantidadServicio != 0)
    {
    	*cantidadServicio=this->cantidad;
    	allOk=1;
    }

    return allOk;
}


// /////////////

int servicio_setTotalServicio(eServicios* this,float totalServicio)
{
	int allOk=0;

	if(this != NULL && totalServicio > 0 && totalServicio <= 1000000000)
	{
		this->totalServicio= totalServicio;
	}
	allOk=1;

    return allOk;
}
int servicio_getTotalServicio(eServicios* this, float* totalServicio)
{
    int allOk=0;

    if(this != NULL && totalServicio != 0)
    {
    	*totalServicio=this->totalServicio;
    	allOk=1;
    }

    return allOk;
}



void* asignarTotales(void* elemento)
{
	eServicios* unServicio = NULL;
	unServicio = (eServicios*) elemento;
	int cantidad;
	servicio_getCantidad(unServicio, &cantidad);
	float precioUnitario;
	servicio_getPrecioUnitario(unServicio, &precioUnitario);
	int total;

	if(elemento != NULL)
	{
		total=precioUnitario*cantidad;
		servicio_setTotalServicio(unServicio, total);
	}
	return unServicio;
}

int servicios_filtrarTipoMinorista(void* elemento)
{
	eServicios* aux = NULL;
	int todoOk = 0;
	aux = (eServicios*)elemento;


	if(aux != NULL)
	{
		if (aux->tipoServicio == 1)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int servicios_filtrarTipoMayorista(void* elemento)
{
	eServicios* aux = NULL;
	int todoOk = 0;
	aux = (eServicios*)elemento;


	if(aux != NULL)
	{
		if (aux->tipoServicio == 2)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int servicios_filtrarTipoExportar(void* elemento)
{
	eServicios* aux = NULL;
	int todoOk = 0;
	aux = (eServicios*)elemento;


	if(aux != NULL)
	{
		if (aux->tipoServicio == 3)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int servicio_SortDescripcion(void* item1, void* item2)
{
	int todoOk = 0;
	eServicios* servicio1 = NULL;
	eServicios* servicio2 = NULL;
	char descripcion1[130];
	char descripcion2[130];

	servicio1 = (eServicios*) item1;
	servicio2 = (eServicios*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(servicio_getDescripcion(servicio1, descripcion1)==1 && servicio_getDescripcion(servicio2, descripcion2)==1)
		{
			if(strcmp(descripcion1, descripcion2)>0)
			{
				todoOk = 1;
			}
			else if(strcmp(descripcion1, descripcion2)<0)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}
