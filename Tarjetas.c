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
/**
 * @brief Encuentra si dentro de la matriz ya exite un par de numeros y no deja que exista un tercer numero
 * @note Se utiliza en otra funcion
 * @see rellenarMatriz(int (*matriz)[4]);
 * @param la matriz ACTUAL del loop de rellenado
 * @param El numero aleatorio de loop actual
 * @retval 1 si true, 0  si false
 * @return integer
 */ 
int findPair(int matriz[4][4], int aleatorio);
void mostrarMatriz(int matriz[4][4]);
int main (int argc, char *argv[]){
	int matriz[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	rellenarMatriz(matriz);
}
void rellenarMatriz (int (*matriz)[4]){
	srand(time(NULL));
	int n = 1;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			n += rand() % 8;
			if(findPair(matriz, n) == 1){
				matriz[i*4 + j] = n;
			}
		}
	}
	mostrarMatriz(matriz);
}
int findPair(int matriz[4][4], int aleatorio){
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < 4){
		if(k > 2){
			return 0;
		}
		if( aleatorio == matriz[i][j] ){
			k++;
		}
		j++;
		if(j == 3){
			i++;
			j = 0;
		}
	}
	return 1;
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
