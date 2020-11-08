#include <iostream>
using namespace std;
typedef long long ll;


int main(){
const int mod  = 1e9 + 7;

    ll N, K, res = 0;
    cin >> N >> K;

    for (ll i = K; i <= N+1; ++i){
        res = (res + (N * i) % mod - (i * (i - 1)) % mod + 1) % mod;
    }

    cout << res << endl;
    return 0;
}