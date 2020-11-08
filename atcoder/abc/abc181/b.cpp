#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int N;
    ll res = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        ll a, b;
        cin >> a >> b;
        res += (b*(b+1) - a*(a-1)) / 2;
    }
    cout << res << endl;
	return 0;
}