#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{ int u,v,cost; };
const int MAX_E = 2e5+10;
const int MAX_V = 1e5+10;
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

long long kruskal(){
    sort(es.begin(), es.end(), comp); 
    init(V);

    long long res = 0;
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

    vector<pair<int, int>> X;
    vector<pair<int, int>> Y;
    cin >> V;
    for (int i = 1; i <= V; ++i){
        int x, y;
        cin >> x >> y;
        X.push_back(make_pair(x,i));
        Y.push_back(make_pair(y,i));
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i = 0; i < V-1; ++i){
        es.push_back(edge{X[i].second, X[i+1].second, abs(X[i].first-X[i+1].first)});
        es.push_back(edge{Y[i].second, Y[i+1].second, abs(Y[i].first-Y[i+1].first)});
    }
    int ans = kruskal();
    cout << ans << endl;


    return 0;
}