#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int N;
    bool is_overflow = false;
    bool is_zero = false;
    ll res = 1, max = 1e18;
    cin >> N;
    for (int i = 0; i < N; ++i){
        ll a;
        cin >> a;
        if (a == 0) {
            is_zero = true;
            break;
        }
        if ( (double)a > (double)max / (double)res ) {
            is_overflow = true;
        }
        res *= a;
        if (res > max) {
            is_overflow = true;
        }
    }

    if (is_zero){
        cout << 0 << endl;
    } else if (is_overflow){
        cout << -1 << endl;
    } else{
        cout << res << endl;    
    }
	return 0;
}