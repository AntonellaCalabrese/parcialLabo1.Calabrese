/*
 * input-UTN.h
 *
 *  Created on: 19 may 2022
 *      Author: antonella
 */

#ifndef INPUT_UTN_H_
#define INPUT_UTN_H_



#endif /* INPUT_UTN_H_ */
/**
 * @fn int getNumero(int*, char*, char*, int, int, int)
 * @brief con esta funcion valido que el usuario solo ingrese numeros.
 *
 * @param pResultado variable de tipo entera con puntero donde se almacena la opcion elegida por el usuario del menú.
 * @param mensaje variable de tipo char con puntero donde se almacena el mensaje para mostrar en pantalla para que el usuario decida cual opcion elegir.
 * @param msjError variable de tipo char con puntero donde se almacena el mensaje de error si el cliente no accede bien a las opciones del menú.
 * @param min variable de tipo entera donde se almacena el minimo de numeros que puede el usuario seleccionar en el menú.
 * @param max variable de tipo entera donde se almacena el maximo de numeros que puede el usuario seleccionar en el menú.
 * @param reintentos variable de tipo entera donde se almacena la cant de veces que el usuario se puede equivocar para entrar al menú correctamente.
 * @return el return devuelve a getNumero la opcion elegida del menú por el usuario.
 */
int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief con esta funcion valida que el usuario solo ingrese enteros
 *
 * @param entero variable de tipo entera que permite que el usuario solo ingrese enteros.
 * @param mensaje variable de tipo entera que almacena el msj a imprimir en pantalla
 * @param mensajeError variable de tipo entera que almacena el msj de error si el usuario ingresa otra cosa que no sea entero
 * @param min variable de tipo entera donde se almacena el minimo de enteros que puede el usuario seleccionar en el menú.
 * @param max variable de tipo entera donde se almacena el maximo de enteros que puede el usuario seleccionar en el menú.
 * @return retorna 0 si salio bien
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief esta funcion valida que el usuario solo ingrese un flotante
 *
 * @param flotante variable de tipo float que guarda el flotante ingresado por el usuario
 * @param mensaje  variable de tipo char donde se almacena el msj a imprimir en pantalla
 * @param mensajeError variable de tipo char que almacena el msj de error si el usuario ingresa algo que no sea un flotante
 * @param min varile de tipo float que almacena el minimo de flotantes que el usuario puede ingresar
 * @param max varile de tipo float que almacena el maximo de flotantes que el usuario puede ingresar
 * @return retorna 0 si salio bien
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);

/**
 * @fn int pedirCadena(char*, char*)
 * @brief funcion que valida que el usario ingrese cadena de caracteres es decir puede ingresar numeros y letras
 *
 * @param cadena variable de tipo char donde se almacena char ingresado por el usario
 * @param mensaje variable de tipo char donde se almacena el msj a imprimir en pantalla.
 * @return
 */
int pedirCadena(char* cadena, char* mensaje);

/**
 * @fn int primerLetraMayuscula(char[])
 * @brief funcion que sirve para que el usuario si escribe con mayusculas y minisculas su nombre se ordene poniendo
 * 		  la primer letra en Mayuscula
 *
 * @param name variable de tipo char donde se almacena el nombre ingresado por el usuario
 * @return
 */
int primerLetraMayuscula(char name[]);

/**
 * @fn int validarLetras(char[])
 * @brief funcion que valida que el usuario solo ingrese letras.
 *
 * @param string variable de tipo char donde se almacena los caracteres ingresado por el usuario.
 * @return
 */
int validarLetras(char string[]);
