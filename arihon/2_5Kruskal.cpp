#include <iostream>
#include <algorithm>
using namespace std;

struct edge{ int u,v,cost; };
const int MAX_E = 100;
const int MAX_V = 100;
int par[MAX_V + 10];
int rankrank[MAX_V + 10];
vector<edge> es;
int V, E;

void init(int n){
    for (int i = 0; i < n; i++){
        par[i] = i;
        rankrank[i] = 0;
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
    if (rankrank[x] == rankrank[y]) {
        par[y] = x;
        rankrank[x]++;  
    }else if (rankrank[x] < rankrank[y]) {
        par[x] = y;
    }else if (rankrank[x] > rankrank[y]) {
        par[y] = x;
    }
}

bool isSame(int x, int y){
    return getRoot(x) == getRoot(y);
}

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

int kruskal(){
    sort(es.begin(), es.end(), comp); 
    init(V);

    int res = 0;
    for (auto i = es.begin(); i != es.end(); ++i){
        edge e = *i;
        if (!isSame(e.u, e.v)){
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}


int main(){

    return 0;
}