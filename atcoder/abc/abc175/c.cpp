#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;

int main() {
	ll X, K, D;
	cin >> X >> K >> D;

    if (X / D >= K) {
        cout << X - K * D << endl;
    } else if ( X / D < -K) {
        cout << - (X + K * D) << endl;
    } else {
        if (K % 2 == 0){
            ll mod = X % (2*D);
            if (mod < 0) {
                cout << min(-mod, 2*D + mod) << endl; 
            } else {
                cout << min(mod, 2*D - mod) << endl; 
            }
        } else {
            ll mod = (X+D) % (2*D);
            if (mod < 0) {
                cout << min(-mod, 2*D + mod) << endl; 
            } else {
                cout << min(mod, 2*D - mod) << endl; 
            }
        }
    }

	return 0;
}