#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &n);
    
    int nth;
    #pragma omp parallel
    {
        nth = omp_get_num_threads();
    }

    int v[n];
    int k[nth][n];

    #pragma omp parallel
    {
    	for (int i = 0; i < n; i++) {
        	v[i] = (i + 1) * 2;
    	}
    }

    #pragma omp parallel
    {
        int th = omp_get_thread_num();
        int i;
        
        #pragma omp private(i) shared(v)
        	
        for (i = 0; i < n; i++) {
            k[th][i] = v[i];
        }
    }

    printf("Matriz generada:\n");
    for (int j = 0; j < nth; j++) {
        for (int i = 0; i < n; i++) {
            printf("%d ", k[j][i]);
        }
        printf("\n");
    }
}
