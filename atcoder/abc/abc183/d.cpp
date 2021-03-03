#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    ll N, W, P[200010], M[200010];
    for (int i = 0; i < 200010; ++i) {
        P[i] = 0;
        M[i] = 0;
    }
    cin >> N >> W;
    for (int i = 0; i < N; ++i){
        ll s, t, p;
        cin >> s >> t >> p;
        P[s] += p;
        M[t] += p;
    }

    ll res = 0;
    bool check = true;
    for (int i = 0; i < 200010; ++i){
        res += P[i];
        res -= M[i];
        if (res > W) check = false;
    }
    if (check){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
