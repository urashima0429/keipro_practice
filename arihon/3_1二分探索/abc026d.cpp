#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

const double pi = 3.141592653589793;
double A, B, C;

double f(double x){
    return A*x + B*sin(C*pi*x);
}

int main(){
    cin >> A >> B >> C;
    double l = 0.0, m, r = 1000.0; 
    for (int i = 0; i < 1000; ++i){
        m = (l + r) / 2;
        if (f(m) > 100.0){
            r = m;
        }else{
            l = m;
        }
    }
    cout << setprecision(15) << l << endl;
}