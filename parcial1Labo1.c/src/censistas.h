/*
 * censistas.h
 *
 *  Created on: 20 may 2022
 *      Author: Antonella Calabrese
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef CENSISTAS_H_
#define CENSISTAS_H_

/**
 * @struct eCensistas
 * @brief estructura de los censitas que contiene la informacion de cada censista
 *
 */

typedef struct{
	int legajoCensista;
	char nombre[20];
	int edad;
	char telefono[16];

}eCensista;


#endif /* CENSISTAS_H_ */

/**
 * @fn void inicializarCensista(eCensista*)
 * @brief función de tipo void que inicializa los datos harcodeados de manera forzada de los censistas.
 *
 * @param listaC cantidad de estructuras eCensista
 */
void inicializarCensista(eCensista* listaC);

/**
 * @fn int mostrarCensistas(eCensista*, int)
 * @brief funcion de tipo entero que imprime por pantalla los campos de todos los cencistas
 *
 * @param listaC campos de la estructura eCencista
 * @param tamC cantidad de estructuras eCensista
 * @return retorna 1 si todo salio bien al mostrar los censistas
 */
int mostrarCensistas(eCensista* listaC, int tamC);


/**
 * @fn void mostrarCensista(eCensista)
 * @brief funcion de tipo void que muestra los campos de un solo censista
 *
 * @param censista
 */
void mostrarCensista(eCensista censista);


