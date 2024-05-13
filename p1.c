#include "stdio.h"
int suma(int a,int b){
	int s=a+b;
	return s;
}
int resta(int a,int b){
	int s=a-b;
	return s;
}
int mul(int a,int b){
	int r=0;
	int *s=&r;
	int i;
	for (i=0;i<b;i++){
		*s+=a;
	}
	return r;
}
int div(int a,int b){
	int r=0;
	int *i=&r;
	while(a>=b){
		a-=b;
		*i+=1;
	}
	return r;
}

int main(){
	int x=5;
	int y=2;
	printf("suma:  %d \n",suma(x,y));
	printf("resta:  %d \n",resta(x,y));
	printf("multi:  %d \n",mul(x,y));
	printf("divi:  %d \n",div(x,y));
	



}
