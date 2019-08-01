#include <iostream>
#include <algorithm>
using namespace std;

// warshall_floyd

const int INF = 1e9;
const int MAX_V = 200;
const int MAX_E = 20000;
const int MAX_R = 10;
int V, E, R;
int r[MAX_R + 10];
int d[MAX_V + 10][MAX_V + 10];

// O(V^3)
// 全対点最短経路
// 負の閉路が存在するかどうか
bool warshall_floyd (){
    for (int k = 1; k <= V; ++k)
        for (int i = 1; i <= V; ++i)
            for (int j = 1; j <= V; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j) 
            if (d[i][j] < 0) return true;

    return false;
}

int main(){

    cin >> V >> E >> R;
    for (int i = 0; i < R; ++i){
        cin >> r[i];
    }
    for (int i = 1; i <= V; ++i){
        for (int j = 1; j <= V; ++j) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }

    warshall_floyd();

    int ans = INF;

    sort(r, r+R);
    do {
        int sum = 0;
        for (int i = 0; i < R - 1; ++i) sum += d[r[i+1]][r[i]];
        ans = min(ans, sum);
    }while(next_permutation(r, r+R));

    cout << ans << endl;
    return 0;
}