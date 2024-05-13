#include "stdio.h"
#include "omp.h"

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Hola Mundo desde el hilo %d\n", id);
    }
    return 0;
}