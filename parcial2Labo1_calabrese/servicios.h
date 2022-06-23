/*
 * servicios.h
 *
 *  Created on: 18 jun 2022
 *      Author: antonella
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct{
	int id_servicio;
	char descripcion[120];
	int tipoServicio;
	float precioUnitario;
	int cantidad;
	float totalServicio;
	int isEmpty;
}eServicios;

#endif /* SERVICIOS_H_ */
eServicios* newServicio();

eServicios* servicios_NewParametros(char* idStr ,char* descripcionStr, char* tipoServicioStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr);

int servicio_mostrarServicio(eServicios* unServicio);

void eliminarServicio(eServicios* unServicio);

int servicio_setId(eServicios* unServicio, int idServicio);

int servicio_getId(eServicios* this,int* idServicio);

int servicio_setDescripcion(eServicios* this,char* descripcionServicio);

int servicio_getDescripcion(eServicios* this, char* descripcionServicio);

int servicio_setTipoServicio(eServicios* this,int tipoServicio);

int servicio_getTipoServicio(eServicios* this, int* tipoServicio);

int servicio_setPrecioUnitario(eServicios* this,float precioUnitario);

int servicio_getPrecioUnitario(eServicios* this, float* precioUnitario);

int servicio_setCantidad(eServicios* this,int cantidadServicio);

int servicio_getCantidad(eServicios* this, int* cantidadServicio);

int servicio_setTotalServicio(eServicios* this,float totalServicio);

int servicio_getTotalServicio(eServicios* this, float* totalServicio);
//3
void* asignarTotales(void* elemento);
//4
int servicios_filtrarTipoMinorista(void* elemento);
int servicios_filtrarTipoMayorista(void* elemento);
int servicios_filtrarTipoExportar(void* elemento);
//5
int servicio_SortDescripcion(void* item1, void* item2);
