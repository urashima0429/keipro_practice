#include <iostream>
using namespace std;

int main() {
    int r, D, X;
    cin >> r >> D >> X;
    for (int i = 1; i <= 10; ++i){
        X = r * X - D;
        cout << X << endl;
    }
    return 0;
}