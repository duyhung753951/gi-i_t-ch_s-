#include<stdio.h>
 void Nhapmang(int n, float a[]){
 	int i;
 	for(i=0;i<n;i++){
 		scanf("%f",&a[i]);
	 }
 }
 void noisuyNewton(int n, float x0, float x[], float y[]){
 	float bangsaiphan[100][100];
 	int i,j;
 	
 	for(i=0;i<n;i++){
 		bangsaiphan[i][0]=y[i];
	}
	 
	for(j=1;j<n;j++){
        for(i=0;i<n-j;i++){
            bangsaiphan[i][j]=(bangsaiphan[i+1][j-1]-bangsaiphan[i][j-1])/(x[i+j]-x[i]);
        }
    }
    printf("Bang ti sai phan:\n");
	for(i=0;i<n;i++){
		printf("%.4f ",x[i]); 
 		for(j=0;j<n-i;j++){
 		printf("%.4f ",bangsaiphan[i][j]);
	   }
	 printf("\n");
   }
   float ketqua=bangsaiphan[0][0];
   float temp=1;
   for(j=1;j<n;j++){
   	temp*=(x0-x[j-1]);
   	ketqua+=bangsaiphan[0][j]*temp;
   }
   printf("Ket qua noi suy tai %.3f la: %f",x0,ketqua); 
 }
 
 int main(){
 	int n;
 	printf("Nhap so moc can noi suy:");
 	scanf("%d",&n);
 	float x[100],y[100];
 	printf("Nhap lan luot gia tri x:");
 	Nhapmang(n,x);
 	printf("Nhap lan luot gia tri y:");
 	Nhapmang(n,y);
 	float x0;
 	printf("Nhap gia tri can noi suy:");
	scanf("%f",&x0); 
 	noisuyNewton(n,x0,x,y);
 }
