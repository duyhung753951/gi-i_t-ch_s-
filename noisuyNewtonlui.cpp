#include<stdio.h>
 void Newton(int n, float x[], float y[],float x0){
 	int i,j;
 	float bangsaiphan[4][4];
 	for(i=0;i<n;i++){
 		bangsaiphan[i][0]=y[i];
	 }
	for(j=1;j<n;j++){
		for(i=0;i<n-j;i++){
			bangsaiphan[i][j]=(bangsaiphan[i+1][j-1]-bangsaiphan[i][j-1])/(x[i+j]-x[i]);
		}
	}
	printf("Bang sai phan:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			printf("%f ",bangsaiphan[i][j]);
		}
		printf("\n");
	}
	float total=y[n-1],t=1;
	for(i=1;i<n;i++){
		t*=(x0-x[n-i]);
		total+=bangsaiphan[n-i-1][i]*t;
	}
	printf("Ket qua noi suy tai %f la: %f",x0,total); 
 }
 int main(){
 	int n=4;
 	float x[4]={0, 0.3, 0.7, 1.0};
 	float y[4]={2, 2.2599, 2.5238, 2.7183};
 	float x0;
 	printf("Nhap vao gia tri can noi suy:");
 	scanf("%f",&x0);
 	Newton(n,x,y,x0);
 } 
