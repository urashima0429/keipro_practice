#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll mod_pow(ll a, ll n) {
    ll r = 1;
    while(n > 0) {
        r = r * ( (n%2) ? a : 1) % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return r;
}

ll mod_comb(ll n, ll k) {
    if ( n < 0 || k < 0 || k > n) return 0;
    k = min(k, n - k); //nCk = nC(n-k)
    ll p = 1, q = 1;
    while ( k > 0 ) {
        p = p * n-- % MOD; // p = n*(n-1)*(n-2)...(n-k+1)
        q = q * k-- % MOD; // q = k*(k-1)*(k-2)...1
    }
    // 1/q = q^(p-2) (MOD p)
    return p * mod_pow(q, MOD - 2) % MOD;
}
ll mod_perm(ll n, ll m){
    if (n < m) return 0;
    if (n <= 1 || m <= 0) return 1;
    return n * mod_perm(n-1, m-1) % MOD;
}

int main() {
    ll N, M;
    cin >> N >> M;

    ll sum = 0;
    if (N - 2 * M + 1 > 0){
        sum += (N - 2 * M + 1) * mod_perm(M - N, N) % MOD;
    }

	return 0;
}