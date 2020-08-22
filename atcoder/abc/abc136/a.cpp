#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A < B + C ? B + C - A : 0) << endl;
}