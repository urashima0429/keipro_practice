#include <iostream>
using namespace std;

const int mod  = 1e9 + 7;
long long modpow(long long a, long long n) {
    long long r = 1;
    while(n > 0) {
        r = r * ( (n%2) ? a : 1) % mod;
        a = a * a % mod;
        n /= 2;
    }
    return r;
}

int main(){
    long long n, m;
    cin >> n >> m;
    cout << modpow(n, m) << endl;
}