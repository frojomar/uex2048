/*
 * tadtablero.h
 *
 *  Created on: 30/11/2015
 *      Author: Francisco Javier Rojo Martín GrupoB
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_

const int MAX=8;

typedef int tipomatriz[MAX][MAX];	//Defino una matriz de 8x8 porque es el tamaño maximo que puede tener el tablero del juego
struct tablero{
	tipomatriz matriz;
  	int tam;						//esta variable me servira para delimitar el tamaño de la matriz por el que nos movemos
};

//Modulo que inicia el TAD Tablero
//PRE:	dim es int, 3<=dim<=8
//POST:	inicia el tablero
//Complejidad O(n²)
void iniciar_tablero (tablero &T, int dim);

//Modulo que devuelve el valor de una posicion del tablero
//PRE:	T iniciado, 0<=i<dim, 0<=j<dim
//POST:	devuelve el valor de una posicion del tablero
//Complejidad O(n²)
int valor_posicion (tablero &T, int i, int j);

//Modulo que comprueba si el valor maximo se ha alcanzado
//PRE:	T iniciado, max es un multiplo de 2 >=4
//POST:	devuelve un bool que indica si el valor maximo ha sido alcanzado
//Complejidad O(n²)
bool valormaximo (tablero T, int max);

//Modulo que suma los valores iguales en horizontal y hacia la izquierda
//PRE:	T iniciado
//POST:	suma los valores iguales en horizontal y hacia la izquierda
//Complejidad O(n²)
int sumarizquierda (tablero &T);

//Modulo que suma los valores iguales en horizontal y hacia la derecha
//PRE:	T iniciado
//POST:	suma los valores iguales en horizontal y hacia la derecha
//Complejidad O(n²)
int sumarderecha (tablero &T);

//Modulo que suma los valores iguales en vertical y hacia arriba
//PRE:	T iniciado
//POST:	suma los valores iguales en vertical y hacia arriba
//Complejidad O(n²)
int sumararriba (tablero &T);

//Modulo que suma los valores iguales en vertical y hacia abajo
//PRE:	T iniciado
//POST:	suma los valores iguales en vertical y hacia abajo
//Complejidad O(n²)
int sumarabajo (tablero &T);

//Modulo que determina en que sentido se suma y se devuelve el valor de esa suma
//PRE:	T iniciado, (sentido==('i'||'d'||'s'||'b'))
//POST:	determina en que sentido se suma y devuelve el valor de esa suma
//Complejidad O(1)
int sumarcasillas (tablero &T, char sentido);

//Modulo que desplaza los valores hacia la izquierda, quedando el mismo numero de 0 que antes de desplazar, pero a la derecha todos ellos
//PRE:	T iniciado
//POST:	desplaza los valores hacia la izquierda, quedando el mismo numero de 0 que antes de desplazar, pero a la derecha todos ellos
//Complejidad O(n²)
void desplazarizquierda (tablero &T);

//Modulo que desplaza los valores hacia la derecha, quedando el mismo numero de 0 que antes de desplazar, pero a la izquierda todos ellos
//PRE:	T iniciado
//POST:	desplaza los valores hacia la derecha, quedando el mismo numero de 0 que antes de desplazar, pero a la izquierda todos ellos
//Complejidad O(n²)
void desplazarderecha (tablero &T);

//Modulo que desplaza los valores hacia la arriba, quedando el mismo numero de 0 que antes de desplazar, pero a la abajo todos ellos
//PRE:	T iniciado
//POST:	desplaza los valores hacia la arriba, quedando el mismo numero de 0 que antes de desplazar, pero a la abajo todos ellos
//Complejidad O(n²)
void desplazararriba (tablero &T);

//Modulo que desplaza los valores hacia abajo, quedando el mismo numero de 0 que antes de desplazar, pero arriba todos ellos
//PRE:	T iniciado
//POST:	desplaza los valores hacia la abajo, quedando el mismo numero de 0 que antes de desplazar, pero a la arriba todos ellos
//Complejidad O(n²)
void desplazarabajo (tablero &T);

//Modulo que determina en que sentido se desplaza
//PRE:	T iniciado, (sentido==('i'||'d'||'s'||'b'))
//POST:	determina en que sentido se desplaza
//Complejidad O(1)
void desplazar (tablero &T, char sentido);

//Modulo que comprueba si el tablero esta lleno o no
//PRE:	T iniciado
//POST:	devuelve un bool que indica si el tablero esta lleno o no
//Complejidad O(n²)
bool tablero_lleno (tablero &T);

//Modulo que genera un valor nuevo
//PRE:	T iniciado, 0<=prob<=100
//POST:	genera un nuevo valor en el tablero en una posicion no ocupada
//Complejidad O(n)
void numero_nuevo (tablero &T, int prob);

//Modulo que genera los valores iniciales
//PRE:  T iniciado, cuantos>=0, 0<=prob<=100
//POST: genera tantos valores iniciales como indique cuantos, siendo estos valores 2 o 4
//Complejidad O(n²)
void valores_iniciales (tablero &T, int cuantos, int prob);

//Modulo que comprueba si dos tableros son iguales
//PRE: 	T iniciado, Tant iniciado, Tant.tam==T.tam
//POST:	comprueba si dos tableros son iguales
bool cambios_producidos (tablero Tant, tablero T);

//Modulo que copia la informacion de un tablero a otro
//PRE: 	T iniciado, Tant iniciado, Tant.tam==T.tam
//POST:	copia la informacion de un tablero a otro
void copiaratablero (tablero T, tablero &Tant);

//Modulo que comprueba si es posible sumar dos o mas casillas en el tablero
//PRE:	T iniciado
//POST:	comprueba si es posible sumar dos o mas casillas en el tablero
bool posible_sumar (tablero T);

#endif /* TADTABLERO_H_ */
