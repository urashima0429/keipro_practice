#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD  = 998244353;
const int MAX_N = 200010;
int N, K;
ll bit[MAX_N];

ll sum (int i){
    ll s = 0;
    while(i > 0){
        s = (s + bit[i]) % MOD;
        i -= i & -i;
    }
    return s;
}

void add (int i, ll x){
    while(i <= N){
        bit[i] = (bit[i] + x) % MOD;
        i += i & -i;
    }
}

int main(){
    int L[12], R[12];
    cin >> N >> K;
    for (int i = 0; i < K; ++i){
        cin >> L[i] >> R[i];
    }

    for (int i = 1; i < N; ++i){
        ll s = 0;
        for (int j = 0; j < K; ++j){
            s = ( s + sum( max(0, i-L[j]) )) % MOD;
            s = ( s - sum( max(0, i-R[j]-1))) % MOD;
            if (L[j] <= i && i <= R[j]) {
                s = (s + 1) % MOD;
            }
        }
        add(i, (s + MOD) % MOD);
    }

    ll ans = sum(N-1) - sum(N-2);
    ans = ans % MOD;
    ans = ans + MOD;
    ans = ans % MOD;
    cout << ans << endl;
}
