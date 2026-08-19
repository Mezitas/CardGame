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
/**
 * @brief Rellena la matriz de tarjetas con numeros aleatorios
 * @note Utiliza otra funcion para poder reconocer que no se repitan mas de dos veces los numeros al
 * @param Puntero a la matriz de enteros (Tarjetas) de 4x4
 * @return Void
 */
void rellenarMatriz(int (*matriz)[4]);
void mostrarMatriz(int matriz[16]);
int main (int argc, char *argv[]){
	int matriz[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	rellenarMatriz(matriz);
}
void rellenarMatriz (int *matriz[16]){
	srand(time(NULL));
	int n = 1;
	for(int i = 0; i < 16; i++){
		n += rand() % 8;
		matriz[i] = n;
	}
	mostrarMatriz(matriz);
}
void mostrarMatriz(int matriz[16]){
	printf("=====MATRIZ=====\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("|");
			printf("%d", matriz[i*j]);
		}
		printf("\n");
		printf("----------------\n");
	}
}
