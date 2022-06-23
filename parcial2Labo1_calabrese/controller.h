/*
 * controller.h
 *
 *  Created on: 20 jun 2022
 *      Author: antonella
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "linkedList.h"

#endif /* CONTROLLER_H_ */
int controller_loadFromText(LinkedList* pArrayListaServicios);

int controller_MostrarServicios(LinkedList* pArrayListaServicios);

int controller_saveAsText(char* path , LinkedList* pArrayListaServicios);

int controller_asignarTotales(LinkedList* pArrayListaServicios);

int controller_FiltroTipoMinorista(LinkedList* pArrayListaServicios);

int controller_FiltroTipoMayorista(LinkedList* pArrayListaServicios);

int controller_FiltroTipoExportar(LinkedList* pArrayListaServicios);

int controller_sortDescripcion(LinkedList* pArrayListaServicios);

