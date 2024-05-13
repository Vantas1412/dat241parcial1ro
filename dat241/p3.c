#include "stdio.h"
#include "omp.h"
int mul(int a , int b){
	int r=0;
	#pragma omp parallel for reduction(+:r)
	for (int i=0;i<b;i++){
		r+=a;
	}
	return r;
}
int div(int a,int b){
	int r=0;
	#pragma omp parallel 
	{
	while (a>=b){
		#pragma omp critical
		{
		a-=b;
		r+=1;
		}
		#pragma omp barrier 
	}
	}
	
	return r;

}
int main(){
	printf("Multiplicacion usando mpi: %d \n",mul(2,1000000000));
	printf("division usando mpi: %d \n",div(100000,2));

}
