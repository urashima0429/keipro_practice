#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N_MAX = 100010;
int N, M, dp[N_MAX];
vector<int> E[N_MAX];

int dfs(int i){
    if (dp[i] != -1) return dp[i]; 

    int res = 0;
    for (int j = 0; j < E[i].size(); ++j){
        res = max(res, dfs(E[i][j]) + 1);
    }
    return dp[i] = res;
}

int main() {
	cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        dp[i] = -1;
    }
    for (int j = 0; j < M; ++j){
        int x, y;
        cin >> x >> y;
        E[y].push_back(x);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i){
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
	return 0;
}