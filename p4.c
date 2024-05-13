#include "stdio.h"
#include "omp.h"
void matriz(int n,int m[n][n]){
	for(int i =0;i<n;i++){
		for (int j=0;j<n;j++){
			m[i][j]=(i+1)*(j+1);
		}
	}
}
void vector(int n,int m[n]){
	for(int i =0;i<n;i++){
		m[i]=(i+1);
	}
}
void mostrar(int n,int v[n]){
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}
	printf("\n");

}
void mxv(int n, int m[n][n], int v[n], int r[n]) {
    #pragma omp parallel for 
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += (m[i][j] * v[j]);
        }
        r[i] = s;
    }
}



int main(){
	int n=5;
	int m[n][n];
	int v[n];
	matriz(n,m);
	vector(n,v);
	int r[n];
	mxv(n,m,v,r);
	mostrar(n,r);
		


}
