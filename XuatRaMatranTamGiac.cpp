#include<stdio.h>

FILE *f;
int n, m;
float a[50][50], b[50];

void input(FILE *f);
void biendoi();
void output();

int main(){
    f = fopen("input.txt", "rt");
    input(f);
    biendoi();
    output();
}

void input(FILE *f){
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(f, "%f", &a[i][j]);
        }
    }
    fscanf(f, "%d", &m);
    for(int i = 0; i < m; i++){
        fscanf(f, "%f", &b[i]);
    }
}

void biendoi(){
    for(int k = 0; k < n-1; k++){
        for(int i = k+1; i < n; i ++){
            float x = a[i][k] / a[k][k];
            for(int j = k; j < n; j++){
                a[i][j] -= ((x) * a[k][j]);
            }
            b[i] -= (x * b[k]);
        }
    }
}

void output(){
    printf("Ma tran tam giac: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("| %.2f ", a[i][j]);
        }
        printf("| %.2f |", b[i]);
        printf("\n");
    }
    
}