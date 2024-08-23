/*
* ------------------------------------------------------------
* Parte2.c
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
* Ver.: 1.1 2024/24/08
* Autor: Dulce Ambrosio - 231143
*
* References:
*Aprende OpenMP en paralelo.dev, s.f
*
* Descripcion:
* Calcula la suma de los primeros N numeros (N=1000000) usando
* el ciclo for parallel y reduction con + para la acumulacion
* de la suma.
* ------------------------------------------------------------
*/
#include <stdio.h> // Biblioteca para la salida y entrada de datos
#include <omp.h> // Biblioteca para el uso de la programacion paralela

int main(){

    int N = 1000000; // La cantidad de numeros que se van a sumar
    int suma = 0; // Variable que almacena la suma

        double start_time, end_time; // se declaran las variable para el tiempo de inicio y fin de la ejecucion

        start_time = omp_get_wtime(); // se inicia a medir el tiempo de la ejecucion
        #pragma omp parallel for reduction(+:suma) // se inicia el bucle for en paralelo y con la clausula reduction
            for(int i=1; i<=N ; i++){ // se inicia el ciclo para realizar el suma de los valores de N
                suma = suma + i;
            } 
        end_time = omp_get_wtime(); //se deja de medir el tiempo de ejecucion y se captura el valor

        printf("La suma total es: %d\n", suma); // se imprime el valor de la suma
        printf("El tiempo de ejecucion es: %f segundos.\n", end_time - start_time); // se imprime el tiempo de ejecucion

    return 0;
}