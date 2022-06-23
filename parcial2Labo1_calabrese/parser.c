/*
 * parser.c
 *
 *  Created on: 18 jun 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#include "servicios.h"
#include "controller.h"
#include "linkedList.h"

/**
 * @fn int parser_PassengerFromText(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los servicios desde el archivo servicios.csv (modo texto).
 *
 * @param pFile Direccion de memoria del archivo que sera parseado.
 * @param pArrayListServicios puntero a la lista de servicios.
 * @return Retorna 1 si esta todo OK y 0 si fallo.
 */
int parser_ServicioFromText(FILE* pFile , LinkedList* pArrayListServicios)
{
	int allOk = -1;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	eServicios* newServicio=NULL;
	int r=0;

	pFile=fopen("servicios.csv","r");
	if(pFile==NULL)
	{
		printf("El archivo es nulo");
	}

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);

	while(!feof(pFile))
	{
		r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
		if(r<6)
		{
			break;
		}
		newServicio = servicios_NewParametros(var1,var2,var3,var4,var5,var6);

		if(newServicio!=NULL)
		{
			ll_add(pArrayListServicios,newServicio);
			allOk=1;
		}
	}
	fclose(pFile);

	return allOk;
}



