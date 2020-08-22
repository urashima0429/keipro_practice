#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    bool over = false;
    int N;
    ll res = 1LL, t;
	
	cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> t;
        res *= t;
        if (res > 1000000000000000000) over = true;
    }
    if (res != 0 && over) {
        cout << -1 << endl;
    } else {
        cout << res << endl; 
    }
	return 0;
}