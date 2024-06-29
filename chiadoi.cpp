/**
   giai phuong trinh:
        x-2^-x=0 for (0<=x<=1), e=10^-5      
**/ 
#include<stdio.h>
#include<math.h>

 float f(float x){
 	return x- pow(2,-x); 
 }
 float Giaipt(float a, float b, float e){
 	float x;
	while(b-a>=e){
 	    x=(a+b)/2;
 		if(f(a)*f(x)>0){
 			a=x;
		 }else{
		 	b=x;
		 }
	 }
	return x; 
 }
 int main(){
 	float a=0,b=1,e=0.000001;
 	printf("Ket qua la:%f",Giaipt(a,b,e));
 }
