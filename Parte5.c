/*
* ------------------------------------------------------------
* Parte5.c
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
* Ver.: 1.1 2024/24/08
* Autor: Dulce Ambrosio - 231143
*
* Descripcion:
* Se utiliza la descomposicion de tareas de manera recursiva
* para generar tantas tareas como hilos y conocer el numero
* de veces que aparece el key.
* ------------------------------------------------------------
*/
#include <stdio.h> // Biblioteca para la salida y entrada de datos
#include <stdlib.h> // Biblioteca para realizar operaciones matematicas entre otros
#include <omp.h>// Biblioteca para el uso de la programacion paralela

#define N 131072 // indica el tamaño del arreglo
#define THRESHOLD 1024  // Se utilizara para dividir la tarea de manera secuencial

long count_key_parallel(long Nlen, long *a, long key) { // es para contar las apariciones del key
    long contador = 0;

    // bucle para iniciar el proceso de manera secuencial
    if (Nlen < THRESHOLD) {
        for (int i = 0; i < Nlen; i++)
            if (a[i] == key) contador++;
    } else {
        // divide el arreglo en dos y realiza el proceso en paralelo
        long mid = Nlen / 2;
        long contador1 = 0, contador2 = 0;

        #pragma omp task shared(a, key, contador1)
        contador1 = count_key_parallel(mid, a, key);

        #pragma omp task shared(a, key, contador2)
        contador2 = count_key_parallel(Nlen - mid, a + mid, key);

        #pragma omp taskwait
        contador = contador1 + contador2;
    }

    return contador;
}

int main() {
    long a[N], key = 42, nkey = 0;

    // el arreglo se realiza de forma aleatoria
    for (long i = 0; i < N; i++) a[i] = rand() % N;
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;

    // Cuenta cuantas veces aparece el key
    #pragma omp parallel
    {
        #pragma omp single
        nkey = contador_key_parallel(N, a, key);
    }

    printf("Numero de veces que 'key' aparece: %ld\n", nkey); //imprime el valor de cuantas veces aparece key

    return 0;
}
