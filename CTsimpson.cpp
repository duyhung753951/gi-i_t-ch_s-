#include<stdio.h>

float fx(float x)
{
    return 1/(1+x);
}

int main()
{
    int n;
    float a, b;
    printf("Nhap a, b, n: ");
    scanf("%f%f%d", &a, &b, &n);
    float h = (b - a)/(float)n, S = fx(a) + fx(b), x = 0;
    for(int i = 1; i < n; i++){
        x = a + i*h;
        S += 2 * fx(x);
        if(i%2!=0) S+=4*f(x);
 		else S+=2*f(x);
    }
    S = (h/3)*S;
    printf("Ket qua = %f", S);
}
