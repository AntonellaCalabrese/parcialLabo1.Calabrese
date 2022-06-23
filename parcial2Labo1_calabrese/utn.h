/*
 * utn.h
 *
 *  Created on: 18 jun 2022
 *      Author: antonella
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
int menuDeSort();

int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);

int pedirCadena(char* cadena, char* mensaje);

int primerLetraMayuscula(char name[]);

int validarLetras(char string[]);

int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2);
int menuDeServicios();
