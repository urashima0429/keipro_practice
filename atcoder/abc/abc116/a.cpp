#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int s = (a + b + c) / 2;
    cout << pow(s*(s-a)*(s-b)*(s-c), 0.5) << endl;
}
