/*
 ============================================================================
 Name        : c.c
 Author      : Antonella Calabrese
 Version     :
 Copyright   : Your copyright notice
 Description : parcial labo 1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input-UTN.h"
#include "censistas.h"
#include "viviendas.h"
#include "catastro.h"

#define TAM 20000

#define TAMC 3

#define TAMCAT 5

int main(void)
{
	setbuf(stdout, NULL);
	eVivienda lista[TAM];
	eCensista listaC[TAMC];
	eCatastro listaCat[TAMCAT];
	//eCatastro listaCat[TAMCAT];
	int respuestaMenuPrincipal;
	int opcionElegida;
	int seguir='s';
	int nextId=20000;
	int flag=0;


	if(inicializarVivienda(lista, TAM) == -1)
	{
	    printf("Hubo un problema al inicializar la vivienda.");
	}

	inicializarCensista(listaC);
	inicializarHardCatastro(listaCat);

	do{
		respuestaMenuPrincipal=getNumero(&opcionElegida, " ***Ingrese una de las opciones: *** \n >>1. Alta  \n >>2. Modificar \n >>3. Baja: \n >>4. Informar:  \n >>5. Listar Cencista \n >>6. Listar Catastro-ordenado por Localidad \n >>7. salir\n", "reingrese la opcion elegida",1,7,3);
		if(respuestaMenuPrincipal==0)
		{
			switch(opcionElegida)
			{
	    		case 1:
	    			if(altaVivienda(lista,listaC,listaCat, TAM ,TAMC,TAMCAT, &nextId))
	    			{
	    			   mostrarViviendas(lista,TAM);
	    			   printf("Alta exitosa!!\n");
	    			   flag=1;
	    			}else
	    			{
	    			   printf("No hay viviendas para registrar\n");
	    			}
	    		break;
	    		case 2:
	    			if(flag==0)
	    			{
	    			   printf("No hay viviendas para modificar. \n");
	    			}
	    			else
	    			{
	    			    if(modificacionVivienda(lista, TAM))
	    			    {
	    			    	printf("Modificacion Exitosa \n");
	    			    }
	    			    else
	    			    {
	    			    	printf("Hubo un problema haciendo la modificacion. \n");
	    			    }
	    			}
	    			break;
	    		case 3:
    				if(flag==0)
    				{
    					printf("No hay viviendas para dar de Baja \n");
    				}
    				else
    				{
    					if(bajaVivienda(lista, TAM))
    					{
    						printf("Baja exitosa. \n");
    						flagReset(lista, TAM, &flag);
    					}
    					else
    					{
    						printf("Hubo un problema al hacer la Baja. \n");
    					}
    				}
	    			break;
	    		case 4:
    				if(flag==0)
					{
    					printf("No hay viviendas para informar. \n");
					}else
					{
						if(informarLista(lista,listaC,listaCat,TAMCAT,TAM,TAMC))
						{

							printf("Lista informada. \n");
						}else
						{
							printf("Hubo un problema al informar. \n");
						}
					}
	    			break;
	    		case 5:
	    			    if(mostrarCensistas(listaC, TAMC))
	    			    {
	    			    	printf("censistas mostrados exitosamente \n");
	    			    }
	    			    else
	    			    {
	    			    	printf("Hubo un problema al mostrar Censistas. \n");
	    			    }

	    			break;
	    		case 6:
    			    if(ListarCatastros(listaCat, TAMCAT))
    			    {
    			    	printf("el catastro fue mostrado exitosamente \n");
    			    }
    			    else
    			    {
    			    	printf("Hubo un problema al mostrar el catastro. \n");
    			    }
    			flag=1;
	    			break;
	    		case 7:
	    			seguir='n';
	    		break;
	    			default:
	    			printf("opcion invalida\n\n");
	    		}
			}
	    }
	    while(seguir == 's');
		return EXIT_SUCCESS;
}
