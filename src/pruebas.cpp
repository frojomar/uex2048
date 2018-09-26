/*
 * pruebas.cpp
 *
 *  Created on: 28/11/2015
 *      Author: Francisco Javier Rojo Martín GrupoB
 */
#include <iostream>
#include "pruebas.h"

using namespace std;
//PRUEBAS DE LA LIBRERIA ENTORNO
//	Se trata de una serie de pruebas, todas ellas visuales (excepto la de 'entornoCargarConfiguracion', que tambien tiene su parte automatica).
//
//	En estas pruebas se deben usar al mismo tiempo la consola "tipica" del IDE como el entorno desarrollado por los profesores para el proyecto de programacion.
//	Se deben ir introducciendo una serie de valores numericos de tal forma que la consola escriba, a partir del valor si funciona correctamente el modulo probado o no.
//
//	Lo unico que pretendo conseguir con esto es que, una vez terminadas las pruebas, pueda ver en la consola si
//	todos los modulos funcionan o no, ya que la consola utiliza el valor introducido para escribir al final de
//	cada modulo de pruebas si la prueba a sido superada correctamente o no.
//

//Complejidad O(1)
//modulo que prueba entornoIniciar creando un entorno con un tablero de la dimension 8x8
void pr_entornoIniciar (){
	int ini;//bandera
	cout<<"Inicio de pruebas de 'entornoIniciar'"<<endl;
	entornoIniciar(8);	//SERA LA UNICA VEZ QUE INICIE EL ENTORNO, ya que las demas pruebas van relacionadas una con otra.
	cout<<"		Introduzca el valor 1 si el entorno se ha iniciado correctamente con un tablero dim.8x8:"<<endl;
	cout<<"		Si no es asi introduzca el valor 0."<<endl;
	cin>>ini; //esta instruccion la realizare al final de cada modulo de pruebas para escribir un mensaje a modo "resumen" de si las pruebas de ese modulo funcionan o no.
	if(ini==1)
		cout<<"Prueba 'entornoInicar' CORRECTA"<<endl;
	if(ini==0)
		cout<<"Prueba 'entornoInicar' FALLIDA"<<endl;
	if((ini!=0)&&(ini!=1))
		cout<<"		El valor "<<ini<<" no es valido, introduzca 0 o 1, por favor:"<<endl;
	cout<<endl;
}

//Complejidad O(1)
//modulo que comprueba que el entorno es capaz de leer, y que lo hace correctamente, el fichero unex2048.cnf para cargar la configuracion que, ya en el juego, se usara para iniciar el entorno aun que aqqui no sea asi.
void pr_entornoCargarConfiguracion (){
	bool cargar;
	int dim, valor, inicio, prob;//variables que almacenaran los valores de salida del modulo 'entornoCargarConfiguracion'.
	cout<<"Inicio de pruebas de 'entornoCargarConfiguracion'"<<endl;
	cargar=entornoCargarConfiguracion(dim, valor, inicio, prob);//detecta si se a podido cargar la configuracion o no, dando valores a demas a las variables antes descritas.
	cout<<"		Configuracion:"<<endl;//muestra por pantalla los valores de las variables escritas en uex2048.cnf para que se pueda comprobar si son correctas o no.
	cout<<"			Dimension: "<<dim<<endl;//dimension del tablero
	cout<<"			Valor: "<<valor<<endl;//valor a alcanzar
	cout<<"			Inicio: "<<inicio<<endl;//numero de valores aleatorios iniciales
	cout<<"			Probabilidad: "<<prob<<endl;//probabilidad de que el numero aleatorio sea 2 y no 4
	if(cargar==true)//prueba que el modulo sea capaz de cargar correctamente el fichero
		cout<<"Prueba 'entornoCargarConfiguracion' CORRECTA"<<endl;
	else
		cout<<"DETECTADO PROBLEMA LEYENDO EL FICHERO <uex2048.cnf>"<<endl;
	cout<<endl;

}

