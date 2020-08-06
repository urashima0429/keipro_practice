#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


// WA
int main() {
    int N, K, MOD = 1e9+7;
    vector<int> pos, neg;
	cin >> N >> K;
    for (int i = 0; i < N; ++i){
        int t;
        cin >> t;
        if (t < 0) {
            neg.push_back(-t);
        } else {
            pos.push_back(t);
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    if (pos.size() == 0){

        int prod = 1;
        for (int i = 0; i < K; ++i){
            prod *= -neg[i];
            prod %= MOD;
        }
        cout << prod + MOD << endl;

    } else {
        int prod = 1,pos_i = pos.size()-1, neg_i = neg.size()-1;
        while (K > 0){
            
            if (K >= 2){
                if (pos[pos_i-1]*pos[pos_i] > neg[neg_i-1]*neg[neg_i]){

                } else {

                }
            }else if (K == 1){
                
            }
        }
    }

	return 0;
}