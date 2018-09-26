/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2015/2016

 Nombre: entorno.cpp
 Descripción: Implementación del TAD Entorno para el proyecto uex2048
 Encargado del manejo de la interfaz del juego.
 Autor:	Profesores de las asignaturas
 Fecha:	25/11/2012
 Fecha última modificaciín: 10/11/2015

 */

#include "entorno.h"
#include <allegro.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// -------------------------------------------------------------
// Definicion de constantes privadas
// -------------------------------------------------------------
// Definición de colores que usa el entorno
const int COLOR_BLANCO = 0;
const int COLOR_ROJO = 1;
const int COLOR_NEGRO = 2;
const int COLOR_AMARILLO = 3;
const int COLOR_VERDE = 4;
const int COLOR_AZUL = 5;
const int COLOR_NARANJA = 6;
const int COLOR_GRIS = 7;

const int COLOR_FONDO = COLOR_VERDE;

//const int COLOR_LINEAS = COLOR_BLANCO;
const int COLOR_LINEAS = COLOR_NARANJA;

// Tamaño de la ventana del juego
const int ANCHO_VENTANA = 800;
const int ALTO_VENTANA = 600;

// Definicón de constantes para posicionar los números en el tablero
const int DISTANCIA_COLS = 60;  // Distancia entre columnas
const int DISTANCIA_FILAS = 60;  // Distancia entre filas
const int ORIGEN_X = 20;  // Origen de las x antes 20
const int ORIGEN_Y = 20 + 40;  // Origen de las y antes 20+40

// definicion de las constantes para posicionar los marcadores
const int COLINI = 525;
const int COLFIN = 675;

const int FILA_1 = 240;
const int FILA_2 = 300;
const int ANCHO = 40;

//para las fuentes de letras
DATAFILE *MisDatos;
FONT *MiFuente;

// -------------------------------------------------------------
// Declaración de módulos PRIVADOS
// -------------------------------------------------------------

// convierte el número dado como parámetro de entrada a string (cadena)
string toString(int numero);

// define el color en función de los valores makecol - allegro library
int makecolor2(int color);

// Dibuja en la pantalla el borde de un tablero con el ancho indicado
void entornoPintarRejilla(int tamanio);


// -------------------------------------------------------------
// Definición de módulos PRIVADOS
// -------------------------------------------------------------
string toString(int numero) {
	stringstream flujo;
	string cadena;

	flujo << numero;
	flujo >> cadena;

	return cadena;
}

int makecolor2(int color) {

	int col;

	switch (color) {
	case COLOR_BLANCO:
		col = makecol(255, 255, 255);
		break;
	case COLOR_ROJO:
		col = makecol(255, 0, 0);
		break;
	case COLOR_NEGRO:
		col = makecol(0, 0, 0);
		break;
	case COLOR_AMARILLO:
		col = makecol(200, 200, 50);
		break;
	case COLOR_VERDE:
		col = makecol(0, 100, 0);
		break;
	case COLOR_AZUL:
		col = makecol(50, 50, 255);
		break;
	case COLOR_NARANJA:
		col = makecol(216, 075, 032);
		break;
	case COLOR_GRIS:
		col = makecol(135, 135, 135);
		break;
	default:
		col = makecol(255, 255, 255);
		break; //color blanco
	}

	return col;
}

