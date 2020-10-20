#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 2e18;
int R, C, K;
ll V[3010][3010], dp[3010][3010][4];

ll dfs(int r, int c, int s){
    if (dp[r][c][s] != -INF) return dp[r][c][s];

    ll res = 0;
    if (r > 0){
        if (s == 0){
            res = max(res, dfs(r-1, c, 0));
            res = max(res, dfs(r-1, c, 1));
            res = max(res, dfs(r-1, c, 2));
            res = max(res, dfs(r-1, c, 3));
        }
        if (s == 1){
            res = max(res, dfs(r-1, c, 0) + V[r][c]);
            res = max(res, dfs(r-1, c, 1) + V[r][c]);
            res = max(res, dfs(r-1, c, 2) + V[r][c]);
            res = max(res, dfs(r-1, c, 3) + V[r][c]);

        }
    }
    if (c > 0){
        res = max(res, dfs(r, c-1, s));
        if (s > 0){
            res = max(res, dfs(r, c-1, s-1) + V[r][c]);    
        }
    }

    return dp[r][c][s] = res;
}

int main() {
	cin >> R >> C >> K;
    for (int r = 0; r < R; ++r){
        for (int c = 0; c < C; ++c){
            dp[r][c][0] = -INF;
            dp[r][c][1] = -INF;
            dp[r][c][2] = -INF;
            dp[r][c][3] = -INF;
        }
    }
    for (int i = 0; i <= R; ++i){
        for (int j = 0; j <= C; ++j){
            V[i][j] = 0;
        }
    }
    for (int i = 0; i < K; ++i){
        int r, c, v;
        cin >> r >> c >> v;
        V[r-1][c-1] = v;
    }

    dp[0][0][0] = 0;
    dp[0][0][1] = V[0][0];
    ll res = -INF;
    res = max(res, dfs(R-1, C-1, 0));
    res = max(res, dfs(R-1, C-1, 1));
    res = max(res, dfs(R-1, C-1, 2));
    res = max(res, dfs(R-1, C-1, 3));
    cout << res << endl;     
	return 0;
}