/*
 * tadtablero.cpp
 *
 *  Created on: 30/11/2015
 *      Author: Francisco Javier Rojo Martín GrupoB
 */

#include <iostream>
#include "tadtablero.h"
#include <cstdlib>


using namespace std;


void iniciar_tablero (tablero &T, int dim){
	int i, j;							//indices
	T.tam=dim;							//esta variable dim sera leida del fichero de configuaracion
	for (i=0; i<T.tam; i++){			//para iniciar el tablero pone todos los valores dentro del espacio util de la matriz a 0
		for (j=0; j<T.tam; j++){
			T.matriz[i][j]=0;
		}
	}
}

int valor_posicion (tablero &T, int i, int j){
	int valor;					//variable
	valor=T.matriz[i][j];		//esto lo hago porque desde el TAD Juego no puedo acceder directamente a parametros del TAD Tablero
	return valor;
}

bool valormaximo (tablero T, int max){
	int i, j;		//indices
	bool fin;				//bandera
	fin=false;
	for (i=0; i<T.tam; i++){			//recorro todo el tablero buscando el valor max, pasando la bandera a 'true' si esta
		for (j=0; j<T.tam; j++){
			if(T.matriz[i][j]==max)
				fin=true;
		}
	}
	return fin;
}

void desplazarderecha (tablero &T){
	int desplazados;		//acumulador
	int i, j;			//indices
	for (i=0; i<T.tam; i++){
		desplazados=0;	//pongo aqui desplazados a 0 para que, cada vez que cambiamos de fila, esta variable se vuelva a 0
		for (j=(T.tam-1); j>=0; j--){
			if(T.matriz[i][j]==0){
				desplazados=desplazados+1;	//cada vez que encontremos un 0 el acumulador aumenta porque asi sabemos que la posicion a desplazar
			}								//cualquier numero distinto de 0 es 1 mayor que antes
			if(T.matriz[i][j]!=0){
				T.matriz[i][j+desplazados]=T.matriz[i][j]; //si no hay ningun 0 a la derecha de un distinto de 0, quedara la fila igual
			}
		}
		for (j=0; j<desplazados; j++){
			T.matriz[i][j]=0;		//ponemos la misma cantidad de 0 que habia antes de desplazar, pero ahora todos a la izquierda
		}
	}
}

void desplazarizquierda (tablero &T){
	int desplazados;									//el funcionamiento de este modulo es igual que el del anterior, pero tiene unas pequeñas
	int i, j;											//diferencias
	for (i=0; i<T.tam; i++){
		desplazados=0;
		for (j=0; j<T.tam; j++){	//la fila se recorre al contrario para que, asi, empezemos por izquierda a desplazar cuando queremos desplazar
			if(T.matriz[i][j]==0){	//a la izquierda, y por la derecha cuando es a la derecha
				desplazados=desplazados+1;
			}
			if(T.matriz[i][j]!=0){
				T.matriz[i][j-desplazados]=T.matriz[i][j];	//se le resta en vez de sumar 'desplazados' porque asi quedaran a la izquierda los =!0
			}
		}
		for (j=0; j<desplazados; j++){
			T.matriz[i][T.tam-(j+1)]=0; //el parametro de la columna es asi para que queden a la derecha los 0
		}
	}
}

void desplazararriba (tablero &T){
	int desplazados;						//el funcionamiento de este modulo es igual que el del anterior, pero tiene unas pequeñas
	int i, j;								//diferencias
	for (j=0; j<T.tam; j++){	//recorro primero las filas dentro de las columnas, al contrario de como solemos hacer, porque es mas comodo a la
		desplazados=0;			//hora de desplazar, tanto hacia arriba como hacia abajo
		for (i=0; i<T.tam; i++){
			if(T.matriz[i][j]==0){
				desplazados=desplazados+1;
			}
			if(T.matriz[i][j]!=0){
				T.matriz[i-desplazados][j]=T.matriz[i][j];	//se le resta en vez de sumar 'desplazados' porque asi quedaran arriba los =!0
			}
		}
		for (i=0; i<desplazados; i++){
			T.matriz[T.tam-(i+1)][j]=0;		//el parametro de la fila es asi para que queden abajo los 0
		}
	}
}

