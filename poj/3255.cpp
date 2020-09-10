#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 5000;
const int INF = 1e9;
struct edge{ int to, cost; };
typedef pair<int, int> P;
vector<edge> G[MAX_V + 10];
int dist1[MAX_V + 10];
int dist2[MAX_V + 10];
int V, E;


// O(ElogV)
// すべての辺のコストが正の時のみ使える
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    for (int i = 0; i <= V; ++i) dist1[i] = INF;
    for (int i = 0; i <= V; ++i) dist2[i] = INF;
    dist1[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second, d1 = p.first; 
        if (dist2[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i){
            edge e = G[v][i];
            int d2 = d1 + e.cost;
            if (dist1[e.to] > d2){
                swap(dist1[e.to], d2);
                que.push(P(dist1[e.to], e.to));
            }
            if (dist2[e.to] > d2 && dist1[e.to] < d2){
                dist2[e.to] = d2;
                que.push(P(dist1[e.to], e.to));
            }
        }
    }
}


int main(){

    cin >> V >> E;
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edge ea = {b,c};
        edge eb = {a,c};
        G[a].push_back(ea);
        G[b].push_back(eb);
    }

    int s = 1;
    int g = V;
    dijkstra(s);

    cout << dist2[g] << "\n" << endl;
    return 0;
}