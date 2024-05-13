#include <stdio.h>
#include <mpi.h>

void matriz(int n, int m[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = (i + 1) * (j + 1);
        }
    }
}

void vector(int n, int m[n]) {
    for (int i = 0; i < n; i++) {
        m[i] = (i + 1);
    }
}

void mostrar(int n, int v[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void mxn(int n, int m[n][n], int v[n], int r[n], int p, int c) {
    int rl[n];
    for (int i = 0; i < n; i++) {
        rl[i] = 0;
        for (int j = 0; j < n; j++) {
            rl[i] += m[i][j] * v[j];
        }
    }
    MPI_Gather(rl, n, MPI_INT, r, n, MPI_INT, 0, MPI_COMM_WORLD);
}

int main(int argc, char *argv[]) {
    int n = 5;
    int m[n][n];
    int v[n];
    int r[n];
    int p, c;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &p);
    MPI_Comm_size(MPI_COMM_WORLD, &c);

    if (p == 0) {
        matriz(n, m);
        vector(n, v);
    }

    mxn(n, m, v, r, p, c);

    if (p == 0) {
        printf("Resultado:\n");
        mostrar(n, r);
    }

    MPI_Finalize();
    return 0;
}
