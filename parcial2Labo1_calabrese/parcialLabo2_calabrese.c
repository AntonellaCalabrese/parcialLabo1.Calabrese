/*
 ============================================================================
 Name        : parcialLabo2_calabrese.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "controller.h"
#include "servicios.h"
#include "utn.h"
#include "parser.h"
#include "linkedList.h"




int main(void)
{
	setbuf(stdout,NULL);

	    char seguir = 'n';
	    int flag=0;
	    int respuestaMenuPrincipal;
	    int opcionElegida;

	    char path[20];


	    LinkedList* listaServicios = ll_newLinkedList();
	    do{
	    		respuestaMenuPrincipal=getNumero(&opcionElegida, " ***Ingrese una de las opciones: *** \n 1. Cargar el archivo \n 2. Imprimir lista \n 3. Asignar totales \n 4. Filtrar por tipo \n 5. Mostrar servicios: \n 6. Guardar servicios \n 7. Salir\n", "reingrese la opcion elegida",1,7,3);
	    		if(respuestaMenuPrincipal==0)
	    		{
	    			switch(opcionElegida)
	    			{
	    			case 1:
	    				controller_loadFromText(listaServicios);
	    				break;
	    			case 2:
	    				if(!ll_isEmpty(listaServicios))
	    				{
	    					controller_MostrarServicios(listaServicios);
	    				}
	    				else
	    				{
	    					printf("Debe cargar una lista para poder mostrar los servicios\n");
	    				}

	    				break;
	    			case 3:
	    				if(!ll_isEmpty(listaServicios))
	    				{
	    					controller_asignarTotales(listaServicios);
	    				}
	    				else
	    				{
	    					printf("Debe cargar una lista para poder asignar totales a los servicios\n");
	    				}
	    			break;
	    				case 4:
	    				    if(!ll_isEmpty(listaServicios))
	    	                {
	    	                    switch(menuDeServicios())
	    	                    {
	    	                        case 1:
	    	                            controller_FiltroTipoMinorista(listaServicios);
	    	                            break;
	    	                        case 2:
	    	                            controller_FiltroTipoMayorista(listaServicios);
	    	                            break;
	    	                        case 3:
	    	                            controller_FiltroTipoExportar(listaServicios);
	    	                            break;
	    	                    }
	    	                }
	    	                else
	    	                {
	    	                    printf("Debe cargar una lista para poder filtrar los servicios\n");
	    	                }
	    					break;
	    				case 5:
	    				    if(!ll_isEmpty(listaServicios))
	    	                {
	    				    	controller_sortDescripcion(listaServicios);
	    	                }
	    	                else
	    	                {
	    	                 printf("Debe cargar una lista antes de ordenar las descripciones\n");
	    	                }
	    					break;
	    				case 6:
	    				    if(!ll_isEmpty(listaServicios))
	    	                {
	    	                    printf("Con que nombre quiere guardar el archivo?(Recuerde poner .csv al final del nombre)\n");
	    	                    fflush(stdin);
	    	                    gets(path);
	    	                    controller_saveAsText(path, listaServicios);
	    	                    printf("Guardado exitoso\n");
	    	                }
	    	                else
	    	                {
	    	                    printf("Debe cargar una lista para poder guardarla\n");
	    	                }
	    				    flag=1;
	    					break;
	    				case 7:
	    					if(flag==1)
	    					{
								pedirCaracter(&seguir, "Esta seguro que desea salir? s(si) y n(no).", "Error. letra invalida. Ingrese s si desea salir o n para continuar.", 's', 'n');
								fflush(stdin);
								if(seguir == 's')
								{
									ll_deleteLinkedList(listaServicios);
									printf("Gracias por todo. Hasta la proxima!!!\n");
								}
	    					}
	    					else
	    					{
	    						printf("primero debe guardar el archivo para poder salir");
	    					}
	    					break;
	    				default:
	    					printf("Opcion invalida!!!\n");
	    					break;
	    			}

	    		}
	    			system("pause");
	    }while(seguir == 'n');
	    return 0;
}

