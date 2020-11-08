#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int N, K;
    cin >> N >> K;
    ll res = 1;

    for (int A_B = 2; A_B <= 199998; ++A_B){
        int C_D = A_B - K;
        if (2 <= C_D && C_D <= 199998) {
            
        }
    }

    cout << res << endl;
	return 0;
}