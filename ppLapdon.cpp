#include<iostream>
#include<math.h>
using namespace std;

float gx(float x){
    return 0.5*sqrt(10-x*x*x);
}

// k la max cua g'(x)

int main()
{
    float x0, x1, err, k, e;
    cin >> x0 >> k >> e;
    while(true){
        x1 = gx(x0);
        err = abs(x1-x0);
        x0 = x1;
        cout << x1 << endl;
        if(err < e*(1-k)/k) break;
    }
    cout << x1;
    return 0;
}