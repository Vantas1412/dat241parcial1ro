#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        fprintf(stderr, "Se requieren al menos 2 procesadores (MASTER y SLAVE)\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int n;
    if (rank == 0) {
        printf("Ingrese el número de términos de Fibonacci a calcular: ");
        scanf("%d", &n);
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    long long int a = 0, b = 1;
    long long int c;
    for (int i = 2; i < n; i++) {
        if (rank == 0) {
            printf("%lld ", a);
            MPI_Send(&i, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
            MPI_Recv(&c, 1, MPI_LONG_LONG_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            a = b;
            b = c;
        } else {

            MPI_Recv(&c, 1, MPI_LONG_LONG_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Send(&b, 1, MPI_LONG_LONG_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
            a = b;
            b = c;
        }
    }

    if (rank == 0) {
        printf("%lld %lld\n", a, b);
    }

    MPI_Finalize();

    return 0;
}
