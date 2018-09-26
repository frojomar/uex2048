/*
 * juego.h
 *
 *  Created on: 08/12/2015
 *      Author: Francisco Javier Rojo Martín GrupoB
 */

#ifndef JUEGO_H_
#define JUEGO_H_
#include "tadtablero.h"
#include "entorno.h"

struct structjuego{		//definimos la estructura de datos del TAD Juego
	tablero T;			//contiene un TAD Tablero
	tablero Tant;		//contiene la informacion del tablero del paso anterior
	int max;			//un entero que almacenara el maximo, leido del archivo de configuracion
	int punt;			//un entero que almacena la puntuacion que llevamos
	int prob;			//un entero que almacena la probabilidad de generar un 2
};

//Modulo que pinta el tablero en el entorno que se nos entrego por los profesores
//PRE:	J iniciado
//POST:	pinta el tablero en el entorno que se nos entrego por los profesores
//		No hago pruebas de este modulo ya que seria basicamente como hacer pruebas de 'entornoeliminarCasilla'
//		y 'entornoPonerNumero', pruebas que ya he hecho
//Complejidad O(n²)
void pintar_entorno(structjuego &J);

//Modulo que da un poco de 'decoracion' al programa, escribiendonos cual tecla hemos pulsado en la Zona1.
//PRE:	la variable 'tecla' es del tipo 'TipoTecla'
//POST: escribe cual tecla hemos pulsado en la Zona1.
//		No hago pruebas de este modulo ya que sería basicamente como hacer pruebas del 'entornoMostrarMensaje', pruebas
//		que ya he hecho.
//Complejidad O(1)
void escribir_zona1(TipoTecla tecla);

//Modulo que inicia el juego, iniciando el TADJuego, el TADTablero y el entorno
//PRE:
//POST: inicia el juego, iniciando el TADJuego, el TADTablero y el entorno
//		No hago pruebas de este modulo porque sería como hacer pruebas de modulos ya probados
//Complejidad O(n²)
void iniciar_juego(structjuego &J);

//Modulo que determina que sentido es el que vamos a usar para desplazar y sumar dependiendo de la tecla pulsada
//PRE:	c==(TIzquierda||TDerecha||TArriba||TAbajo)
//POST:	determina que sentido es el que vamos a usar para desplazar y sumar dependiendo de la tecla pulsada
//Complejidad O(n²)
char sentido_movimiento(TipoTecla c);

//Modulo que recoge el conjunto de instrucciones a realizar en cada paso del juego
//PRE:	J iniciado
//POST:	recoge el conjunto de instrucciones a realizar en cada paso del juego, haciendolas funcionar en el orden adecuado
//		No hago pruebas de este modulo porque sería como hacer pruebas de modulos ya probados
//Complejidad O(1)
void siguiente_paso(structjuego &J);

//Modulo que determina si debemos seguir jugando o si ya hemos terminado, bien porque el tablero este lleno, bien porque hayamos alcanzado el maximo
//PRE:	J iniciado
//POST:	determina si debemos seguir jugando o si ya hemos terminado, bien porque el tablero este lleno, bien porque hayamos alcanzado el maximo
//		No hago pruebas de este modulo porque sería como hacer pruebas de modulos ya probados
//Complejidad O(n)
void jugar(structjuego &J);

#endif /* JUEGO_H_ */
