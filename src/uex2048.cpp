/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2015/2016

 Nombre: uex2048.cpp
 Descripción:  Proyecto uex2048
 Autor:	Francisco Javier Rojo Martín GrupoB
 Fecha:  25/10/2015

 */

#include <iostream>
#include "entorno.h"
#include "pruebas.h"
#include "juego.h"

using namespace std;




int main(){
	structjuego J;

	//pruebas();

	iniciar_juego (J);
	jugar (J);


	return 0;
}
