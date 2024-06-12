#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int n, i, k;
    float xn;
    printf("Nhap xn: ");
    scanf("%f", &xn);
    printf("Nhap n: ");
    scanf("%d",&n);
    float a[n], b[n];
    long long D, P;
    printf("Nhap bang: ");
    for(i = 0; i <= n; i++){
        scanf("%f%f", &a[i], &b[i]);
    }
    for(k = 0; k<=n; k++){
        D=1;
        for(i = 1; i<=n; i++){
            if(i != k){
                D = D * ((xn - a[i])/(a[k] - a[i]));
            }
        }
        P = P + b[k] * D;
    }
    printf("P = %llf", P);
}
