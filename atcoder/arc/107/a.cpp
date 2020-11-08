#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll MOD = 998244353;
	ll A, B, C, res = 1;
    cin >> A >> B >> C;
    if (A % 2 == 0){
        res = (res * (A/2) % MOD) * (A+1) % MOD;
    }else{
        res = (res * A % MOD) * ((A+1)/2) % MOD;
    }
        if (B % 2 == 0){
        res = (res * (B/2) % MOD) * (B+1) % MOD;
    }else{
        res = (res * B % MOD) * ((B+1)/2) % MOD;
    }
    if (C % 2 == 0){
        res = (res * (C/2) % MOD) * (C+1) % MOD;
    }else{
        res = (res * C % MOD) * ((C+1)/2) % MOD;
    }
    cout << res << endl;
	return 0;
}