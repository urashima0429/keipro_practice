#include <iostream>
using namespace std;

// WA

int main() {
	const int MAX_N = 400;
    const int MAX_M = 400;
	const int MAX_W = 400;
    int N, M;
    int s[MAX_N], l[MAX_N], p[MAX_N];
    int W[MAX_M], ans[MAX_M];
    int dp[MAX_N][MAX_W];

    cin >> N;
    for (int i = 1; i <= N; ++i){
    	cin >> s[i] >> l[i] >> p[i];
    }
    cin >> M;
    for (int i = 0; i < M; ++i){
        cin >> W[i];
    }

    for (int k = 0; k < M; ++k){
        
        for (int i = 0; i <= N; ++i){
            for (int j = 0; j <= W[k]; ++j){
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= N; ++i){
            for (int j = 0; j <= W[k]; ++j){
                int m = dp[i-1][j];
                for (int n = max(0 , j - l[i]); n <= j - s[i]; ++n){
                    m = max(m, dp[i][n] + p[i]);
                }
                dp[i][j] = m;
            }
        }

        for (int i = 0; i <= N; ++i){
            for (int j = 0; j <= W[k]; ++j){
                cout << dp[i][j] << " ";
            } cout << endl;
        }

        ans[k] = dp[N][W[k]];
    }


    bool can = true;
    for (int i = 0; i < M; ++i){
        if (ans[i] == 0) can = false;
    }
    if(can){
        for (int i = 0; i < M; ++i){
            cout << ans[i] << endl;
        }
    }else{
        cout << -1 << endl;
    }
}