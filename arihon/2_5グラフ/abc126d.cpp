#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_E = 1e5 + 10;
const int MAX_V = 1e5 + 10;
const long long INF = 1e18;
struct edge{ int to, cost; };
typedef pair<int, int> P;
vector<edge> G[MAX_V + 10];
long long d[MAX_V + 10];
int V, E;

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    for (int i = 1; i <= V; ++i) d[i] = INF;
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
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


int main(){

    cin >> V;
    E = V-1;
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(edge{b,c});
        G[b].push_back(edge{a,c});
    }

    int s = 1;
    dijkstra(s);

    for (int i = 1; i <= V; i++){
		cout << d[i] % 2 << endl;    		
    }
    return 0;
}