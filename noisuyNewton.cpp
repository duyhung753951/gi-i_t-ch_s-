#include<iostream>
#include<math.h>
using namespace std;

float f(float x){
    return x*x*x - 3*x +1;
}

float df(float x){
    return 3*x*x -3;
}

int main()
{
    //x0 = 0, sai so = 0.00001
    //m la min cua f'(x)
    float f0, g0, x1, x0, saiso, err, m;
    cout << "Nhap x0 = ";
    cin >> x0;
    cout << "Nhap sai so = ";
    cin >> saiso;
    int i = 1;
    do{
        f0=f(x0);
        g0=df(x0);
        x1 = x0 - f0/g0;
        err = abs(f(x1))/m;
        cout << "Vong lap thu " << i << ": x1 = " << x1 << endl;
        x0 = x1;
        i++;
    }while(err >= saiso);
    cout << "Nghiem gan dung la : " << x1;
    return 0;
}