#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int N, mxm = 0;
    ll res = 0;
    cin >> N >> mxm;
    for (int i = 1; i < N; ++i){
        int a;
        cin >> a;
        if (mxm > a){
            res += mxm - a;
        } else {
            mxm = a;
        }
    }

    cout << res << endl;
	return 0;
}