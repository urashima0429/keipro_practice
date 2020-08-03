#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

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
    int N;
    cin >> N;
    vector<ll> A, B;
    for (int i = 0; i < N; ++i){
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    int M = 0;
    for (int i = 0; i < N; ++i){
        for (int j = i+1; j < N; ++j){
            if (A[i]*A[j] + B[i]*B[j] == 0){
                M++; 
                cout << i << ":" << j << endl;  
            }
        }
    }
    cout << M << endl;

    ll ans = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 0; j <= i/2; ++j){
            ans = (ans + (j%2==0?1:-1) * modcomb(M, j) * modcomb(N-2*j, i-2*j)) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}