//Giai gan dung hpt bang pp lap jacoby 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ham de tinh chuan cua su khac biet giua hai mang
double calculate_error(double x1[], double x0[], int n) {
    double error = 0.0;
    for (int i = 0; i < n; i++) {
        error += pow(x1[i] - x0[i], 2);
    }
    return sqrt(error);
}

// Ham in mang
void print_array(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Ham trien khai phuong phap lap Jacobi
void jacobi_method(double **a, double *b, double *x0, double epsilon, int n) {
    double *x1 = (double*) malloc(n * sizeof(double));
    double err;
    int x;
	printf("So lan can lap la:");
	scanf("%d",&x);
    // So lan lap toi da dam bao chuong trinh khong chay vo han
    int max_iterations = x;
    int iterations = 0;

    do {
        // Tinh toan uoc luong moi x^(1)
        for (int i = 0; i < n; i++) {
            x1[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    x1[i] -= a[i][j] * x0[j];
                }
            }
            x1[i] /= a[i][i];
        }

        // Tinh sai so err = ||x^(1) - x^(0)||
        err = calculate_error(x1, x0, n);

        // Cap nhat uoc luong x^(0) = x^(1)
        for (int i = 0; i < n; i++) {
            x0[i] = x1[i];
        }

        // In mang x^(1) hien tai
        printf("Lap lan %d: ", iterations + 1);
        printf("sai so hien tai: %lf\n", err);
        print_array(x1, n);

        iterations++;
    } while (iterations < max_iterations);
    free(x1);
}

/* 
dong dau la n
cac dong tiep theo la ma tran A
cuoi cung la vector B
*/


int main() {
    FILE *f;
    f = fopen("input.txt", "rt");
    int n;
    double epsilon = 0.03; // Do chinh xac mong muon

    // Nhap kich thuoc cua he phuong trinh
    fscanf(f, "%d", &n);

    // Khai bao ma tran a v� c�c mang b, x0
    double **a = (double**) malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        a[i] = (double*) malloc(n * sizeof(double));
    }

    double *b = (double*) malloc(n * sizeof(double));
    double *x0 = (double*) malloc(n * sizeof(double));

    // Nhap ma tran a
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%lf", &a[i][j]);
        }
    }

    printf("Ma tran vua nhap la: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }

    // Nhap mang b
    for (int i = 0; i < n; i++) {
        fscanf(f, "%lf", &b[i]);
    }
    printf("Mang B vua nhap la: \n");
    for (int i = 0; i < n; i++) {
        printf("%lf\n", b[i]);
    }

    // Nhap gia tri khoi tao ban dau x^(0)
    printf("Nhap gia tri khoi tao x0 (%d phan tu):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x0[i]);
    }

    // Goi ham jacobi_method
    jacobi_method(a, b, x0, epsilon, n);

    // Giai phong bo nho duoc cap phat
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(b);
    free(x0);

    return 0;
}

