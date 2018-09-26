/*
 * pruebas.h
 *
 *  Created on: 28/11/2015
 *      Author: Francisco Javier Rojo Martín GrupoB
 */

#ifndef PRUEBAS_H_
#define PRUEBAS_H_
#include "entorno.h"
#include "tadtablero.h"
#include "juego.h"

//PRUEBAS DE LA LIBRERIA ENTORNO
//
void pr_entornoIniciar ();

void pr_entornoCargarConfiguracion ();

void pr_entornoPonerNumero();

void pr_entornoEliminarCasilla();

void pr_entornoMostrarMensaje ();

void pr_entornoLeerTecla();

void pr_entornoPausa ();

void pr_entornoPonerMarcadores();

void pr_entornoPonerMaximo();

void pr_entornoPonerPuntuacion();

void pr_entornoMostrarMensajeFin ();

void pruebas_entorno ();
//
//FIN DE PRUEBAS DE LA LIBRERIA ENTORNO

//PRUEBAS DEL TAD TABLERO
//
void pr_iniciar_tablero();

void pr_valor_posicion();

void pr_desplazar ();

void pr_sumarcasillas ();

void pr_valormaximo ();

void pr_tablero_lleno ();

void pr_valores_iniciales ();

void pr_numero_nuevo ();

void pr_cambios_producidos();

void pr_copiaratablero();

void pr_posible_sumar();

void pr_pruebas_tadtablero();

//
//FIN DE PRUEBAS DEL TAD TABLERO

//INICIO DE PRUEBAS DE JUEGO
//

//Solo hago pruebas de un modulo porque el resto de modulos tan solo recogen instrucciones de otras librerias que ya han sido probadas previamente.
void pr_sentido_movimiento();

void pruebas_juego();
//
//FIN DE PRUEBAS DE JUEGO

//MODULO DE PRUEBAS PRINCIPAL
void pruebas();
//

#endif /* PRUEBAS_H_ */
