#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll N, res = 0;
    cin >> N;

    for (ll i = 1; i < N; ++i){
        res += (N / i) + (N % i ? 0 : -1);
    }
    cout << res << endl;
	return 0;
}