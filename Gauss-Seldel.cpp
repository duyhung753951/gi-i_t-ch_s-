//Giai gan dung hpt bang pp Gauss seidel 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gaussSeidel(double** A, double* b, double* x, int n, int iterations, double epsilon) {
    for (int k = 0; k < iterations; k++) {
        double max_error = 0.0;

        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            double x_new = (b[i] - sum) / A[i][i];
            double error = fabs(x_new - x[i]);
            if (error > max_error) {
                max_error = error;
            }
            x[i] = x_new;
        }

        printf("Lan lap %d: ", k + 1);
        for (int i = 0; i < n; i++) {
            printf("x%d = %f ", i + 1, x[i]);
        }
        printf("\n");

        if (max_error < epsilon) {
            printf("Thuat toan dung lai o lan lap %d do sai so nho hon epsilon.\n", k + 1);
            break;
        }
    }
}

/* 
dong dau la n
cac dong tiep theo la ma tran A
cuoi cung la vector B
*/


int main() {
    FILE *f;
    f = fopen("input.txt", "rt");
    int n, iterations;
    double epsilon=0.0000001;
    // Nhap kich thuoc cua ma tran 
    printf("Nhap kich thuoc cua ma tran (n): ");
    fscanf(f, "%d", &n);

    // Cap phat bo nho dong cho A,b,x
    double** A = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
    }
    double* b = (double*)malloc(n * sizeof(double));
    double* x = (double*)malloc(n * sizeof(double));

    // Nhap ma tran A
    printf("Nhap vao ma tran A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%lf", &A[i][j]);
        }
    }

    printf("Ma tran vua nhap la: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }

    // Nhap vector b
    printf("Nhap vector b:\n");
    for (int i = 0; i < n; i++) {
        fscanf(f, "%lf\n", &b[i]);
    }

    printf("Vector vua nhap la: \n");
    for (int i = 0; i < n; i++) {
        printf("%lf\n", b[i]);
    }

    // Nhap gia tri khoi tao ban dau
    printf("Nhap gia tri khoi tao ban dau cua x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    // Nhap so lan lap
    printf("Nhap so lan lap: ");
    scanf("%d", &iterations);
    
    printf("Gia tri ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f ", i + 1, x[i]);
    }
    printf("\n");

    gaussSeidel(A, b, x, n, iterations, epsilon);

    // Giai phong bo nho
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
    fclose(f);
    return 0;
}

