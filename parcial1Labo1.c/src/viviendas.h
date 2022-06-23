/*
 * viviendas.h
 *
 *  Created on: 25 may 2022
 *      Author: Antonella Calabrese
 */
#include <stdio.h>
#include <stdlib.h>
#include "catastro.h"
#include "censistas.h"
#ifndef VIVIENDAS_H_
#define VIVIENDAS_H_

typedef struct{
	int  tipoVivienda;
	char descripcion[20];
}eTipoVivienda;


typedef struct{
    int idVivienda;
    int idCatastro;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda ;
	int legajoCensista;
	int isEmpty;
}eVivienda;


#endif /* VIVIENDAS_H_ */
/**
 * @fn int inicializarVivienda(eVivienda*, int)
 * @brief funcion de tipo entero que recibe por parametro la estructura de viviendas y el tamaño
 *
 * @param lista
 * @param tam
 * @return devuelve 0 si todo salio bien
 */
int inicializarVivienda(eVivienda* lista, int tam);

/**
 * @fn int altaVivienda(eVivienda*, eCensista*, int, int, int*)
 * @brief funcion de tipo entero para dar de alta una vivienda
 *
 * @param lista  la estructura evivienda
 * @param listaC lista de la estructura ecensista
 * @param tam tamaño de las viviendas
 * @param tamC tamaño de los censistas
 * @param pId puntero a id
 * @return retorna 1 si todo salio bien
 */
int altaVivienda(eVivienda* lista,eCensista* listaC,eCatastro* listaCat, int tam,int tamC,int tamCat, int* pId);

/**
 * @fn int buscarLibre(eVivienda*, int)
 * @brief funcion de tipo entero para buscar una estructura de vivienda libre
 *
 * @param lista le paso la lista
 * @param tam le paso el tamaño
 * @return retorna el indice de donde encontro una estructura libre
 */
int buscarLibre(eVivienda* lista, int tam);

/**
 * @fn int mostrarViviendas(eVivienda*, int)
 * @brief funcion para mostrar todas las viviendas
 *
 * @param lista lista de la vivienda
 * @param tam tamaño de las viviendas
 * @return retorna 1 si todo salio bien
 */
int mostrarViviendas(eVivienda* lista, int tam);

/**
 * @fn void mostrarVivienda(eVivienda)
 * @brief funcion para mostrar 1 sola vivienda
 *
 * @param unaVivienda
 */
void mostrarVivienda(eVivienda unaVivienda);

/**
 * @fn int menuModificacion()
 * @brief funcion para que el usuario eliga una de las opciones
 *
 * @return retorna la opcion elegida
 */
int menuModificacion();

/**
 * @fn int modificacionVivienda(eVivienda*, int)
 * @brief funcion para que el usuario modifique los datos de uno de los campos de la estructura vivienda
 *
 * @param lista
 * @param tam
 * @return retorna 1 si todo salio bien
 */
int modificacionVivienda(eVivienda* lista, int tam);

/**
 * @fn int buscarViviendaId(eVivienda*, int, int)
 * @brief con esta funcion buscamos el id de la estructura vivienda
 *
 * @param lista
 * @param tam
 * @param idVivienda
 * @return retorna el indice de la estructura
 */
int buscarViviendaId(eVivienda* lista, int tam, int idVivienda);

/**
 * @fn int bajaVivienda(eVivienda*, int)
 * @brief funcion para dar de baja una vivienda
 *
 * @param lista
 * @param tam
 * @return retorna 1 si todo salio bien
 */
int bajaVivienda(eVivienda* lista, int tam);

/**
 * @fn int flagReset(eVivienda*, int, int*)
 * @brief
 *
 * @param list
 * @param tam
 * @param flag
 * @return retorna 1 si todo salio bien
 */
int flagReset(eVivienda* list, int tam, int* flag);

/**
 * @fn int submenuListado()
 * @brief funcion para elegir la opcion elegida por el usuario
 *
 * @return retorna la opcion elegida
 */
int submenuListado();

/**
 * @fn int ordenarViviendaPorCalle(eVivienda*, int, int)
 * @brief funcion para hacer un listado de todas las viviendas ordenados por calle y ante igualdad de calle por cantidad de personas.
 *
 * @param lista
 * @param tam
 * @param orden ordena 1 en ascendente y 0 descendente
 * @return retorna 1 si todo salio bien
 */
int ordenarViviendaPorCalle(eVivienda* lista, int tam, int orden);

/**
 * @fn int informarLista(eVivienda*, int)
 * @brief funcion para informar
 *
 * @param lista
 * @param tam
 * @return retorna 1 si todo salio bien
 */
int getCantViviendaUsadas(eVivienda* lista);

int listadoViviendayCensista(eVivienda* lista,eCensista* listaC);

int submenuTipoLocalidad();

int informarLista(eVivienda* lista, eCensista* listaC ,eCatastro* listaCat,int tamCat, int tam, int tamC);

int elegirTipoVivienda(eVivienda* lista, eCensista* listaC,eCatastro* catastro, int tam , int tamC, int tamCat);

int elegirTipoLocalidad(eVivienda* lista, eCensista* listaC,eCatastro* listaCat, int tam , int tamC, int tamCat);

int cantViviendasCensadasAvellaneda(eVivienda* lista,eCatastro* listaCat,int tam, int tamCat);

int elegirCensista(eVivienda* lista,eCensista* listaC,eCatastro* listaCat,int tam, int tamC, int tamCat);

int cantDeTipoCasaCensadas(eVivienda* lista,int tam);

int cantDepartamentosEnLanus(eVivienda* lista,eCatastro* listaCat,int tam,int tamCat);
