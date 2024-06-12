#include<iostream>
using namespace std;
//x²-m=0 find x
float fx(float x, float m){
    return x*x-m;
}

float find_sqrt_m(float m);
int main()
{
    float m;
    cout << "Nhap so muon tim can bac 2: ";
    cin >> m;
    cout << "Ket qua : " << find_sqrt_m(m);
    return 0;
}

float find_sqrt_m(float m){   
    float a, b, e, x0;
    a = 1;
    b = 2;
    e = 0.000001;
    while((b-a)>=e){
        x0=(a+b)/2;
        if(fx(a, m)*fx(x0, m) > 0){
            a = x0;
        }else{
            b = x0;
        }
    }
    return x0;
}