void desplazarabajo (tablero &T){
	int desplazados;						//el funcionamiento de este modulo es igual que el del anterior, pero tiene unas pequeñas
	int i, j;								//diferencias
	for (j=0; j<T.tam; j++){
		desplazados=0;
		for (i=(T.tam-1); i>=0; i--){
			if(T.matriz[i][j]==0){
				desplazados=desplazados+1;
			}
			if(T.matriz[i][j]!=0){
				T.matriz[i+desplazados][j]=T.matriz[i][j];
			}
		}
		for (i=0; i<desplazados; i++){
			T.matriz[i][j]=0;
		}
	}
}

void desplazar (tablero &T, char sentido){
	switch(sentido){					//este modulo simplemente es para elegir, en funcion de un caracter dado, que modulo de desplazamiento ejecutar
		case 'd':
			desplazarderecha(T);
			break;
		case 'i':
			desplazarizquierda(T);
			break;
		case 'b':
			desplazarabajo(T);
			break;
		case 's':
			desplazararriba(T);
			break;

	}
}

int sumarderecha (tablero &T){
	int i, j;
	int suma;
	suma=0;
	for (i=0; i<T.tam; i++){
		for (j=(T.tam-1); j>0; j--){	//no cogemos el j=0 porque sino la ultima comparacion se haria con un numero de fuera del tablero que nosotros no podemos controlar
			if (T.matriz[i][j]==T.matriz[i][j-1]){
				T.matriz[i][j]=2*T.matriz[i][j];
				T.matriz[i][j-1]=0;
				suma=suma+T.matriz[i][j];
				j--; //este desincremento dentro del if es para que, si por ejemplo 2 y 2 se suman formando 4, y en la siguiente casilla hay un 4, no se sumen en el mismo paso estos dos 4 formando un 8
			}
		}
	}
	return suma;
}

int sumarizquierda (tablero &T){
	int i, j;
	int suma;
	suma=0;
	for (i=0; i<T.tam; i++){
		for (j=0; j<(T.tam-1); j++){	//(T.tam-1) porque sino la ultima comparacion se haria con un numero de fuera del tablero que nosotros no podemos controlar
			if (T.matriz[i][j]==T.matriz[i][j+1]){
				T.matriz[i][j]=2*T.matriz[i][j];
				T.matriz[i][j+1]=0;
				suma=suma+T.matriz[i][j];
				j++; //este incremento dentro del if es para que, si por ejemplo 2 y 2 se suman formando 4, y en la siguiente casilla hay un 4, no se sumen en el mismo paso estos dos 4 formando un 8
			}
		}
	}
	return suma;
}

int sumararriba (tablero &T){
	int i, j;
	int suma;
	suma=0;
	for (j=0; j<T.tam; j++){
		for (i=0; i<(T.tam-1); i++){	//(T.tam-1) porque sino la ultima comparacion se haria con un numero de fuera del tablero que nosotros no podemos controlar
			if (T.matriz[i][j]==T.matriz[i+1][j]){
				T.matriz[i][j]=2*T.matriz[i][j];
				T.matriz[i+1][j]=0;
				suma=suma+T.matriz[i][j];
				i++; //este incremento dentro del if es para que, si por ejemplo 2 y 2 se suman formando 4, y en la siguiente casilla hay un 4, no se sumen en el mismo paso estos dos 4 formando un 8
			}
		}
	}
	return suma;
}
int sumarabajo (tablero &T){
	int i, j;
	int suma;
	suma=0;
	for (j=0; j<T.tam; j++){
		for (i=(T.tam-1); i>0; i--){	//no cogemos el i=0; porque sino la ultima comparacion se haria con un numero de fuera del tablero que nosotros no podemos controlar
			if (T.matriz[i][j]==T.matriz[i-1][j]){
				T.matriz[i][j]=2*T.matriz[i][j];
				T.matriz[i-1][j]=0;
				suma=suma+T.matriz[i][j];
				i--; //este desincremento dentro del if es para que, si por ejemplo 2 y 2 se suman formando 4, y en la siguiente casilla hay un 4, no se sumen en el mismo paso estos dos 4 formando un 8
			}
		}
	}
	return suma;
}

