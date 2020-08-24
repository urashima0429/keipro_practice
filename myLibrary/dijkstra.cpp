#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 110;
const int MAX_E = 510;
const int INF = 1e9;
struct edge{ int to, cost; };
typedef pair<int, int> P;
vector<edge> G[MAX_V];
int d[MAX_V];
int V, E;

// 経路保存
int pre_v[MAX_V];

// すべての辺のコストが正の時のみ使える
// O(ElogV)
// int s : 始点
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    for (int i = 1; i <= V; ++i) d[i] = INF;
    for (int i = 1; i <= V; ++i) pre_v[i] = -1;
    d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i){
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                pre_v[e.to] = v;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


int main(){
    int S;
    cin >> V >> E >> S;
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edge e = {b+1,c};
        G[a+1].push_back(e);
    }

    dijkstra(S+1);

    for (int i = 1; i <= V; ++i){
        if (d[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << d[i] << endl;

            // // 経路
            // vector<int> path;
            // int t = i;
            // while(t != S+1) {
            //     t = pre_v[t];
            //     path.push_back(t);
            // }
            
            // reverse(path.begin(), path.end());

            // for(int i = 0; i < path.size(); ++i) {
            //     cout << path[i] << " -> ";
            // }
            // cout << endl;
        }
    }


}