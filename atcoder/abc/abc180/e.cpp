#include <iostream> 
using namespace std;
typedef long long ll;

const int INF = 1e9;
int N, X[20], Y[20], Z[20];
int dp[20][1<<18];


int abs(int a, int b){
    return a > b ? a-b : b-a;
}
// cost from i to j
int cost(int i, int j){
    return abs(X[j], X[i]) + abs(Y[j], Y[i]) + max(0, Z[j] - Z[i]);
}

int dfs(int n, int s){
    if (dp[n][s] <= INF) return dp[n][s];

    int res = INF;
    for (int i = 0; i < N; ++i){
        if (i != n && s & 1 << i) {
            res = min(res, dfs(i, s - (1 << i)) + cost(i, n));
        }
    }
    return dp[n][s] = res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> X[i] >> Y[i] >> Z[i];
        for (int j = 0; j < 1<<N; ++j){
            dp[i][j] = INF + 10;
        }
    }

    dp[0][0] = 0;
    cout << dfs(0, (1<<N)-1) << endl;
    return 0;
}