/**
 * @file Tarjetas.c
 * @brief Juego de tarjetas, encuentra todos los pares de tarjetas (Numericas)
 * @note Este es un juego de terminal, no esperes una maravilla :v
 * @author JuanMeza (Mezita)
 * @date 18 de agosto del 2026 (18th august)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
/**
 * @brief Rellena la matriz de tarjetas con numeros aleatorios
 * @note Utiliza otra funcion para poder reconocer que no se repitan mas de dos veces los numeros al
 * @param Puntero a la matriz de enteros (Tarjetas) de 4x4
 * @return Void
 */
void rellenarMatriz(int matriz[4][4]);
void mostrarMatriz(int matriz[4][4]);
void aleatorizarVector(int vector[16]);

void empezarJuego();
void interfaz(int matriz[4][4]);
void mostrarOcultarMatriz(int matriz[4][4]);
void mostrarMatrizOculta();
void itzMenu1();
void itzMenu2();


int main (int argc, char *argv[]){
	empezarJuego();
	return 0;
}
void rellenarMatriz (int matriz[4][4]){
	srand(time(NULL));
	int vector[16] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
	aleatorizarVector(vector);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			matriz[i][j] = vector[i * 4 + j];
		}
	}
}
void mostrarMatriz(int matriz[4][4]){
	printf("=====MATRIZ=====\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("|");
			printf("%d", matriz[i][j]);
		}
		printf("\n");
		printf("----------------\n");
	}
}
void aleatorizarVector(int vector[16]){
	int temp = 0;
	int random = 0;
	int random2 = 0;
	for (int i = 0; i<16; i++){
		random = rand() % 16;
		random2 = rand() % 16;
		temp = vector[random];
		vector[random] = vector[random2];
		vector[random2] = temp; 
	}
}

void empezarJuego(){
	int matriz[4][4] = {0};
	rellenarMatriz(matriz);
	itzMenu1();
	mostrarOcultarMatriz(matriz);
}
void interfaz(int matriz[4][4]){
	itzMenu1();
	itzMenu2();
}
void mostrarOcultarMatriz(int matriz[4][4]){
	for(int i = 0; i < 4; i++){
		printf("Volteando tarjetas en %d...\n", 4 - i);
		mostrarMatriz(matriz);
		sleep(1);
		system("cls");
	}
}
void mostrarMatrizOculta(){
	printf("=====MATRIZ=====\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("|");
			printf("*");
		}
		printf("\n");
		printf("----------------\n");
	}
}
void itzMenu1(){
	printf("Bienvenido al juego de tarjetas\n");
	printf("El objetivo del juego es encontrar todos los pares de tarjetas\n");
	printf("Para ello, deberas ingresar las coordenadas de las tarjetas que deseas voltear\n");
	printf("Si las tarjetas son iguales, se quedaran volteadas, de lo contrario, se volveran a voltear\n");
	system("pause");
	system("cls");
}
void itzMenu2(){
	printf("Ingrese las coordenadas de la primera tarjeta (fila y columna)\n");
	mostrarMatrizOculta();
}