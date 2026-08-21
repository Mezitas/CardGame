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
void mostrarOcultarMatriz(int matriz[4][4]);
void mostrarMatrizOculta();
void organizarVector(int vector[16]);
void mostrarEntcontrado(int matriz[4][4], int x[16], int y[16]);
int coordenadaY();
int coordenadaX();
int verificarX();
int verificarY();
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
	int vectorPosicionesX[16] = {-1};
	int vectorPosicionesY[16] = {-1};
	int intentos = 0;
	rellenarMatriz(matriz);
	itzMenu1();
	mostrarOcultarMatriz(matriz);
}
void mostrarOcultarMatriz(int matriz[4][4]){
	for(int i = 0; i < 5; i++){
		printf("Volteando tarjetas en %d...\n", 5 - i);
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
void mostrarEntcontrado(int matriz[4][4], int x[16], int y[16]){
	printf("=====MATRIZ=====\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("|");
			if(i == x[i*4 + j] && j == y[i*4 + j]){
				printf("%d", matriz[i][j]);
			}else{
				printf("*");
			}
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
	printf("Ingrese las coordenadas de la tarjeta (fila y columna)\n");
	mostrarMatrizOculta();
}
int coordenadaY(){
	int coordenadaY;
	printf("Ingrese la columna de la tarjeta: ");
	scanf("%d", &coordenadaY);
	return coordenadaY;
}
int coordenadaX(){
	int coordenadaX;
	printf("Ingrese la fila de la tarjeta: ");
	scanf("%d", &coordenadaX);
	return coordenadaX;
}
int verificarX(){
	int x = coordenadaX();
	if(x < 0 || x > 3){
		printf("Coordenada invalida, ingrese un numero entre 0 y 3\n");
		verificarX();
	}
	return x;
}
int verificarY(){
	int y = coordenadaY();
	if(y < 0 || y > 3){
		printf("Coordenada invalida, ingrese un numero entre 0 y 3\n");
		verificarY();
	}
	return y;
}
void organizarVector(int vector[16]){
	int temp = 0;
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			if(vector[i] < vector[j]){
				temp = vector[i];
				vector[i] = vector[j];
				vector[j] = temp;
			}
		}
	}
}
void moverPosiciones(int x[16], int y[16], int posX, int posY, int index){
	x[index] = posX;
	y[index] = posY;
}