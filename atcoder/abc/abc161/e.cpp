#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N;
    ll up[200010], down[200010], res = 0;
    
    cin >> N;
    for (int i = 1; i < N; ++i){
        up[i] = 0;
        down[i] = 0;
    }
    for (int i = 0; i < N; ++i){
        ll a;
        cin >> a;
        if (i+a < N) up[i+a]++;
        if (i-a > 0) down[i-a]++;
    }

    for (int i = 1; i < N; ++i){
        res += up[i] * down[i];
    }
    
    cout << res << endl;
    return 0;
}