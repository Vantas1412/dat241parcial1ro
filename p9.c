#include "stdio.h"
#include "mpi.h"

int main(int argc, char *argv[]) {
    int n;
    int r, s;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &s);
    if (r== 0) {
        printf("Ingrese el tamaño del vector: ");
        scanf("%d", &n);
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    int v[n];
    int k[s][n];
    for (int i = 0; i < n; i++) {
        v[i] = (i + 1) * 2;
    }
    int ck=n/s;
    int st=r*ck;
    int et= (r==s-1) ? n: st+ck;
    for (int i=st;i<et;i++){
    	for (int j=0;j<n;j++){
    		k[r][j]=v[j];
    	}
    }
    MPI_Gather(k[r], n, MPI_INT, k, n, MPI_INT, 0, MPI_COMM_WORLD);
    if (r == 0) {
        printf("Matriz generada:\n");
        for (int j = 0; j < s; j++) {
            for (int i = 0; i < n; i++) {
                printf("%d ", k[j][i]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    
    
}


