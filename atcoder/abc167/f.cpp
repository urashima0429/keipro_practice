#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int pow(int a, int n){
    int res = 1;
    for (int i = 0; i < n; ++i) res *= a;
    return res;
}

int main(){
	int N;
    cin >> N;
    vector<int> S, u;
    for (int i = 0; i < pow(2, N); ++i){
        int s;
        cin >> s;
        S.push_back(s);
    }
    sort(S.begin(), S.end());

    int itr = pow(2, N)-1;
    u.push_back(S[itr--]);
    for (int i = 0; i < N; ++i){
        int l = u.size();
        for (int j = 0; j < l; ++j){
            if (S[itr] < u[j]){
                u.push_back(S[itr--]);
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}