#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
typedef long long ll;


int main(){
    double a, b, x;
    double PI=3.14159265358979323846;
    cin >> a >> b >> x;

    double tanX;
    if (a*a*b <= 2*x) {
        tanX = 2.0*(a*a*b-x) / (a*a*a);
    }else{
        tanX = (a*b*b) / (2.0*x);
    }
    cout << fixed << setprecision(10);
    cout << atan(tanX) * 180.0 / PI << endl;
    return 0;
}