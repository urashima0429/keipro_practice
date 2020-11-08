#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MAX = 200010;
long long fac[MAX], finv[MAX], inv[MAX];

void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll mod_pow(ll a, ll n) {
    ll r = 1;
    while(n > 0) {
        r = r * ( (n%2) ? a : 1) % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return r;
}

ll mod_comb(int n, int k){
    if (n < 0 || k < 0 || n < k) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll mod_perm(ll n, ll k){
    if (n < 0 || k < 0 || n < k) return 0;
    return fac[n] * finv[n-k] % MOD;
}

int main(){
    init();
    ll N, M, K, res = 0;
    cin >> N >> M >> K;

    for (int i = 0; i <= K; ++i){
        ll t = M;
        t = t * mod_comb(N-1, i) % MOD;
        t = t * mod_pow(M-1, N-1-i) % MOD;

        res = (res + t) % MOD;
    }

    cout << (res + MOD) % MOD << endl;
    return 0;
}