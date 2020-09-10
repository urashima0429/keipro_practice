#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    const int INF = 1e9;
    const int MAX_V = 200 + 10;
    const int MAX_E = 40000;
    int V, E, R;
    int d[MAX_V][MAX_V];
    vector<int> v;

    cin >> V >> E >> R;
    for (int i = 0; i < R; ++i){
        int r;
        cin >> r;
        v.push_back(r);
    }
    sort(v.begin(), v.end());
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
    
    long long ans = INF;
    do {
        long long sum = 0;
        for (int i = 0; i < R-1; ++i){
            sum += d[v[i]][v[i+1]];
        }
        ans = min(ans, sum);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}