int sumarcasillas (tablero &T, char sentido){
	int suma;//acumulador y bandera
	suma=0;
	switch(sentido){  					//este modulo simplemente es para elegir, en funcion de un caracter dado, que modulo de suma ejecutar
		case 'd':
			suma=sumarderecha(T);
			break;
		case 'i':
			suma=sumarizquierda(T);
			break;
		case 's':
			suma=sumararriba(T);
			break;
		case 'b':
			suma=sumarabajo(T);
			break;
	}
	if(suma!=0){
		desplazar(T, sentido);		//si se ha hecho la suma de algun numero, llamamos a desplazar con el sentido apropiado para que vuelva a reordenar
	}								//los numeros en el sitio adecuado segun el caracter dado
	return suma;
}

bool tablero_lleno (tablero &T){
	int i, j;	//indices
	bool lleno;	//bandera
	lleno=true;
	for (i=0; i<T.tam; i++){			//comprobamos si el tablero esta lleno buscando algun 0.
		for (j=0; j<T.tam; j++){		//en cuanto encontremos algun 0, la bandera se pone a 'false' indicando que no lo esta
			if (T.matriz[i][j]==0)
				lleno=false;
		}
	}
	return lleno;
}

void numero_nuevo (tablero &T, int prob){
	int i, j, valor;
	srand(time(NULL));	//cambiamos la semilla para que sea aleatoria a partir de la hora
	i=rand()%T.tam;		//generamos dos valores aleatorios de i, j dentro de los limites del tablero
	j=rand()%T.tam;
	while(T.matriz[i][j]!=0){	//comprobamos que esa posicion esta vacia
		i=rand()%T.tam;		//si no lo esta volvemos a generar i,j aleatorios hasta que no lo este
		j=rand()%T.tam;
	}
	valor=rand()%100;	//le damos a 'valor' un primer valor entre 0 y 99
	if(valor<prob)	//si ese valor es entre 0 y 49 el valor de la casilla sera 2
		valor=2;
	else
		valor=4; //sino sera 4.
	T.matriz[i][j]=valor;
}

void valores_iniciales (tablero &T, int cuantos, int prob){
	int k; //indice
	k=0;
	while(k<cuantos){	//llamamos a numero_nuevo tantas veces como valores iniciales queremos
		numero_nuevo (T, prob);
		k++;
	}
}

bool cambios_producidos (tablero Tant, tablero T){
	int i, j;	//indices
	int dim;	//variable empleada para almacenar el tamaño de la matriz de ambos tableros, al ser igual en ambos
	bool cambios;
	cambios=false;
	dim=T.tam;
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			if(Tant.matriz[i][j]!=T.matriz[i][j])
				cambios=true;
		}
	}
	return cambios;
}

void copiaratablero (tablero T, tablero &Tant){
	int i, j;	//indices
	int dim;	//variable empleada para almacenar el tamaño de la matriz de ambos tableros, al ser igual en ambos
	dim=T.tam;
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			Tant.matriz[i][j]=T.matriz[i][j];
		}
	}
}

bool posible_sumar (tablero T){
	int i, j;	//indices
	int dim;	//variable empleada para almacenar el tamaño de la matriz menos 1
	bool posible;
	posible=false;
	for(i=0; i<(T.tam-1); i++){
		for(j=0; j<(T.tam-1); j++){
			if(T.matriz[i][j]==T.matriz[i][j+1])
				posible=true;
			if(T.matriz[i][j]==T.matriz[i+1][j])
				posible=true;
		}
	}

	//comprobamos las esquinas, que en el caso anterior no se pueden comprobar
	dim=T.tam-1;
	if(posible==false){
		if(T.matriz[dim][dim]==T.matriz[dim][dim-1])
			posible=true;
		if(T.matriz[dim][dim]==T.matriz[dim-1][dim])
			posible=true;
		if(T.matriz[0][0]==T.matriz[0][1])
			posible=true;
		if(T.matriz[0][0]==T.matriz[1][0])
			posible=true;
		if(T.matriz[0][dim]==T.matriz[1][dim])
			posible=true;
		if(T.matriz[0][dim]==T.matriz[0][dim-1])
			posible=true;
		if(T.matriz[dim][0]==T.matriz[dim][1])
			posible=true;
		if(T.matriz[dim][0]==T.matriz[dim-1][0])
			posible=true;
	}
	return posible;
}
