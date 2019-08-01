#include <iostream>
using namespace std;

// BellmanFord

const int MAX_V = 1000;
const int MAX_E = 2000;
const long long INF = 9e18;
struct edge{ int from, to, cost; };
edge e[MAX_E + 10];
long long d[MAX_V + 10];
int V, E;

// 負の閉路が存在するかどうか
bool bellman_ford(){
    for (int i = 1; i <= V; ++i) d[i] = INF;
    d[1] = 0;

    // |V|回目のループで更新が発生していれば負の閉路が存在する
    for (int i = 1; i <= V; ++i){

        bool update = false;
        bool goal_update = false;
        // すべての辺に関して更新がないか調べる
        for (int j = 0; j < E; ++j){
            edge _e = e[j];
            if (d[_e.from] != INF && d[_e.to] > d[_e.from] + _e.cost){
                d[_e.to] = d[_e.from] + _e.cost;
                update = true;
                if (_e.to == V) goal_update = true;
            } 
        }
        // 更新がなければ負の閉路は存在しない
        if (!update) return false;

        //　閉路があっても最短距離が更新され続けるとは限らない
        if (i == V && goal_update) return true;
    }
    return false;
}




int main(){

    cin >> V >> E;
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = edge{a,b,-c};
    }

    if (bellman_ford()){
        cout << "inf" << endl;
    }else{
        cout << -d[V] << endl;
    }

    return 0;
}