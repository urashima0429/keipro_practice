#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 1000;
const int MAX_E = 10000;
const int INF = 1e15;
struct edge{ int to; int cost; };
typedef pair<int, int> P;
vector<edge> G[MAX_V + 10];
// [cost][mod4][mod7]
int d[MAX_V + 10][4][7];
int V, E;

// // 経路保存
// int pre_v[MAX_V];
// vector<int> path;

// O(ElogV)
// すべての辺のコストが正の時のみ使える
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    for (int i = 0; i <= V; ++i) 
        for (int j = 0; j < 4; ++j) 
            for (int k = 0; k < 7; ++k) d[i][j][k] = INF;
    // for (int i = 0; i <= V; ++i) pre_v[i] = -1;
    d[s][0][0] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        int mod4 = p.first % 4;
        int mod7 = p.first % 7;
        if (d[v][mod4][mod7] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i){
            edge e = G[v][i];
            int _mod4, _mod7;
            _mod4 = (mod4 + e.cost) % 4;
            _mod7 = (mod7 + e.cost) % 7;
            if (d[e.to][_mod4][_mod7] > d[v][mod4][mod7] + e.cost){
                d[e.to][_mod4][_mod7] = d[v][mod4][mod7] + e.cost;
                // pre_v[e.to] = v;
                que.push(P(d[e.to][_mod4][_mod7], e.to));
            }
        }
    }
}


int main(){

    cin >> V >> E;
    for (int i = 0; i < E; ++i){
        int a, b;
        int c;
        cin >> a >> b >> c;
        if (a == V-1)
            G[b].push_back(edge{a,c});
        else if (b == V-1){
            G[a].push_back(edge{b,c});
        }else{
            G[a].push_back(edge{b,c});
            G[b].push_back(edge{a,c});
        }
    }

    int s = 0;
    int g = V-1;
    dijkstra(s);

    int ans = INF;
    for (int i = 0; i < 4; ++i){
        ans = min(ans, d[g][i][0]);
    }
    for (int i = 0; i < 7; ++i){
        ans = min(ans, d[g][0][i]);
    }
    cout << ans << endl;

    // // 経路保存
    // int t = g;
    // path.push_back(t);
    // while(t != s) {
    //     t = pre_v[t];
    //     path.push_back(t);
    // }
    // reverse(path.begin(), path.end());
    // for(int i = 0; i != path.size(); ++i) {
    //     cout << path[i] << endl;
    // }
}