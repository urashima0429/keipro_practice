#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    const ll INF = 1e18;
    const int MAX_N = 40;
    int N, W;
    vector<ll> v, w;
    pair<ll, ll> wv[1 << (MAX_N / 2)];
    cin >> N >> W;
    for (int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        w.push_back(b);
    }

    int n_2 = N / 2;
    for (int i = 0; i < 1 << n_2; ++i){
        ll sw = 0, sv = 0;
        for (int j = 0; j < n_2; ++j){
            if(i >> j & 1){
                sw += w[j];
                sv += v[j];
            }
        }
        wv[i] = make_pair(sw, sv);
    }
    sort(wv, wv + (1 << n_2));

    int m = 1;
    for (int i = 1; i < 1 << (n_2); ++i){
        if(wv[m-1].second < wv[i].second){
            wv[m++] = wv[i];
        }
    }

    ll ans = 0;
    for (int i = 0; i < 1 << (N - n_2); ++i){
        ll sw = 0, sv = 0;
        for (int j = 0; j < (N - n_2); ++j){
            if(i >> j & 1){
                sw += w[n_2 + j];
                sv += v[n_2 + j];
            }
        }
        if (sw <= W){
            ll tv = (lower_bound(wv, wv+m, make_pair(W-sw, INF)) - 1)->second;
            ans = max(ans, sv + tv);
        }
    }

    cout << ans << endl;
    return 0;
}