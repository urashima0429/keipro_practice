#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    string X;
    ll M;
    cin >> X >> M;

    int b = 0;
    for (int i = 0; i < X.length(); ++i){
        b = max(b, X[i]-48);
    }

    ll l = b+1, m, r = 1e9;
    for (int i = 0; i < 100; ++i){
        m = (l + r) / 2;

        bool OK = true;
        ll t = 0, x = 1;
        for (int j = X.length()-1; j >= 0; --j){
            t += x * (ll)(X[j]-48);
            x *= m;
            if (t > M || x > 1e18) {
                OK = false;
                break;
            }
        }
        cout << t << ":" << x << ":" << m << endl;
        if (OK){
            l = m;
        } else {
            r = m;
        }
    }
    cout << m - b << endl;
}
