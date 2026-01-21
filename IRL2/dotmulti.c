#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main () {
    int N = 512 * 1024 * 1024;
    int max_n = 22;
    int *A, *B;
    long dot_product = 0;
    double begin,end; // Timestamps for beginning and end of computation

    //Allocate Array A and B with N elements
    //Fill in
    A = (int*) malloc((size_t)N * sizeof(int));
    B = (int*) malloc((size_t)N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        A[i] =  rand() %  max_n; /* change as desired */
        B[i] = rand() %  max_n;
    }
    //Initialize arrays
    //Fill in. Loop through A and B and fill in initial value

    //Now running time-stamp
    begin = omp_get_wtime();
    //Fill in. Loop and generate dot-product
    #pragma omp parallel for reduction(+:dot_product)
    for (int i; i < N; i++)
    {
        dot_product += A[i]*B[i];
    }
    end = omp_get_wtime();

    printf("The final dotproduct is %ld\n", dot_product);
    printf("Time to execute was %lfs\n", end-begin);

    return 0;
}
