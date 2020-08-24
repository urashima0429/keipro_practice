#include <iostream>
using namespace std;
typedef long long ll;

ll INF = 2e18;
const int MAX_V = 110;
const int MAX_E = 10010;
int V, E;
ll d[MAX_V][MAX_V];

// 全対点最短経路
// O(V^3)
// return bool : 負の閉路が存在するかどうか
bool warshall_floyd (){
    for (int k = 1; k <= V; ++k){
        for (int i = 1; i <= V; ++i){
            for (int j = 1; j <= V; ++j) {
                // d[i][k] < 0の時、INFはINF+(d[i][k])に更新されてしまう
                if (d[i][k] != INF && d[k][j] != INF){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
        
    for (int i = 1; i <= V; ++i){
        if (d[i][i] < 0) return true;
    }

    return false;
}

int main(){
    cin >> V >> E;
    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j) 
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        d[a+1][b+1] = c;
    }

    if (warshall_floyd()){
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 1; i <= V; ++i){
            for (int j = 1; j <= V; ++j) {
                if (d[i][j] < INF) {
                    cout << d[i][j];
                } else {
                    cout << "INF";
                }

                if (j == V){
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
    }
}