//Complejidad O(1)
//modulo que crea una serie de numeros en el entorno y permite al usuario crear en la posicion que el quiera uno nuevo.
void pr_entornoPonerNumero(){
	int bandera, fila, col, valor;//variables empleadas para: bandera:leer los valores introduccidos por pantalla; los otros para almacenar los datos del numero que crearemos
	cout<<"Inicio de las pruebas de 'entornoPonerNumero'"<<endl;
	cout<<"NOTA: CONSIDERAR LA PRIMERA COLUMNA COMO LA 1 Y NO COMO LA 0 (IGUAL CON LA FILA)"<<endl;
	entornoPonerNumero(0,0,4);		//
	entornoPonerNumero(6,0,1005);	//creo una serie de valores que se mostraran en el tablero
	entornoPonerNumero(0,6,120);	//del entorno.
	entornoPonerNumero(6,6,15);		//
	entornoPonerNumero(3,3,2);		//
	cout<<"		Deben aparecer los siguientes numeros:"<<endl;		//
	cout<<"			Fila: 1		Columna: 1		Valor: 4"<<endl;	//nos muestra por pantalla los numeros creados
	cout<<"			Fila: 7		Columna: 1		Valor: 1005"<<endl;	//y sus posiciones para que comprobemos si esto
	cout<<"			Fila: 1		Columna: 7		Valor: 120"<<endl;	//encaja con lo que aparece en el entorno
	cout<<"			Fila: 7		Columna: 7		Valor: 15"<<endl;	//
	cout<<"			Fila: 4		Columna: 4		Valor: 2"<<endl;	//
	cout<<"		Si es correcto, introduzca 1:"<<endl;
	cin>>bandera;
	if(bandera==1){
		cout<<"		Introduce una fila:"<<endl; //permitimos que el usuario cree un nuevo valor y su posicion para
		cin>>fila;								//mostrarle como el numero creado por el se muestra en entorno
		cout<<"		Introduce una columna:"<<endl;
		cin>>col;
		cout<<"		Introduce un valor(entre 0 y 2048):"<<endl;
		cin>>valor;
		entornoPonerNumero(fila-1, col-1, valor);//le restamos 1 porque hemos considerado la primera fila y colunma como 1 y no como 0
		cout<<"		¿Se ha generado el nuevo numero?(introduce 1 si es correcto, sino, otro):"<<endl;
		cin>>bandera;
		if(bandera==1)
			cout<<"Prueba de 'entornoPonerNumero' CORRECTA"<<endl;
		else
			cout<<"Prueba de 'entornoPonerNumero' FALLIDA"<<endl;
	}
	else
		cout<<"Prueba de 'entornoPonerNumero' FALLIDA"<<endl;
	cout<<endl;
}

//Complejidad O(1)
//modulo que elimina los valores de las casillas que se han asignado predefinidamente en el modulo anterior
void pr_entornoEliminarCasilla(){
	int bandera;
	cout<<"Inicio de las pruebas 'entornoEliminarCasilla'"<<endl;
	cout<<"		Introduzca 1 para proceder a eliminar todos los numeros del tablero excepto el introduccido por usted:"<<endl;
	cin>>bandera;
	if(bandera==1){
		entornoEliminarCasilla(0,0);	//
		entornoEliminarCasilla(6,0);	//eliminamos todos los numeros que se han creado de forma predefinida en
		entornoEliminarCasilla(0,6);	//el modulo anterior.
		entornoEliminarCasilla(6,6);	//en introducido por el usuario no lo eliminamos para no vincular este modulo
		entornoEliminarCasilla(3,3);	//con parametros al anterior y para que vea que no es necesario eliminar todos los valores
	}
	cout<<"		Si se han eliminado todos excepto el suyo introduzca 1(en caso contrario, introduzca otro):"<<endl;
	cin>>bandera;
	if(bandera==1)
		cout<<"Prueba de 'entornoEliminarCasilla' CORRECTA"<<endl;
	else
		cout<<"Prueba de 'entornoEliminarCasilla' FALLIDA"<<endl;
	cout<<endl;
}

//Complejidad O(1)
//modulo que prueba que los mensajes se muestran en el entorno tal y como se debian mostrar
void pr_entornoMostrarMensaje (){
	int bandera;
	cout<<"Inicio de las pruebas de 'entornoMostrarMensaje'"<<endl;
	entornoMostrarMensaje(Zona1, "Zona1(superior)");//mostramos este mensaje en la zona superior de las tres accesibles para nosotros para escribir en el entorno
	entornoMostrarMensaje(Zona2,"Zona2(centro)");//lo mismo pero en la zona intermedia de las tres
	entornoMostrarMensaje(Zona3,"Zona3(inferior)");//lo mismo pero en la zona inferior de las tres
	cout<<"		Si todos los mensajes aparecen en su zona correspondiente introduce 1(sino, otro numero):"<<endl;
	cin>>bandera;
	if(bandera==1)
		cout<<"Prueba de 'entornoMostrarMensaje'CORRECTA"<<endl;
	else
		cout<<"Prueba de 'entornoMostrarMensaje'FALLIDA"<<endl;
	cout<<endl;
}

