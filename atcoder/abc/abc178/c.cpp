#include <iostream>
using namespace std;
typedef long long ll;

const ll mod  = 1e9 + 7;
ll modpow(ll a, ll n) {
    ll r = 1;
    while(n > 0) {
        r = r * ( (n%2) ? a : 1) % mod;
        a = a * a % mod;
        n /= 2;
    }
    return r;
}

ll modcomb(int n, int k) {
    if ( n < 0 || k < 0 || k > n) return 0;
    k = min(k, n - k); //nCk = nC(n-k)
    ll p = 1, q = 1;
    while ( k > 0 ) {
        p = p * n-- % mod; // p = n*(n-1)*(n-2)...(n-k+1)
        q = q * k-- % mod; // q = k*(k-1)*(k-2)...1
    }
    // 1/q = q^(p-2) (mod p)
    return p * modpow(q, mod - 2) % mod;
}


int main() {
	int N;
    ll res = 0;
    cin >> N;

    res = (res + modpow(10, N)) % mod;
    res = (res - modpow(9, N)) % mod;
    res = (res - modpow(9, N)) % mod;
    res = (res + modpow(8, N)) % mod;
    res = (res + mod) % mod;

    cout << res << endl;
	return 0;
}