void entornoPintarRejilla(int tamano) {

	acquire_screen();

	int i;
	int columnas = tamano;
	int filas = tamano;
	int nVecesMarco = 5; // número de veces que se repite el marco

	for (i = 1; i < nVecesMarco; i++) {
		rect(screen, ORIGEN_X + i, ORIGEN_Y + i,
				ORIGEN_X + columnas * DISTANCIA_COLS + i,
				ORIGEN_Y + filas * DISTANCIA_FILAS + i,
				makecolor2(COLOR_NARANJA));
	}
	// horizontales
	for (i = 0; i <= (columnas); i++) {
		line(screen, ORIGEN_X + 0 * DISTANCIA_COLS,
				ORIGEN_Y + i * DISTANCIA_FILAS,
				ORIGEN_X + columnas * DISTANCIA_COLS,
				ORIGEN_Y + i * DISTANCIA_FILAS, makecolor2(COLOR_LINEAS));
	}

	//verticales
	for (i = 0; i <= (filas); i++) {
		line(screen, ORIGEN_X + i * DISTANCIA_COLS,
				ORIGEN_Y + 0 * DISTANCIA_FILAS, ORIGEN_X + i * DISTANCIA_COLS,
				ORIGEN_Y + filas * DISTANCIA_FILAS, makecolor2(COLOR_LINEAS));
	}

	textout_ex(screen, font, "*** 2 0 4 8 ***", 525, 30, makecol(216, 075, 032),
			makecol(0, 0, 0));
	textout_ex(screen, font, "PROYECTO DE PROGRAMACIÓN", 525, 50,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "TECLAS:", 525, 80, makecol(255, 255, 255),
			makecol(0, 0, 0));
	textout_ex(screen, font, "Arriba: Fecha arriba", 525, 100,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Abajo:  Flecha abajo", 525, 120,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Drcha:  Flecha derecha", 525, 140,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Izqda:  Flecha izquierda", 525, 160,
			makecol(255, 255, 255), makecol(0, 0, 0));
	textout_ex(screen, font, "Salir:  Escape", 525, 180, makecol(255, 255, 255),
			makecol(0, 0, 0));

	release_screen();

}

/*void invertirFC(int &fila, int &columna) {
	int aux = columna;
	columna = fila;
	fila = aux;
}
*/
// -------------------------------------------------------------
// Definición de la interfaz PÚBLICA
// -------------------------------------------------------------

void entornoIniciar(int tam) {
	int i, j;
	// Iniciar el entorno
	allegro_init();
	install_keyboard();
	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	MisDatos = load_datafile("fuentes.dat");
	entornoPintarRejilla(tam);
	for (i = 0; i < tam; i++)
		for (j = 0; j < tam; j++)
			entornoEliminarCasilla(i, j);

}

bool entornoCargarConfiguracion(int &tamano, int &maxValor, int &numInicio,
		int &prob2) {

	bool leido;
	ifstream entrada;
	string cadena;  // para recuperar la informacion de las líneas del fichero
	entrada.open("uex2048.cnf");
	if (entrada.is_open()) {
		getline(entrada, cadena);
		tamano = atoi(cadena.c_str());

		getline(entrada, cadena);
		maxValor = atoi(cadena.c_str());

		getline(entrada, cadena);
		numInicio = atoi(cadena.c_str());

		getline(entrada, cadena);
		prob2 = atoi(cadena.c_str());

		leido = true;
		entrada.close();
	} else {
		cout
				<< "Fichero de configuración no encontrado (<proyecto>/Uex2048.cnf)."
				<< endl;
		cout << "Formato:" << endl;
		cout << "\t[Tamaño del tablero 1..4]" << endl;
		cout << "\t[valor maximo a conseguir]" << endl;
		cout << "\t[número de casillas con valores iniciales]" << endl;
		cout << "\t[probabilidad de que se genere un 2 aleatoriamente]" << endl;
		leido = false;
	}

	return leido;
}

void entornoPonerNumero(int fila, int columna, int valor) {

	int pos1, pos2, tam;

	int R = 100 * valor;
	int G = 50 * valor;
	int B = 30 * valor;

	pos1 = ORIGEN_X + columna * DISTANCIA_COLS + 30;
	pos2 = ORIGEN_Y + fila * DISTANCIA_FILAS + 15;

	if (valor < 10) {
		tam = 5;
	} else if (valor < 100) {
		tam = 4;
		pos2 = pos2 + 2;
	} else if (valor < 1000) {
		tam = 3;
		pos2 = pos2 + 3;
	} else {
		tam = 2;
		pos2 = pos2 + 5;
	}

	MiFuente = (FONT *) MisDatos[tam].dat;

	rectfill(screen, ORIGEN_X + columna * DISTANCIA_COLS + 6,
			ORIGEN_Y + fila * DISTANCIA_FILAS + 6,
			ORIGEN_X + columna * DISTANCIA_COLS + DISTANCIA_COLS - 6,
			ORIGEN_Y + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 6,
			makecol(R, G, B));
	textout_centre_ex(screen, MiFuente, toString(valor).c_str(), pos1, pos2,
			makecolor2(COLOR_NEGRO), makecol(R, G, B));

}

