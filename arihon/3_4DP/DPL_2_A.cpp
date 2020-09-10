#include <iostream>
using namespace std;

const int MAX_V = 15;
const int INF = 1e9;
int V, E, D[MAX_V][MAX_V], dp[1 << MAX_V][MAX_V];

int rec(int S, int v, int T){
    if (dp[S][v] >= 0) return dp[S][v];
    if (S == (1 << V) - 1 && v == T) return dp[S][v] = 0;
    
    int res = INF;
    for (int u = 0; u < V; ++u){
        if (!(S >> u & 1)) res = min(res, rec(S | 1 << u, u, T) + D[v][u]);
    }
    return dp[S][v] = res;
}

int main(){
    cin >> V >> E;
    for (int i = 0; i < V; ++i){
        for (int j = 0; j < V; ++j){
            D[i][j] = INF;
        }
    }

    for (int i = 0; i < E; ++i){
        int v, u, c;
        cin >> v >> u >> c;
        D[v][u] = c;
    }
    

    
    int ans = INF;
    for (int i = 0; i < V; ++i){
        for (int i = 0; i < (1 << V); ++i){
            for (int j = 0; j < V; ++j){
                dp[i][j] = -1;
            }
        }
        ans = min(ans, rec(0, i, i));
    }
    if (ans >= INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;    
    }
}
