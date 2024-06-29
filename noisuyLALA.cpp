#include<stdio.h>
 void Nhapmang(int n, float a[]){
 	int i;
 	for(i=0;i<n;i++){
 		scanf("%f",&a[i]);
	 }
 }
 float LL(int n, float x0, float x[], float y[]){
 	int i,j;
 	float L=0;
 	for(i=0;i<n;i++){
 		float t=y[i];
		 for(j=0;j<n;j++){
		 	if(j!=i){
		 		t*=(x0-x[j])/(x[i]-x[j]);
			 }
		 }
		 L+=t; 
	 }
	 return L;
 }
 int main(){
 	int n;
 	printf("So moc noi suy la:");
 	scanf("%d",&n);
 	float x[n],y[n];
 	printf("Nhap vao cac moc gia tri cua x:");
 	Nhapmang(n,x);
 	printf("Nhap vao cac moc gia tri cua y:");
 	Nhapmang(n,y);
 	float x0;
 	printf("Nhap gia tri can noi suy:");
 	scanf("%f",&x0);
 	float total = LL(n,x0,x,y);
 	printf("ket qua la:%f",total);
 }
