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
int coordenadaY();
int coordenadaX();
int verificarX();
int verificarY();
void itzMenu1();
void itzMenu2(int matriz[4][4], int intentos);
void descurbrirPosiciones(int x, int y, int matriz[4][4]);
int encontrar(int x, int y, int xAnterior, int yAnterior, int matriz[4][4]);
int terminado(int matriz[4][4]);
int yaEncontrado(int x, int y, int matriz[4][4]);

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
	for (int i = 0; i < 16; i++){
		random = rand() % 16;
		random2 = rand() % 16;
		temp = vector[random];
		vector[random] = vector[random2];
		vector[random2] = temp; 
	}
}
void empezarJuego(){
	int matrizInicial[4][4] = {0};
	int matrizEncontrar[4][4] = {0};
	int coorX = 0;
	int coorY = 0;
	int coorYAnterior = 0;
	int coorXAnterior = 0;
	int noCarta = 0;
	int intentos = 0;
	rellenarMatriz(matrizInicial);
	itzMenu1();
	mostrarOcultarMatriz(matrizInicial);
	while(intentos < 3){
		itzMenu2(matrizEncontrar, intentos);
		coorX = verificarX();
		coorY = verificarY();
		if(yaEncontrado(coorX, coorY, matrizEncontrar) == 0){
			matrizEncontrar[coorX][coorY] = matrizInicial[coorX][coorY];
			noCarta++;
			if(noCarta == 1){
				coorXAnterior = coorX;
				coorYAnterior = coorY;
			}else if(noCarta == 2){
				intentos += encontrar(coorX, coorY, coorXAnterior, coorYAnterior, matrizEncontrar);
				noCarta = 0;
			}
		}
		
		if(terminado(matrizEncontrar) == 1){
			intentos = 10;
			system("cls");
			printf("\n\nFelicidades, ganaste!\n");
			sleep(3);
			return;
		}
	}
	if(intentos >= 3){
		printf("\n\nSe acaboooo, perdiste todos tus intentos...\n");
		system("pause");
	}
}
void mostrarOcultarMatriz(int matriz[4][4]){
	for(int i = 0; i < 5; i++){
		printf("Volteando tarjetas en %d...\n", 5 - i);
		mostrarMatriz(matriz);
		sleep(1);
		system("cls");
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
void itzMenu2(int matriz[4][4], int intentos){
	printf("\n\nNumero de intentos: %d\n\n",3-intentos);
	printf("Ingrese las coordenadas de la tarjeta (fila y columna)\n");
	mostrarMatriz(matriz);
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
		printf("Coordenada en X invalida, ingrese un numero entre 1 y 4\n");
		return verificarX();
	}
	return x-1;
}
int verificarY(){
	int y = coordenadaY();
	if(y < 0 || y > 3){
		printf("Coordenada en Y invalida, ingrese un numero entre 1 y 4\n");
		return verificarY();
	}
	return y-1;
}
int encontrar(int x, int y, int xAnterior, int yAnterior, int matriz[4][4]){
	if(matriz[x][y] != matriz[xAnterior][yAnterior]){
		matriz[x][y] = 0;
		matriz[xAnterior][yAnterior] = 0;
		printf("\n\nCarta incorrecta, intente de nuevo\n\n");
		return 1;
	}
	return 0;
}
int terminado(int matriz[4][4]){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(matriz[i][j] == 0){
				return 0;
			}
		}
	}
	return 1;
}
int yaEncontrado(int x, int y, int matriz[4][4]){
	if(matriz[x][y] != 0){
		printf("La tarjeta ya fue encontrada, ingrese otra coordenada\n");
		return 1;
	}
	return 0;
}