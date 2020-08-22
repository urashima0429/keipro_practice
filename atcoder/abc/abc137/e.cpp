#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_E = 5010;
const int MAX_V = 2510;
const ll INF = 1e18;
struct edge{ ll from, to, cost; };
edge e[MAX_E];
ll d[MAX_V];
int V, E;

// O(V * E)
bool bellman_ford(int s = 1, int g = V){
    for (int i = 1; i <= V; ++i) d[i] = -INF;
    d[s] = 0;
        
    bool update = false;
    for (int i = 1; i <= V; ++i){
        for (int j = 0; j < E; ++j){
            edge _e = e[j];
            if (d[_e.from] != -INF && d[_e.to] < d[_e.from] + _e.cost){
                d[_e.to] = d[_e.from] + _e.cost;
                if (i == V && _e.to == V) update = true;
            } 
        }

    }
    return update;
}


int main(){
    int P;
    cin >> V >> E >> P;
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = edge{a,b,c-P};
    }

    if (bellman_ford()){
        cout << -1 << endl;;
    }else{
        cout << max(d[V], 0LL) << endl;
    }
}