//Complejidad O(n)
//modulo que escribe en una zona del entorno la letra que ha detectado el programa que hemos pulsado para que nos aseguremos de que reconoce correctamente que tecla hemos pulsado
void pr_entornoLeerTecla(){
	bool salir;//variable utilizada para terminar estas pruebas
	int bandera;
	TipoTecla c;//variable que almacena el valor de la tecla pulsada
	cout<<"Inicio de las pruebas de 'entornoLeerTecla'"<<endl;
	entornoMostrarMensaje(Zona1,"");//eliminamos los mensajes anteriores
	entornoMostrarMensaje(Zona3,"");//
	cout<<"		Cuando quiera terminar estas pruebas pulse ESC sobre el entorno"<<endl;
		while(!salir){
			c= entornoLeerTecla();
			switch(c){
				case TIzquierda:							//para cada tecla hacemos que se escriba en la Zona2
					entornoMostrarMensaje(Zona2, "Izq");	//la tecla pulsada
					break;									//No he hecho desplazamientos porque entonces las pruebas
				case TDerecha:								//se podrian complicar mas de lo expresamente necesario
					entornoMostrarMensaje(Zona2, "Der");
					break;
				case TAbajo:
					entornoMostrarMensaje(Zona2, "Abajo");
					break;
				case TArriba:
					entornoMostrarMensaje(Zona2, "Arriba");
					break;
				case TX:
					entornoMostrarMensaje(Zona2, "Tecla X");
					break;
				case TEnter:
					entornoMostrarMensaje(Zona2, "Enter");
					break;
				case TEliminar:
					entornoMostrarMensaje(Zona2, "Eliminar");
					break;
				case TSalir:
					entornoMostrarMensaje(Zona2, "SALIR");
					salir=true;
					break;
				case TNada:
					break;
			}

		}
	cout<<"		Si todos los mensajes se correspondian con las teclas pulsadas introduzca 1:"<<endl;
	cin>>bandera;
	if(bandera==1)
		cout<<"Prueba de 'entornoLeerTecla'CORRECTA"<<endl;
	else
		cout<<"Prueba de 'entornoLeerTecla'FALLIDA"<<endl;
	cout<<endl;

}

//Complejidad O(1)
//modulo que modifica el valor de la "pausa" que se realiza entre cada orden en el entorno
void pr_entornoPausa (){
	int bandera;
	cout<<"Inicio de las pruebas de 'entornoPausa'"<<endl;
	cout<<"		Pulsa Enter en el entorno para iniciar las pruebas"<<endl;
	if(entornoLeerTecla()==TEnter){//cuando pulsemos ENTER en el entorno comenzaran las pruebas
		entornoMostrarMensaje(Zona2, "SIN PAUSA");	//escribimos una pareja de numeros para cada valor de pausa, de
			entornoPonerNumero(0,0,4);				//manera que el usuario pueda, visualmente, percatar como el tiempo
			entornoPonerNumero(6,0,1005);			//de ejecucion varia bastante
		entornoMostrarMensaje(Zona2, "CON PAUSA");
		entornoMostrarMensaje(Zona3, "250000 ms");
		entornoPausa(250000);
			entornoPonerNumero(0,6,120);
			entornoPonerNumero(6,6,15);
		entornoMostrarMensaje(Zona3, "750000 ms");
		entornoPausa(750000);
			entornoPonerNumero(3,3,2);
			entornoPonerNumero(4,4,6);
	}
	cout<<"		Si las instrucciones han variado su tiempo de ejecucion introduce 1:"<<endl;
	cin>>bandera;
	if(bandera==1)
		cout<<"Prueba de 'entornoPausa'CORRECTA"<<endl;
	else
		cout<<"Prueba de 'entornoPausa'FALLIDA"<<endl;
	cout<<endl;
}

//Complejidad O(1)
//modulo que nos permite comprobar que los marcadores se crean correctamente en el entorno
void pr_entornoPonerMarcadores(){
	int bandera;
	cout<<"Inicio de las pruebas de 'entornoPonerMarcadores'"<<endl;
	entornoPonerMarcadores(); //ponemos los marcadores sin ningun valor en ellos
	cout<<"		¿Ha aparecido el recuadro de los marcadores(introduce 1 si es si)?:"<<endl;
	cin>>bandera;
	if(bandera==1)
		cout<<"Prueba de 'entornoPonerMarcadores'CORRECTA"<<endl;
	else
		cout<<"Prueba de 'entornoPonerMarcadores'FALLIDA"<<endl;
	cout<<endl;
}

