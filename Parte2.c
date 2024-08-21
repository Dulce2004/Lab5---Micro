#include <stdio.h>
#include <omp.h>

#define N 1000000

int main(){

    #pragma omp parallel for reduction(+ : sum)
        int i;
        int sum = 0;

        for(i=0; i < N; i++){
            sum += N;
        }

        printf ("El valor de la suma final es: %d\n", sum);
        printf ("El tiempo transcurrido fue: %d\n", omp_get_wtime());

        return 0 ; 
    
}
