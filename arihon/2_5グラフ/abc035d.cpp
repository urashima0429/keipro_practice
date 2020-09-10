#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// WA

const int MAX_E = 1e5 + 10;
const int MAX_V = 1e5 + 10;
const long long INF = 1e18;
struct edge{ int to, cost; };
typedef pair<int, int> P;
vector<edge> G[MAX_V + 10];
long long d[MAX_V + 10];
vector<edge> _G[MAX_V + 10];
long long _d[MAX_V + 10];
int V, E;
long long A[MAX_V];

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


void _dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    for (int i = 1; i <= V; ++i) _d[i] = -INF;
    _d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if (_d[v] > p.first) continue;
        for (int i = 0; i < _G[v].size(); ++i){
            edge e = _G[v][i];
            if (_d[e.to] < _d[v] + e.cost){
                _d[e.to] = _d[v] + e.cost;
                que.push(P(_d[e.to], e.to));
            }
        }
    }
}


int main(){
    long long T;
    cin >> V >> E >> T;
    for (int i = 1; i <= V; ++i){
        cin >> A[i];
    }
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(edge{b,c});
        _G[b].push_back(edge{a,-c});
    }

    int s = 1;
    dijkstra(s);
    _dijkstra(s);

    long long ans = 0;
    for (int i = 1; i <= V; i++){
        // cout << A[i] * (T - d[i] + _d[i]) << endl;
        ans = max(ans, A[i] * (T - d[i] + _d[i]));
    }    
    cout << ans << endl;
    return 0;
}