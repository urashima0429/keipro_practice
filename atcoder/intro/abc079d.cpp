#include <iostream>
#include <algorithm>
using namespace std;

// warshall_floyd

const int INF = 1e9;
const int MAX_V = 10;
const int MAX_H = 200;
const int MAX_W = 200;
int V = 10, H, W;
int d[MAX_V + 10][MAX_V + 10];
int A[MAX_H + 10][MAX_W + 10];

// O(V^3)
// 全対点最短経路
// 負の閉路が存在するかどうか
bool warshall_floyd (){
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 1; j <= V; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j) 
            if (d[i][j] < 0) return true;

    return false;
}

int main(){

    cin >> H >> W;
    for (int i = 0; i < V; ++i){
        for (int j = 0; j < V; ++j){
            int c;
            cin >> c;
            if (c == -1) d[i][j] = INF;
            else d[i][j] = c;
        }
    }
    warshall_floyd();

    int ans = 0;
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j) {
            int a;
            cin >> a;
            if (a != -1 && a != 1) ans += d[a][1];
        }
    }

    cout << ans << endl;
    return 0;
}