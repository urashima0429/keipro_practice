#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A * C < B ? C : B / A) << endl;
}