#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int N;
    map<pair<ll, ll>, int> m;
    cin >> N;
    for (int i = 0; i < N; ++i){
        ll a, b;
        cin >> a >> b;
        if (b < 0) {
            a = -a;
            b = -b;
        }
        ll g = gcd(a, b);

        m[make_pair(a/g, b/g)]++;
    }

    
    return 0;
}