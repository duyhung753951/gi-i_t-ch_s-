#include<iostream>
#include<math.h>
using namespace std;

float f(float x){
    return x*x*x - x - 1;
}

int main()
{
    //a, b la khoang phan ly de` bai` cho
    //m la min cua f'(x)
    float a, b, x1, x0, saiso, err;
    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    int i = 1;
    do{
       x1 = (a*f(b)-b*f(a))/(f(b)-f(a));
	   if(f(x1)*f(a)>0)
	       a=x1;
	   else 
	       b=x1;
	   saiso=fabs(b-a);
       cout << "Vong lap thu " << i << ": x1 = " << x1 << endl;
       x0 = x1;
       i++;
    }while(saiso >= err);
    cout << "Nghiem gan dung la : " << x1;
    return 0;
}
