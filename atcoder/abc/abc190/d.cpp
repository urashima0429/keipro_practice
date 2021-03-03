#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;

    int res = 0;
    for (ll i = 1; i*i <= 2 * N; ++i){
        if (2LL * N % i == 0){
            ll a = i, b = 2*N/i;
            if ( (2LL*N - a*a) % a == 0 && ((2LL*N - a*a) / a) & 1) {
                // cout << "a:" << a << " " << (2LL*N - a*a) / a << endl;
                res++;
            }
            if ( (2LL*N - b*b) % b == 0 && ((2LL*N - b*b) / b) & 1) {
                // cout << "b:" << b << " " << (2LL*N - b*b) / b << endl;
                res++;
            }
        }
    }

    cout << res << endl;
}
