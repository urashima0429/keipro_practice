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
	int N, M, K;
	cin >> N >> M >> K;

    long long ans = 0;
    int dmax = N + M - 2;
    for (int d = 1; d <= dmax; ++d){
        long long tmp = 0;
        for (int j = 0; j <= d; ++j){
            tmp += ( j==0||j==d ? 1 : 2) * max(0, (N-j) * (M-(d-j)));
        }
        ans += tmp * d % mod;
    }

    cout << ans * modcomb(N * M -2, K - 2) % mod << endl;
}