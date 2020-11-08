#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

// 約数の列挙
// O(n^(1/2))
vector<ll> divisor(ll n){
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i){
        if (n % i == 0){
            res.push_back(i);
            if (i != n/i) res.push_back(n/i);
        }
    }
    return res;
}

int main(){
    ll N;
    cin >> N;

    auto v = divisor(N);
    sort(v.begin(), v.end());
    for (auto i : v){
        cout << i << endl;
    }
    return 0;
}