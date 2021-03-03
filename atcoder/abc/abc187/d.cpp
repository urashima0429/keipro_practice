#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N, res = 0;
    ll aoki_sum = 0, takahashi_sum = 0;
    vector<tuple<ll,ll,ll>> t;
    cin >> N;
    for (int i = 0; i < N; ++i){
        ll a,b;
        cin >> a >> b;
        aoki_sum += a;
        t.push_back( make_tuple(2*a+b, a, b) );
    }

    sort(t.begin(), t.end());

    for (int i = N-1; i >= 0; --i){
        ll a = get<1>(t[i]);
        ll b = get<2>(t[i]);

        aoki_sum -= a;
        takahashi_sum += a + b;
        res++;
        // cout << aoki_sum << ":" << takahashi_sum << ":" << res << endl;

        if (takahashi_sum > aoki_sum) {
            break;
        }
    }

    cout << res << endl;
    return 0;
}
