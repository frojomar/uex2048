/*
 * juego.cpp
 *
 *  Created on: 08/12/2015
 *      Author: Francisco Javier Rojo Martín GrupoB
 */

#include <iostream>
#include "juego.h"

using namespace std;

void pintar_entorno(structjuego &J){
	int i, j;
	for(i=0;i<J.T.tam; i++){
		for(j=0;j<J.T.tam; j++){
			if(valor_posicion(J.T, i, j)==0)
				entornoEliminarCasilla(i, j);
			else
				entornoPonerNumero(i, j, valor_posicion(J.T, i, j));
		}
	}
}


void escribir_zona1(TipoTecla tecla){		//este modulo es meramente decorativo
	switch (tecla){							//dependiendo de la tecla de direccion que pulsemos nos escribe uno u otro mensaje, indicando cual hemos pulsado
		case TIzquierda:
			entornoMostrarMensaje(Zona1, "Tecla Pulsada: TIzquierda");
			break;
		case TDerecha:
			entornoMostrarMensaje(Zona1, "Tecla Pulsada: TDerecha");
			break;
		case TAbajo:
			entornoMostrarMensaje(Zona1, "Tecla Pulsada: TAbajo");
			break;
		case TArriba:
			entornoMostrarMensaje(Zona1, "Tecla Pulsada: TArriba");
			break;
		default:
			break;
	}
}
char sentido_movimiento(TipoTecla c){
	char sentido;	//"convierte" el tipotecla en un caracter que podemos emplear con las operaciones del TAD Tablero, donde el tipotecla no esta definido
	switch (c){
		case TIzquierda:
			sentido='i';
			break;
		case TDerecha:
			sentido='d';
			break;
		case TAbajo:
			sentido='b';
			break;
		case TArriba:
			sentido='s';
			break;
		default:
			break;
	}
	return sentido;
}
void siguiente_paso(structjuego &J, bool &terminar){
	TipoTecla c;
	char sentido;				//recoge las intrucciones que se deben ejecutar en cada paso (excepto en el primero, cuyo caso es especial)
	c=entornoLeerTecla();		//leemos la tecla pulsada
	if(c==TSalir){			//si la tecla es ESC, salimos del juego sin terminar de jugar
		terminar=true;
	}
	else{	//si no es ESC, realiza las instrucciones adecuadas
		escribir_zona1 (c); //escribe en la zona 1 la tecla pulsada
		sentido= sentido_movimiento(c);	//"convierte" el tipotecla en un caracter
		desplazar(J.T, sentido); //desplaza en el sentido adecuado segun la tecla
		J.punt=J.punt+sumarcasillas(J.T, sentido);//aumenta la puntuacion segun el valor de la suma de las casillas en este paso
		pintar_entorno(J);
		if (cambios_producidos(J.Tant, J.T)==true){
			numero_nuevo(J.T, J.prob); //genera un nuevo valor
			entornoPausa(200000);	//hace una pequeña pausa antes de escribir en el entorno el numero nuevo
			pintar_entorno(J);
			copiaratablero(J.T,J.Tant);
		}

		entornoPonerPuntuacion(J.punt); //pone la puntuacion en su zona reservada en el entorno

	}
}
//MODULOS PRINCIPALES DEL JUEGO
//
void iniciar_juego(structjuego &J){
	int dim, inic;
	J.punt=0; //pone la puntuacion a 0
	entornoCargarConfiguracion(dim, J.max, inic, J.prob); //almacena la informacion del fichero de configuracion en sus respectivas variables
	entornoIniciar(dim); //inicia el entorno de la dimension dada por el fichero de configuarion
	iniciar_tablero(J.T, dim); //inicia el tablero
	iniciar_tablero(J.Tant, dim); //inicia el tablero auxiliar para comprobar cambios
	valores_iniciales(J.T, inic, J.prob); //genera los valores iniciales
	pintar_entorno(J); //pinta el entorno con los valores iniciales
	entornoPonerMarcadores(); //pone los marcadores en el entorno
	entornoPonerMaximo(J.max); //escribe el maximo a alcanzar en el entorno
	entornoPonerPuntuacion(J.punt); //escribe la puntuacion 0 en el entorno
	entornoPausa(100000);
	entornoMostrarMensaje(Zona3,"Pulsa ESC para salir");
}

void jugar (structjuego &J){ //este modulo es el mas importante del TAD Juego, ya que es el que llama a todos, ya sea directamente o mediante otros, menos a iniciar_juego
	bool fin;//bandera
	fin=false;	//indica que no se ha terminado el juego
	while(fin!=true){ //mientras la bandera 'fin' no sea 'true', seguiremos jugando
		if(valormaximo(J.T,J.max)==true){ //si se haalcanzado el valor maximo se terminara el juego
			entornoMostrarMensajeFin("Enhorabuena!! Ha ganado.Pulsa una tecla");
			if(entornoLeerTecla())
				fin=true;
		}
		else{ //si el valor maximo no ha sido alcanzado, distingue entre dos casos
			if (tablero_lleno(J.T)==true){ //si se ha llenado el tablero, NO se terminara el juego
				if(posible_sumar(J.T)!=true){
					entornoMostrarMensajeFin("Fin del juego. Pulsa una tecla");
					if(entornoLeerTecla())
						fin=true;
				}
				else{
					entornoMostrarMensaje(Zona2, "Se puede seguir sumando");
					siguiente_paso(J, fin);
					entornoMostrarMensaje(Zona2, "");
				}

			}
			else{ // si no se dan ninguna condicion anterior pasamos al paso siguiente
				siguiente_paso(J, fin);
			}
		}
	}
}


