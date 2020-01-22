#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll N, K;
    vector<int> A, F;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
    	int a;
    	cin >> a;
    	A.push_back(a);
    }
    for (int i = 0; i < N; ++i) {
    	int f;
    	cin >> f;
    	F.push_back(-f);
    }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());


    ll l = -1, r = 1e18 + 10; 
    while(l + 1 < r){
        ll m = (l + r) / 2;

        ll check = K;
        for (int i = 0; i < N; ++i){
		    ll a = A[i];
	    	ll f = -F[i];
	    	ll tmp = (a * f - m) / f + ((a * f - m) % f > 0 ? 1 : 0);
	    	check -= tmp;
        }
        if (check >= 0){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}