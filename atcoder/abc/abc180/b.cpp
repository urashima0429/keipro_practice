#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll N, x, a = 0, b = 0, c = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> x;
        a += x > 0 ? x : -x;
        b += x*x;
        c = max(c, x > 0 ? x : -x);
    }

    cout << setprecision(17); 
    cout << a << endl;
    cout << sqrt(b) << endl;
    cout << c << endl;
	return 0;
}