//Complejidad O(1)
//modulo que nos permite poner en el entorno el valor maximo que se debe alcanzar
void pr_entornoPonerMaximo(){
	int bandera, max;//max se usa para leer de la pantalla el valor max deseado
	cout<<"Inicio de las pruebas de 'entornoPonerMaximo'"<<endl;
	cout<<" 	Introduce el maximo que deseas alcanzar:"<<endl;
	cin>>max;
	entornoPonerMaximo(max); //permitimos al usuario introducir el valor maximo para que pueda ver como es el valor introducido por él el que se muestra en el marcador de maximo
	cout<<"		Debe aparecer el valor "<<max<<" como maximo dentro de los marcadores"<<endl;
	cout<<" 	Introduce 1 si es asi:"<<endl;
	cin>>bandera;
	if(bandera==1)
		cout<<"Prueba de 'entornoPonerMaximo'CORRECTA"<<endl;
	else
		cout<<"Prueba de 'entornoPonerMaximo'FALLIDA"<<endl;
	cout<<endl;
}

//Complejidad O(1)
//modulo que prueba que se escribe en los marcadores la puntuacion real que llevamos, aunque en este caso no sea la real, ya que solo nos interesa comprobar que la escribe
void pr_entornoPonerPuntuacion(){
	int bandera, punt;
	cout<<"Inicio de las pruebas de 'entornoPonerPuntuacion'"<<endl;
	cout<<" 	Introduce una puntuacion (en el juego la puntuacion se calcula, pero esto es solo una PRUEBA):"<<endl;
	cin>>punt;
	entornoPonerPuntuacion(punt); //permitimos, al igual que en el caso de max, que el usuario lo elija para que sea mas visual
	cout<<"		Debe aparecer el valor "<<punt<<" como puntuacion dentro de los marcadores"<<endl;
	cout<<" 	Introduce 1 si es asi:"<<endl;
	cin>>bandera;
	if(bandera==1)
		cout<<"Prueba de 'entornoPonerPuntuacion'CORRECTA"<<endl;
	else
		cout<<"Prueba de 'entornoPonerPuntuacion'FALLIDA"<<endl;
	cout<<endl;
}

//Complejidad O(1)
//modulo que prueba que se genera correctamente el mensaje que pone fin a nuestra partida al juego uex2048
void pr_entornoMostrarMensajeFin (){
	int bandera;
	cout<<"Inicio de las pruebas de 'entornoMostrarMensajeFin'"<<endl;
	entornoMostrarMensajeFin("HEMOS TERMINADO LAS PRUEBAS!!");	//este mensaje aparece en el medio del entorno
	cout<<"		¿Ha aparecido el mensaje de fin correctamente?"<<endl;
	cout<<" 	Introduce 1 si es asi:"<<endl;
	cin>>bandera;	//con esta lectura de la pantalla se terminan las pruebas de entorno
	if(bandera==1)
		cout<<"Prueba de 'entornoMostrarMensajeFin'CORRECTA"<<endl;
	else
		cout<<"Prueba de 'entornoMostrarMensajeFin'FALLIDA"<<endl;
	cout<<endl;
}

//Complejidad O(1)
//modulo que recopila todas las pruebas del entorno para ejecutarlas en el orden apropiado, de tal manera que no se ejecute un modulo que necesite de otro que aun no ha sido probado
void pruebas_entorno (){
	cout<<"INICIO DE PRUEBAS DE LA LIBRERIA ENTORNO"<<endl;
		pr_entornoIniciar();
		pr_entornoCargarConfiguracion ();
		pr_entornoPonerNumero();
		pr_entornoEliminarCasilla();
		pr_entornoMostrarMensaje ();
		pr_entornoLeerTecla();
		pr_entornoPausa ();
		pr_entornoPonerMarcadores();
		pr_entornoPonerMaximo();
		pr_entornoPonerPuntuacion();
		pr_entornoMostrarMensajeFin ();

	cout<<"FIN DE PRUEBAS DE LA LIBRERIA ENTORNO"<<endl;
	cout<<endl;
}
//
//FIN DE PRUEBAS DE ENTORNO

//PRUEBAS DEL TAD TABLERO
//
//Para realizar las pruebas del entorno de manera mas comoda voy a diseñar un modulo 'auxiliar' que solo empleare en las
//pruebas del tad tablero que me muestre por pantalla el tablero.
void mostrartablero (tablero &T){
	int i, j;
	for(i=0; i<T.tam; i++){
		for (j=0;j<T.tam; j++){
			cout<<T.matriz[i][j];
			cout<<"     "; //para generar un espacio entre numero y numero de la misma fila, de manera que se vea todo mas claro
		}
		cout<<endl;
	}
}