void entornoEliminarCasilla(int fila, int columna) {

	rectfill(screen, ORIGEN_X + columna * DISTANCIA_COLS + 5,
			ORIGEN_Y + fila * DISTANCIA_FILAS + 5,
			ORIGEN_X + columna * DISTANCIA_COLS + DISTANCIA_COLS - 2,
			ORIGEN_Y + fila * DISTANCIA_FILAS + DISTANCIA_FILAS - 2,
			makecolor2(COLOR_GRIS));
}

void entornoMostrarMensaje(TipoZona zona, string msg) {

	int fila;

	switch (zona) {

	case Zona1:
		fila = 520;
		break;
	case Zona2:
		fila = 540;
		break;
	case Zona3:
		fila = 560;
		break;

	default:
		return;

	}

	textout_ex(screen, font, "                                        ", 525,
			fila, makecol(255, 0, 0), makecol(0, 0, 0));
	textout_ex(screen, font, msg.c_str(), 525, fila, makecol(255, 255, 0),
			makecol(0, 0, 0));

}

void entornoMostrarMensajeFin(string cad) {

	int i, j;

	// Borrar un rectangulo
	rectfill(screen, 200, 200, 620, 440, makecol(0, 0, 0));

	// Efecto
	for (i = 0, j = 0; i < 40 && j < 40; i += 4, j += 4) {
		rect(screen, i + 220, j + 240, 600 - i, 400 - j, makecol(255, 0, 0));
		rect(screen, i + 222, j + 242, 598 - i, 398 - j,
				makecol(255, 255, 255));
		usleep(25000); // 25 milisegundos
	}

	// Mensaje
	textout_ex(screen, font, cad.c_str(), 280, 320, makecol(255, 255, 0),
			makecol(0, 0, 0));

}

void entornoPonerMarcadores() {
	string puntos;

	rect(screen, COLINI - 1, FILA_1 - 1, COLFIN + 1, FILA_1 + ANCHO + 1,
			makecolor2(COLOR_NARANJA));
	rect(screen, COLINI - 2, FILA_1 - 2, COLFIN + 2, FILA_1 + ANCHO + 2,
			makecolor2(COLOR_NARANJA));
	rectfill(screen, COLINI, FILA_1, COLFIN, FILA_1 + ANCHO,
			makecolor2(COLOR_GRIS));
	puntos = "VALOR MAXIMO:";
	textout_ex(screen, font, puntos.c_str(), COLINI + 10, FILA_1 + 15,
			makecolor2(COLOR_NEGRO), makecolor2(COLOR_GRIS));

	rect(screen, COLINI - 1, FILA_2 - 1, COLFIN + 1, FILA_2 + ANCHO + 1,
			makecolor2(COLOR_NARANJA));
	rect(screen, COLINI - 2, FILA_2 - 2, COLFIN + 2, FILA_2 + ANCHO + 2,
			makecolor2(COLOR_NARANJA));
	rectfill(screen, COLINI, FILA_2, COLFIN, FILA_2 + ANCHO,
			makecolor2(COLOR_GRIS));
	puntos = "PUNTUACIÓN:";
	textout_ex(screen, font, puntos.c_str(), COLINI + 10, FILA_2 + 15,
			makecolor2(COLOR_NEGRO), makecolor2(COLOR_GRIS));

}

void entornoPonerMaximo(int valor) {

	textout_ex(screen, font, toString(valor).c_str(), COLINI + 115, FILA_1 + 15,
			makecolor2(COLOR_NEGRO), makecolor2(COLOR_GRIS));
}

void entornoPonerPuntuacion(int valor) {

	textout_ex(screen, font, toString(valor).c_str(), COLINI + 110, FILA_2 + 15,
			makecolor2(COLOR_NEGRO), makecolor2(COLOR_GRIS));
}

TipoTecla entornoLeerTecla() {

	TipoTecla tecla = TNada;
	utoupper(readkey());

	if (key[KEY_UP])
		tecla = TArriba;
	else if (key[KEY_DOWN])
		tecla = TAbajo;
	else if (key[KEY_RIGHT])
		tecla = TDerecha;
	else if (key[KEY_LEFT])
		tecla = TIzquierda;
	else if (key[KEY_ESC])
		tecla = TSalir;
	else if (key[KEY_ENTER])
		tecla = TEnter;
	else if (key[KEY_DEL])
		tecla = TEliminar;
	else if (key[KEY_X])
		tecla = TX;

	clear_keybuf();

	return tecla;

}

void entornoPausa(int pausa) {
	usleep(pausa);
}
