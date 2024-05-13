#include <stdio.h>
#include <math.h>
#include <mpi.h>


double f(double x) {
    return 4.0 / (1.0 + x * x);
}


int main(int argc,char *argv[] ){
	int r,s;
	int p=1000000;
	double st, et;
	double iw = 1.0 / (double)p;
    	double ts = 0.0;
    	double ls = 0.0;
    	st= MPI_Wtime();
	
	MPI_Init(&argc, &argv);
    	MPI_Comm_rank(MPI_COMM_WORLD, &r);
    	MPI_Comm_size(MPI_COMM_WORLD, &s);
	int nip=p/s;
	int si=r*nip;
	int ei=si+nip;
	for (int i=si;i<ei;i++){
		double x=(i+0.5)*iw;
		ls+=f(x);
	}
	MPI_Reduce(&ls, &ts, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if (r == 0) {
        double pi = ts*iw;
        et = MPI_Wtime();
        printf("Estimated value of pi: %f\n", pi);
        printf("tiempo ejecucion: %f\n", et-st);
    	}

    	MPI_Finalize();
	
	
	
}