void pr_iniciar_tablero(){
	cout<<"Inicio de pruebas de 'iniciar_tablero'"<<endl;
	int i, j;
	bool error;
	tablero T;
	error=false;
	iniciar_tablero(T, 4);
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			if((T.matriz[i][j]!=0)&&(error==false))
				cout<<"Error para 'iniciar_tablero'"<<endl;
				error=true;
		}
	}
	cout<<"Fin de pruebas de 'iniciar_tablero'"<<endl;
	cout<<endl;
}

void pr_valor_posicion(){
	cout<<"Inicio de pruebas de 'valor_posicion'"<<endl;
	tablero T;
	iniciar_tablero(T, 5);
	T.matriz[0][0]=1; T.matriz[2][1]=3; T.matriz[0][3]=2; T.matriz[3][4]=1;

	if(valor_posicion(T, 0, 0)!=1)
		cout<<"Error para prueba 1 de 'valor_posicion"<<endl;
	if(valor_posicion(T, 2, 1)!=3)
		cout<<"Error para prueba 2 de 'valor_posicion"<<endl;
	if(valor_posicion(T, 0, 3)!=2)
		cout<<"Error para prueba 3 de 'valor_posicion"<<endl;
	if(valor_posicion(T, 3, 4)!=1)
		cout<<"Error para prueba 4 de 'valor_posicion"<<endl;

	cout<<"Fin de pruebas de 'valor_posicion'"<<endl;
}

void pr_desplazar(){
	cout<<"Inicio de pruebas de 'desplazar'"<<endl;								//En este modulo pruebo el modulo desplazar, pero a la vez tambien
	tablero T, F;																//quedan probados los modulos que desplazan en cada sentido
	iniciar_tablero(T,5);
	T.matriz[0][0]=1; T.matriz[0][1]=3; T.matriz[0][3]=2; T.matriz[0][4]=1;
	T.matriz[1][0]=1; T.matriz[1][1]=5; T.matriz[1][3]=5;
	T.matriz[2][2]=6; T.matriz[2][3]=6; T.matriz[2][4]=12;
	//La fila 3 sera nula
	T.matriz[4][0]=6;

	cout<<"Tablero original"<<endl;							//Estas pruebas consisten en realizar cuatro desplazamientos
	mostrartablero(T);										//a un tablero original, uno en cada sentido posible, de
															//manera que el tablero original sufra: primero un
	desplazar(T, 'd');										//desplazamiento a la derecha, sobre este uno a la izquierda
	cout<<"Tablero tras desplazar hacia derecha"<<endl;		//otro hacia arriba, y otro ultimo hacia abajo; enlazado
	mostrartablero(T);										//cada uno de ellos con el anterior.

	desplazar(T, 'i');
	cout<<"Tablero tras desplazar hacia izquierda"<<endl;
	mostrartablero(T);

	desplazar(T, 's');
	cout<<"Tablero tras desplazar hacia arriba"<<endl;
	mostrartablero(T);

	desplazar(T, 'b');
	cout<<"Tablero tras desplazar hacia abajo"<<endl;
	mostrartablero(T);

	iniciar_tablero(F,8);
	F.matriz[0][0]=1; F.matriz[0][4]=3; F.matriz[0][6]=2; F.matriz[0][7]=9;
	F.matriz[1][0]=1; F.matriz[1][1]=5; F.matriz[1][2]=5; F.matriz[1][3]=7;
	F.matriz[2][4]=6; F.matriz[2][5]=6; F.matriz[2][6]=6; F.matriz[2][7]=4;
	F.matriz[3][4]=6;
	//La fila 4 sera nula
	//La fila 5 sera nula
	F.matriz[6][3]=6; F.matriz[6][5]=6;
	//La fila 7 sera nula


	cout<<"Segundo Tablero original"<<endl;					//Estas pruebas consisten en realizar cuatro desplazamientos
	mostrartablero(F);										//a un tablero original, uno en cada sentido posible, de
															//manera que el tablero original sufra: primero un
	desplazar(F, 'd');										//desplazamiento a la derecha, sobre este uno a la izquierda
	cout<<"Tablero tras desplazar hacia derecha"<<endl;		//otro hacia arriba, y otro ultimo hacia abajo; enlazado
	mostrartablero(F);										//cada uno de ellos con el anterior

	desplazar(F, 's');
	cout<<"Tablero tras desplazar hacia arriba"<<endl;
	mostrartablero(F);

	desplazar(F, 'i');
	cout<<"Tablero tras desplazar hacia izquierda"<<endl;
	mostrartablero(F);

	desplazar(F, 'b');
	cout<<"Tablero tras desplazar hacia abajo"<<endl;
	mostrartablero(F);


	cout<<"Fin de pruebas de 'desplazar'"<<endl;
}

