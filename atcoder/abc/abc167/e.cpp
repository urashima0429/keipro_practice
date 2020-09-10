#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
long long modpow(long long a, long long n) {
    long long r = 1;
    while(n > 0) {
        r = r * ( (n%2) ? a : 1) % mod;
        a = a * a % mod;
        n /= 2;
    }
    return r;
}

long long modcomb(int n, int k) {
    if ( n < 0 || k < 0 || k > n) return 0;
    k = min(k, n - k); //nCk = nC(n-k)
    long long p = 1, q = 1;
    while ( k > 0 ) {
        p = p * n-- % mod; // p = n*(n-1)*(n-2)...(n-k+1)
        q = q * k-- % mod; // q = k*(k-1)*(k-2)...1
    }
    // 1/q = q^(p-2) (mod p)
    return p * modpow(q, mod - 2) % mod;
}


int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    long long 
    ll res = 0;
    for (ll k = 0; k <= K; ++k){
        ll a = 1;        
        a = (a * M) % mod;
        a = (a * modpow(M-1, N-k-1)) % mod;
        a = (a * modcomb(N-1, k) ) % mod;

        res = (res + a) % mod;
    }

    cout << res << endl;
    return 0;
}