#include<stdio.h>
#include<math.h>
 float f(float x){
 	return exp(x)+pow(2,-x)+2*cos(x)-6;//f(x)
 }
 float Df(float x){
 	return exp(x)-pow(2,-x)*log(2)-2*sin(x);//f'(x)
 }
 int main(){
 	float x0,x1,e,err;
 	printf("Nhap vao x0 va e:");
 	scanf("%f%f",&x0,&e);
 	while(1){
 		x1=x0 - f(x0)/Df(x0);
 		err=fabs(x1-x0);
 		x0=x1;
 		if(err<=e) break;
	 }
	printf("ket qua la:%f",x1); 
 } 
