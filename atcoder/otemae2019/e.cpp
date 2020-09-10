#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    const int MAX_N = 5e3 + 10;
	int N, Q;
    vector<int> T, X;
	cin >> N >> Q;

    X.push_back(0);
    T.push_back(0);
    for (int i = 1; i <= N; ++i){
        int d;
        cin >> d;
        X.push_back(X[i-1] - d);
        T.push_back(-X[i-1] + d - i);
        cout << X[i] << ":" << T[i] << endl;
    }

    for (int i = 0; i < Q; ++i){
        int t, l, r;
        cin >> t >> l >> r;
        auto low = lower_bound(T.begin(), T.end(), t);
        int num = low - T.begin();
        cout << num << endl;

        int ans = 0;
        for (int j = 0; j < num; ++j){
            
        }
    }

}