void pr_sumarcasillas(){
	cout<<"Inicio de pruebas de 'sumarcasillas'"<<endl;							//En este modulo pruebo el modulo sumarcasillas, pero a la vez tambien
	tablero T;																	//quedan probados los modulos que suman en cada sentido
	iniciar_tablero(T,5);
	T.matriz[0][0]=1; T.matriz[0][1]=3; T.matriz[0][3]=2; T.matriz[0][4]=1;
	T.matriz[1][0]=1; T.matriz[1][1]=5; T.matriz[1][3]=5;
	T.matriz[2][2]=6; T.matriz[2][3]=6; T.matriz[2][4]=12;
	//La fila 3 sera nula
	T.matriz[4][0]=6;

	cout<<"Tablero original"<<endl;
	mostrartablero(T);

	desplazar(T, 'd');
	sumarcasillas(T, 'd');
	cout<<"Tablero tras desplazar hacia derecha y sumar"<<endl;
	mostrartablero(T);

	desplazar(T, 'i');
	sumarcasillas(T, 'i');
	cout<<"Tablero tras desplazar hacia izquierda y sumar"<<endl;
	mostrartablero(T);

	desplazar(T, 's');
	sumarcasillas(T, 's');
	cout<<"Tablero tras desplazar hacia arriba y sumar"<<endl;
	mostrartablero(T);

	desplazar(T, 'b');
	sumarcasillas(T, 'b');
	cout<<"Tablero tras desplazar hacia abajo y sumar"<<endl;
	mostrartablero(T);

	cout<<"Fin de pruebas de 'sumarcasillas'"<<endl;
}

void pr_valormaximo (){
	cout<<"Inicio pruebas de 'valormaximo'"<<endl;								//En esta prueba lo que hago es un tablero
	tablero T;																	//con distintos valores en el.
	iniciar_tablero(T, 5);														//Lo que hago despues es llamar a 'valormaximo'
	T.matriz[0][0]=1; T.matriz[0][1]=3; T.matriz[0][3]=2; T.matriz[0][4]=1;		//con dos valores de maximo a alcanzar. En uno de los casos
	T.matriz[1][0]=1; T.matriz[1][1]=5; T.matriz[1][3]=5;						//ese maximo no ha sido alcanzado, pero en el otro si.
	T.matriz[2][2]=6; T.matriz[2][3]=6; T.matriz[2][4]=12;
	if(valormaximo(T,12)!=true)
		cout<<"Error para prueba 1 de 'valormaximo'"<<endl;
	if(valormaximo(T,24)!=false)
		cout<<"Error para prueba 2 de 'valormaximo"<<endl;
	cout<<"Fin de pruebas de 'valormaximo'"<<endl;
}

void pr_tablero_lleno (){
	cout<<"Inicio pruebas de 'tablero_lleno'"<<endl;						//En esta prueba pruebo que, con dos tableros de distinta dimension,
	tablero T;																//el modulo comprueba correctamente si estan llenos o no. Uno si lo esta, pero el otro no
	iniciar_tablero(T, 5);
	T.matriz[0][0]=1; T.matriz[0][1]=3; T.matriz[0][3]=2; T.matriz[0][4]=1;
	T.matriz[1][0]=1; T.matriz[1][1]=5; T.matriz[1][3]=5;
	T.matriz[2][2]=6; T.matriz[2][3]=6; T.matriz[2][4]=12;
	if(tablero_lleno(T)==true)
		cout<<"Error para prueba 1 de 'tablero_lleno'"<<endl;
	iniciar_tablero(T, 2);
	T.matriz[0][0]=1; T.matriz[0][1]=3;
	T.matriz[1][0]=1; T.matriz[1][1]=5;
	if(tablero_lleno(T)==false)
		cout<<"Error para prueba 2 de 'tablero_lleno'"<<endl;
	cout<<"Fin de pruebas de 'tablero_lleno'"<<endl;
}

