#include <iostream>
#include <algorithm>
using namespace std;

struct edge { int u, v, cost; };
const int MAX_V = 10010;
const int MAX_E = 100010;
edge es[MAX_E];
int V, E;

bool comp (const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}
int par[MAX_V];
int size[MAX_V];
int _rank[MAX_V];
void init(int n){
    for (int i = 0; i < n; i++){
        par[i] = i;
        size[i] = 1;
        _rank[i] = 0;
    }
}
int getRoot(int x){
    if (par[x] == x){
        return x;
    }else{
        return par[x] = getRoot(par[x]);
    }
}
void unite(int x, int y){
    x = getRoot(x);
    y = getRoot(y);
    if (x == y) return;
    if (_rank[x] == _rank[y]) {
        par[y] = x;
        size[x] = size[x] + size[y];
        _rank[x]++;  
    }else if (_rank[x] < _rank[y]) {
        par[x] = y;
        size[y] = size[x] + size[y];
    }else if (_rank[x] > _rank[y]) {
        par[y] = x;
        size[x] = size[x] + size[y];
    }
}
int getSize(int x){
    return size[getRoot(x)];
}
bool isSame(int x, int y){
    return getRoot(x) == getRoot(y);
}


// kruskal
int main(){
    cin >> V >> E;
    for (int i = 0; i < E; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        es[i] = {a+1, b+1, c};
    }

    sort(es, es + E, comp);
    init(V);
    int res = 0;
    for (int i = 0; i < E; ++i){
        edge e = es[i];
        if (!isSame(e.u, e.v)){
            unite(e.u, e.v);
            res += e.cost;
        }
    }

    cout << res << endl;
    return 0;
}