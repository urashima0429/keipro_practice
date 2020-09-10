#include <iostream>
using namespace std;

// WA

int main() {
    const int MAX_N = 100 + 10;
    const int MAX_W = 10000 + 10;
    int N, W, v[MAX_N], w[MAX_N], m[MAX_N], dp[MAX_N][MAX_W];
    cin >> N >> W;
    for (int i = 1; i <= N; ++i){
        cin >> v[i] >> w[i] >> m[i];
    }

    dp[0][0] = 0;
    for (int j = 1; j <= W; ++j){
        dp[0][j] = -1;
    }

    for (int i = 1; i <= N; ++i){
        for (int j = 0; j <= W; ++j){
            if (dp[i-1][j] >= 0) dp[i][j] = m[i];
            else if (j - w[i] >= 0 && dp[i][j-w[i]] > 0) dp[i][j] = dp[i][j-w[i]] - 1;
            else dp[i][j] = -1;
        }
    }

    int ans = 0;
    for (int k = 0; k <= W; ++k){
        int i = N;
        int j = k;
        int sum = 0;
        while (i >= 0){
            while ()
        }

        ans = max(ans, sum);
    }

    cout << dp[N][W] << endl;


}