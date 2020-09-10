#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<ll, ll> prime_factorize(ll n){
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; ++i){
        while(n % i == 0){
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

int main(){
    ll N;
    cin >> N;
    auto m = prime_factorize(N);

    ll res = 0;
    for (auto i : m){
        ll p = i.first;
        ll q = i.second;

        int n = 1;
        while (n*(n+1)/2 <= q){
            n++;
        }
        res += --n;
    }
    cout << res << endl;
    return 0;
}