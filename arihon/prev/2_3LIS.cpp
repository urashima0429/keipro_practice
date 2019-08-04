#include <iostream>
using namespace std;

// DP 最長増加部分列 O(NlogN)

const int MAX_N = 1e3, INF = 1e9;
int N, a[MAX_N + 1], dp[MAX_N + 1];

int main(){

    // input
    cin >> N ;
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        dp[i] = INF;
    }

    for (int i = 0; i < N; ++i){
        *lower_bound(dp, dp + N, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp + N, INF) - dp << endl;
    
}