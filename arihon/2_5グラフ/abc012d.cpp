#include <iostream>
using namespace std;

int main(){
    const int INF = 1e9;
    const int MAX_V = 300 + 10;
    const int MAX_E = 50000;
    int V, E;
    int d[MAX_V][MAX_V];

    cin >> V >> E;
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

    for (int k = 1; k <= V; ++k)
        for (int i = 1; i <= V; ++i)
            for (int j = 1; j <= V; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


    int ans = INF;
    for (int i = 1; i <= V; ++i){
        int m = 0;
        for (int j = 1; j <= V; ++j) {
            m = max(m, d[i][j]);
        }
        ans = min(ans, m);
    }
    cout << ans << endl;
}