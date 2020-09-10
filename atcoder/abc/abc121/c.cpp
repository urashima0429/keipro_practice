#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N, M;
    vector<pair<int, int>> v;
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    
    ll j = M, ans = 0;
    for (int i = 0; i < N; ++i){
        ll a = v[i].first;
        ll b = v[i].second;
        if (j >= b) {
            j -= b;
            ans += a * b;
        }else{
            ans += a * j;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

