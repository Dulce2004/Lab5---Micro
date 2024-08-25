/*
* ------------------------------------------------------------
* Parte3.c
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3086 - Programacion de Microprocesadores
* Ver.: 1.1 2024/24/08
* Autor: Dulce Ambrosio - 231143
*
* Descripcion:
* Se imprime el valor del fibonacci 21, el factorial de 5, 
* y el numero maximo y minimo de un arreglo, estas operaciones
* se realizan en secciones paralelas.
* ------------------------------------------------------------
*/
#include <stdio.h> // Biblioteca para la salida y entrada de datos
#include <stdlib.h> // Biblioteca para realizar operaciones matematicas entre otros
#include <omp.h>// Biblioteca para el uso de la programacion paralela

int main (){

    #pragma omp parallel sections //se inicia la paralelizacion en secciones
    {
        #pragma omp section // se inicia la seccion paralela del factorial
        {
            int a = 5; // valor del cual se sacara el factorial
            int fac = 1; //se inicia el factorial en 1, ya que si inicia en 0 el valor sera 0

            for (int i=a; i > 0; i--){  // bucle que calcula el factorial
                fac = fac * i;
            } 
            printf ("___________________________________________________________\n");
            printf ("El resultado del factorial de 5 es: %d\n", fac);  // se imprime el valor del resultado
        }

        #pragma omp section // se inicia la seccion paralela del fibonacci
        {
            int x = 0; // es el valor inicial de la secuencia
            int y = 1; // inicia la secuencia
            int z; // es la variable que almacenara el valor del fibonacci

            for(int i = 1; i <=20; i++){ // bucle que calcula el fibonacci
                z = x + y;
                x = y;
                y = z;
            }
            printf ("___________________________________________________________\n");
            printf("El resultado del fibonacci de 21 es: %d\n", z); // se imprime el valor del fibonacci
        }

        #pragma omp section // se inicia la seccion para encontrar el minimo y maximo del arreglo
        {
            int arreglo[11] = {0 , 11, 39, 3, 43, 5, 25, 7, 84, 9, 10}; //el arreglo y sus valores
            int num_mayor = 0; 
            int num_menor = 0;

            for(int i =0; i <= 10; i++){ // bucle que recorre el arreglo
                if(arreglo[i] > num_mayor){ // bucle que busca el numero maximo y minimo
                    num_mayor = arreglo[i];
                }else if (arreglo[i] < num_menor){
                    num_menor = arreglo[i];
                }
            }
            printf ("___________________________________________________________\n");
            printf ("El numero maximo/mayor en el arreglo es: %d\n", num_mayor); // imprime el numero maximo del arreglo
            printf ("El numero minimo/menor en el arreglo es: %d\n", num_menor); // imprime el numero minimo del arreglo
        }
    }
    return 0;
}