void pr_numero_nuevo (){
	cout<<"Inicio pruebas de 'numero_nuevo'"<<endl;			//Esta prueba sigue una mecanica similar al de la anterior prueba
		tablero T;
		int cuantos, i, j;
		cuantos=0;
		iniciar_tablero(T, 5);
		numero_nuevo(T, 0);
		for(i=0; i<T.tam; i++){
			for (j=0;j<T.tam; j++){
				if((T.matriz[i][j]!=4)&&(T.matriz[i][j]!=0))
					cout<<"Error para 'numero_nuevo 1'"<<endl;
				else{
					if(T.matriz[i][j]!=0)
						cuantos++;
				}
			}
		}
		if(cuantos!=1)
			cout<<"Error en la cantidad de 'numero_nuevo 1'"<<endl;

		cuantos=0;
		iniciar_tablero(T, 5);
		numero_nuevo(T, 50);
		for(i=0; i<T.tam; i++){
			for (j=0;j<T.tam; j++){
				if((T.matriz[i][j]!=4)&&(T.matriz[i][j]!=2)&&(T.matriz[i][j]!=0))
					cout<<"Error para 'numero_nuevo 2'"<<endl;
				else{
					if(T.matriz[i][j]!=0)
						cuantos++;
				}
			}
		}
		if(cuantos!=1)
			cout<<"Error en la cantidad de 'numero_nuevo 2'"<<endl;

		cuantos=0;
		iniciar_tablero(T, 5);
		numero_nuevo(T, 100);
		for(i=0; i<T.tam; i++){
			for (j=0;j<T.tam; j++){
				if((T.matriz[i][j]!=2)&&(T.matriz[i][j]!=0))
					cout<<"Error para 'numero_nuevo 3'"<<endl;
				else{
					if(T.matriz[i][j]!=0)
						cuantos++;
				}
			}
		}
		if(cuantos!=1)
			cout<<"Error en la cantidad de 'numero_nuevo 3'"<<endl;

		cout<<"Fin de pruebas de 'numero_nuevo'"<<endl;
}

void pr_valores_iniciales (){
	cout<<"Inicio pruebas de 'valores_iniciales'"<<endl;				//Esta prueba consiste en probar que, cuando se generan los valores iniciales, se generan los que hacen falta
	tablero T;															// y que no son distintos de 2 o 4
	int cuantos, i, j;
	cuantos=0;
	iniciar_tablero(T, 5);
	valores_iniciales(T,4, 50);
	for(i=0; i<T.tam; i++){
		for (j=0;j<T.tam; j++){
			if((T.matriz[i][j]!=2)&&(T.matriz[i][j]!=4)&&(T.matriz[i][j]!=0))
				cout<<"Error para 'valores_iniciales 1'"<<endl;
			else{
				if(T.matriz[i][j]!=0)
					cuantos++;
			}
		}
	}
	if(cuantos!=4)
		cout<<"Error en la cantidad de 'valores_iniciales 1'"<<endl;

	cuantos=0;
	iniciar_tablero(T, 5);
	valores_iniciales(T, 2, 100);
	for(i=0; i<T.tam; i++){
		for (j=0;j<T.tam; j++){
			if((T.matriz[i][j]!=2)&&(T.matriz[i][j]!=0))
				cout<<"Error para 'valores_iniciales 2'"<<endl;
			else{
				if(T.matriz[i][j]!=0)
					cuantos++;
			}
		}
	}
	if(cuantos!=2)
		cout<<"Error en la cantidad de 'valores_iniciales 2'"<<endl;

	cuantos=0;
	iniciar_tablero(T, 5);
	valores_iniciales(T,6, 0);
	for(i=0; i<T.tam; i++){
		for (j=0;j<T.tam; j++){
			if((T.matriz[i][j]!=4)&&(T.matriz[i][j]!=0))
				cout<<"Error para 'valores_iniciales 3'"<<endl;
			else{
				if(T.matriz[i][j]!=0)
					cuantos++;
			}
		}
	}
	if(cuantos!=6)
		cout<<"Error en la cantidad de 'valores_iniciales 3'"<<endl;

	cout<<"Fin de pruebas de 'valores_iniciales'"<<endl;
}

void pr_cambios_producidos(){
	cout<<"Inicio de pruebas de 'cambios_producidos'"<<endl;
	tablero T, Tant;
	iniciar_tablero(Tant, 2);
	iniciar_tablero(T, 2);

	T.matriz[0][0]=0;T.matriz[0][1]=2;
	T.matriz[1][0]=3;T.matriz[1][1]=4;

	Tant.matriz[0][0]=0;Tant.matriz[0][1]=2;
	Tant.matriz[1][0]=3;Tant.matriz[1][1]=4;

	if(cambios_producidos(Tant, T)!=false)
		cout<<"Error para prueba 1 de 'cambios_producidos'"<<endl;

	iniciar_tablero(Tant, 2);
	iniciar_tablero(T, 2);

	T.matriz[0][0]=0;T.matriz[0][1]=2;
	T.matriz[1][0]=3;T.matriz[1][1]=4;

	Tant.matriz[0][0]=0;Tant.matriz[0][1]=1;
	Tant.matriz[1][0]=2;Tant.matriz[1][1]=3;

	if(cambios_producidos(Tant, T)==false)
		cout<<"Error para prueba 2 de 'cambios_producidos'"<<endl;

	cout<<"Fin de pruebas de 'cambios_producidos'"<<endl;
}

