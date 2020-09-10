#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_V = 100;
const int INF = 1e9;
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;

// O(V^2)

int X[MAX_V], Y[MAX_V];

int prim(){
    for (int i = 0; i < V; ++i){
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[0] = 0;
    int res = 0;

    while(true){
        int v = -1;

        for (int u = 0; u < V; ++u){
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
        
        if (v == -1) break;
        used[v] = true;
        res += mincost[v];
        
        for (int u = 0; u < V; ++u){
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }

    return res;
}

int main(){

    cin >> V;
    for (int i = 0; i < V; ++i){
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < V; ++i){
        for (int j = 0; j < V; ++j){
            if (i == j) cost[i][j] = 0;
            else cost[i][j] = min(abs(X[i]-X[j]), abs(Y[i]-Y[j]));
        }        
    }

    cout << prim() << endl;
}