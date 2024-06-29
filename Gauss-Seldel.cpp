/* Giai he phuong trinh (Bang phuong phap Gauss_Seidel):
   10x + 2y + z = 10
   x + 10y + 2z = 12
   x + y +10z = 8 
voi x0=(0,0,0)
*/
#include<stdio.h>
#include<math.h>

#define f1(x,y,z) (10-2*y-z)/10 // x
#define f2(x,y,z) (12-2*z-x)/10 // y
#define f3(x,y,z) (8-x-y)/10 // z

int main(){
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, err;
    int count = 0;
    printf("Nhap sai so mong muon: ");
    scanf("%f", &err);
    do{
        x1=f1(x0,y0,z0);
        y1=f2(x1,y0,z0);
        z1=f3(x0,y1,z0);

        e1=fabs(x1-x0);
        e2=fabs(y1-y0);
        e3=fabs(z1-z0);
        count+=1;
        printf("Lan lap thu %d: x=%f\ty=%f\tz=%f\n", count, x1, y1, z1);
        x0=x1;
        y0=y1;
        z0=z1;
    }while(e1 > err || e2 > err || e3 > err);
}
