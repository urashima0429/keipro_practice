#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll N;
    cin >> N;

    ll _3_A = 1;
    for (int A = 1; _3_A * 3 <= N; ++A){
        _3_A *= 3;
        
        ll _5_B = 1;
        for (int B = 1; _3_A + _5_B * 5 <= N; ++B){
            _5_B *= 5;

            if(_3_A + _5_B == N) {
                cout << A << " " << B << endl;
                return 0;
            } 
        }
    }

    cout << -1 << endl;
	return 0;
}