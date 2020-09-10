#include <iostream>
using namespace std;

int extgcd(int a, int b, int& x, int& y){
    int d = a;
    if (b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int main(){
    int a, b;
    cin >> a >> b;

    int x, y;
    int g = extgcd(a, b, x, y);
    cout << x << " " << y << endl; 
    return 0;
}