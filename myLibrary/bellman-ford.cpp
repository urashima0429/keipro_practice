#include <iostream>
using namespace std;

const int INF = 1e9;
const int MAX_V = 1010;
const int MAX_E = 2010;
struct edge{ int from, to, cost; };
int d[MAX_V];
edge e[MAX_E];
int V, E;

// グラフに負の辺が含まれる場合はダイクストラではできない
// O(V * E)
// int s : 始点
// return bool : 負の閉路が存在するかどうか
bool bellman_ford(int s = 1){
    for (int i = 1; i <= V; ++i) d[i] = INF;
    d[s] = 0;

    for (int i = 1; i <= V; ++i){
        bool update = false;
        for (int j = 0; j < E; ++j){
            edge _e = e[j];
            if (d[_e.from] != INF && d[_e.to] > d[_e.from] + _e.cost){
                d[_e.to] = d[_e.from] + _e.cost;
                update = true;
            } 
        }
        if (!update) return false;
    }
    return true;
}

int main(){
    int S;
    cin >> V >> E >> S;
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = edge{a+1,b+1,c};
    }

    if (bellman_ford(S+1)){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        for (int i = 1; i <= V; ++i){
            if (d[i] == INF){
                cout << "INF" << endl;
            } else {
                cout << d[i] << endl;
            }
        }
    }
}