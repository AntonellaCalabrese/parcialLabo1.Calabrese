/*
 * catastro.h
 *
 *  Created on: 16 jun 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef CATASTRO_H_
#define CATASTRO_H_

typedef struct{
	int idCatastro;
	char localidad[25];
	int manzana;
	int parcela;
}eCatastro;



#endif /* CATASTRO_H_ */
void inicializarHardCatastro(eCatastro* listaCat);

void mostrarCatastro(eCatastro catastro);

int mostrarCatastros(eCatastro* listaCat, int tamCat);

int listarCatastroPorLocalidad(eCatastro* lista, int tam, int orden);

int ListarCatastros(eCatastro* listaCat,int tamCat);
