#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll A;
    double B;
    cin >> A >> B;
    ll res = A * (ll)floor(B * 100 + 0.001) / 100;
    cout << res << endl;
}