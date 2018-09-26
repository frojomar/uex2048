/**

	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2015/2016

	Nombre: entorno.h
	Descripción: Especificación del TAD Entorno para el proyecto 2048.
	     	 	 Encargado del manejo de la interfaz del juego.
	Autor:	Profesores de las asignaturas
	Fecha:  25/10/2015

*/


#ifndef ENTORNO_H_
#define ENTORNO_H_

#include <string>
using namespace std;
// -------------------------------------------------------------
// Definicion de constantes públicas
// -------------------------------------------------------------


// Dimensiones máximas  del tablero

const int MAXTAMANO	= 8;


// -------------------------------------------------------------
// Definicion de tipos
// -------------------------------------------------------------

/**
 *   Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
 *   de los cursores o teclas válidas que se ha pulsado
 */
enum TipoTecla {TEliminar,TNada,TEnter, TIzquierda, TDerecha, TArriba, TAbajo, TSalir,  TX};


/**
 *   Zonas en el entorno para imprimir mensajes. Existen 3 zonas delimitadas para imprimir un
 *   mensaje en la pantalla del entorno. Se pueden usar para imprimir mensajes de estado de
 *   diferentes tipos
 */
enum TipoZona {Zona1, Zona2, Zona3};


// -------------------------------------------------------------
// Declaración de interfaz (módulos) PÚBLICA
// -------------------------------------------------------------


/**

	PRE:  3 <= tam <= MAXTAMANO,
	POST: Inicia la pantalla de juego, incluyendo una rejilla cuadrada de tam*tam
*/
void entornoIniciar (int tam);


/**
	PRE: Archivo uex2048.cnf correcto y en la carpeta raíz del proyecto
	     (NO SE COMPRUEBAN ERRORES EN LOS DATOS)
	POST: Devuelve:
	         TRUE:  si se carga correctamente la configuración del juego,
		     FALSE: en caso contrario.
    PARÁMETROS:
		Si la configuración se lee de forma correcta se devolverá:
		   tamano:		número de filas y columnas del tablero
		   maxValor:    valor máximo (potencia de 2) que se debe obtener para ganar el juego
		   numIniciar: 	número de valores aleatorios que se generan inicialmente en el tablero
		   prob2:		probabilidad de que aparezca el número 2 al generar números aleatoriamente
		Por defecto, el archivo Uex2048.cnf se encuentra en el directorio  del proyecto
 */
bool entornoCargarConfiguracion ( int 	&tamano,
								  int   &maxValor,
								  int 	&numIniciar,
								  int 	&prob2);




/**
	PRE:  { 0 <= fila < MAXTAMANO }
	PRE:  { 0 <= columna < MAXTAMANO}
    PRE:  { 1 <=  valor <= maxValor}
	POST: Coloca en una casilla el "valor"
*/
void entornoPonerNumero(int fila, int columna, int valor);


/**
 * 	PRE:  0 <= fila < MAXTAMANO,
	PRE:  0 <= columna < MAXTAMANO,
	POST: Elimina del entorno el valor que existe en la casilla cuyas coordenadas son fila, columna.
*/
void entornoEliminarCasilla(int fila, int columna);

/**
   PRE: 	{zona in {Zona1,Zona2,Zona3}}
   POST:	Escribe el mensaje pasado por parámetro en el entorno, concretamente, en la zona especificada.
*/
void entornoMostrarMensaje (TipoZona zona, string msg);


/**
    POST: Muestra un mensaje en el centro de la rejilla para indicar que ha finalizado el juego
*/
void entornoMostrarMensajeFin (string cad);

/**
    POST: Muestra un recuadro que permite inidicar los marcadores del juego: valor máximo y puntuación
*/
void entornoPonerMarcadores( ) ;

/**
    POST: Muestra valor en la zona correspondiente al marcador valor máximo
*/
void entornoPonerMaximo( int valor);

/**
    POST: Muestra valor en la zona correspondiente al marcador puntuación
*/
void entornoPonerPuntuacion( int valor);

/**
    POST:Devuelve un valor enumerado de TipoTecla con la tecla que se ha pulsado
*/
TipoTecla entornoLeerTecla();


/*
 * PRE: pausa es el tiempo en milisegundos que dura la pausa
 * POST: lleva a cabo una pausa en la ejecución del juego,
 * por ejemplo, para ralentizar el movimiento de los valores en el tablero
 * * */

void entornoPausa (int pausa);




#endif

