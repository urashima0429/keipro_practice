#include <iostream>
using namespace std;

// prim
int main(){
    const int INF = 1e9;
    const int MAX_V = 110;
    int cost[MAX_V][MAX_V];
    int mincost[MAX_V];
    bool used[MAX_V];

    int V, E;
    cin >> V >> E;
    for (int i = 0; i < V; ++i){
        for (int j = 0; j < V; ++j){
            cost[i][j] = INF;
        }
    }
    for (int i = 0; i < V; ++i){
        mincost[i] = INF;
        used[i] = false;
    }
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    for (int i = 0; i < V; ++i){
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[0] = 0;
    int res = 0;

    while (true){
        int v = -1;
        for (int u = 0; u < V; ++u){
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) {
                v = u;
            }
        }
        if (v == -1) break;
        
        used[v] = true;
        res += mincost[v];

        for (int u = 0; u < V; ++u){
            mincost[u] = min(mincost[u], cost[v][u]);
        } 
    }

    cout << res << endl;
    return 0;
}