void pr_copiaratablero(){
	cout<<"Inicio de pruebas de 'copiaratablero'"<<endl;
	tablero T, Tant;

	iniciar_tablero(Tant, 2);
	iniciar_tablero(T, 2);

	T.matriz[0][0]=0;T.matriz[0][1]=2;
	T.matriz[1][0]=3;T.matriz[1][1]=4;

	copiaratablero(T,Tant);

	if(Tant.matriz[0][0]!=0)
		cout<<"Error para 'copiaratablero' 1"<<endl;

	if(Tant.matriz[0][1]!=2)
			cout<<"Error para 'copiaratablero' 1"<<endl;

	if(Tant.matriz[1][0]!=3)
			cout<<"Error para 'copiaratablero' 1"<<endl;

	if(Tant.matriz[1][1]!=4)
			cout<<"Error para 'copiaratablero' 1"<<endl;

	cout<<"Fin de pruebas de 'copiartablero'"<<endl;
}

void pr_posible_sumar(){
	cout<<"Inicio de pruebas de 'posible_sumar'"<<endl;
	tablero T;

	iniciar_tablero(T, 2);

	T.matriz[0][0]=0;T.matriz[0][1]=2;
	T.matriz[1][0]=3;T.matriz[1][1]=2;

	if(posible_sumar(T)==false)
		cout<<"Error para 'posible_sumar' 1"<<endl;

	iniciar_tablero(T, 2);

	T.matriz[0][0]=0;T.matriz[0][1]=2;
	T.matriz[1][0]=3;T.matriz[1][1]=4;

	if(posible_sumar(T)!=false)
		cout<<"Error para 'posible_sumar' 2"<<endl;


	cout<<"Fin de pruebas de 'posible_sumar'"<<endl;
}

void pruebas_tadtablero(){
	cout<<"INICIO DE LAS PRUEBAS DEL TAD TABLERO"<<endl;
	pr_iniciar_tablero();
	pr_valor_posicion();
	pr_desplazar();
	pr_sumarcasillas();
	pr_valormaximo();
	pr_tablero_lleno();
	pr_valores_iniciales();
	pr_numero_nuevo();
	pr_cambios_producidos();
	pr_copiaratablero();
	pr_posible_sumar();
	cout<<"FIN DE LAS PRUEBAS DEL TAD TABLERO"<<endl;
}
//
//FIN DE PRUEBAS DEL TAD TABLERO

//INICIO DE PRUEBAS DE JUEGO
//

void pr_sentido_movimiento(){
	cout<<"Inicio pruebas de 'sentido_movimiento'"<<endl;
	char sentido;

	sentido=sentido_movimiento(TIzquierda);
	if(sentido!='i')
		cout<<"Error para la prueba 1 de sentido_movimiento"<<endl;

	sentido=sentido_movimiento(TDerecha);
	if(sentido!='d')
		cout<<"Error para la prueba 2 de sentido_movimiento"<<endl;

	sentido=sentido_movimiento(TArriba);
	if(sentido!='s')
		cout<<"Error para la prueba 3 de sentido_movimiento"<<endl;

	sentido=sentido_movimiento(TAbajo);
	if(sentido!='b')
		cout<<"Error para la prueba 4 de sentido_movimiento"<<endl;
	cout<<"Fin pruebas de 'sentido_movimiento'"<<endl;
}

void pruebas_juego(){ //Solo hago pruebas de un modulo porque el resto de modulos tan solo recogen instrucciones de otras librerias que ya han sido probadas previamente.
	cout<<"INICIO DE LAS PRUEBAS DEL TAD JUEGO"<<endl;
	pr_sentido_movimiento();
	cout<<"FIN DE LAS PRUEBAS DEL TAD JUEGO"<<endl;

}
//
//FIN DE PRUEBAS DE JUEGO

void pruebas(){
	int bandera;
	cout<<endl;
	cout<<"Seleccione que pruebas quiere realizar:"<<endl;
	cout<<"		0.Todas"<<endl;
	cout<<"		1.Libreria Entorno"<<endl;
	cout<<"		2.TAD Tablero"<<endl;
	cout<<"		3.Juego"<<endl;
	cout<<"		4.SALIR DE LAS PRUEBAS"<<endl;
	cout<<"Introduzca el valor:"<<endl;
	cin>>bandera;
	if(bandera==0){
		pruebas_entorno();
		pruebas_tadtablero();
		pruebas_juego();
	}
	if(bandera==1)
		pruebas_entorno();
	if(bandera==2)
		pruebas_tadtablero();
	if(bandera==3)
		pruebas_juego();
	if(bandera==4)
		cout<<"Saliendo de las pruebas"<<endl;
	cout<<endl;
}


