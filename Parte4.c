/*
* ------------------------------------------------------------
* Parte4.c
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
* Ver.: 1.1 2024/24/08
* Autor: Dulce Ambrosio - 231143
*
* Descripcion:
* Con el ciclo for en paralelo se modifican dos variables
* mientras que la variable 1 es compartida con la variable2
* y la variable2 es privada
* ------------------------------------------------------------
*/
#include <stdio.h> // Biblioteca para la salida y entrada de datos
#include <stdlib.h> // Biblioteca para realizar operaciones matematicas entre otros
#include <omp.h>// Biblioteca para el uso de la programacion paralela

int main (){

    int variable1 = 0; // esta variable sera compartida (shared) con el resto de los hilos
    int variable2 = 0; // esta variable sera privada (private)

    #pragma omp parallel for // ciclo parallel for
    for(int i = 0; i < 10; i++ ){ 
        variable2 = i + 1; 
        variable1 += variable2; // se comparte la variable 1

        printf("Hilo %d, Iteracion %d: variable1 = %d, variable2 = %d\n", omp_get_thread_num(), i, variable1, variable2); // se imprimen los valores de las iteraciones
    }
    printf("Resultado final de la variable1 es: %d\n", variable1); // se imprime el valor de la variable1, la cual es compartida, despues de ser modificada.

    return 0;

}