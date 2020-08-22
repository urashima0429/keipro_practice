#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll N, D, res = 0, x, y;
	cin >> N >> D;
    for (int i = 0; i < N; ++i){
        cin >> x >> y;
        if (x*x + y*y <= D*D) res++;
    }
    cout << res << endl; 
	return 0;
}