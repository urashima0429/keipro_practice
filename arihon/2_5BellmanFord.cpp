#include <iostream>
using namespace std;

const int MAX_E = 100;
const int MAX_V = 100;
const int INF = 1e9;
struct edge{ int from, to, cost; };
edge e[MAX_E];
int d[MAX_V];
int V, E;

// O(V * E)
// 負の閉路が存在するかどうか
bool bellman_ford(int s = 1){
    for (int i = 1; i <= V; ++i) d[i] = INF;
    d[s] = 0;

    // |V|回目のループで更新が発生していれば負の閉路が存在する
    for (int i = 1; i <= V; ++i){

        bool update = false;
        // すべての辺に関して更新がないか調べる
        for (int j = 0; j < E; ++j){
            edge _e = e[j];
            if (d[_e.from] != INF && d[_e.to] > d[_e.from] + _e.cost){
                d[_e.to] = d[_e.from] + _e.cost;
                update = true;
            } 
        }
        // 更新がなければ負の閉路は存在しない
        if (!update) return false;
        if (i == V) return true;
    }
}




int main(){

    cin >> V >> E;
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = edge{a,b,c};
    }

    if (bellman_ford()){
        cout << "negative closed loop";
    }else{
        cout << d[V] << endl;
    }
}