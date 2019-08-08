#include <iostream>
#include <set>
using namespace std;


const int MAX_N = 2e5 + 10;
int par[MAX_N + 10];
int size[MAX_N + 10];
int rankrank[MAX_N + 10];

void init(int n){
    for (int i = 0; i < n; i++){
        par[i] = i;
        size[i] = 1;
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
        size[x] = size[x] + size[y];
        rankrank[x]++;  
    }else if (rankrank[x] < rankrank[y]) {
        par[x] = y;
        size[y] = size[x] + size[y];
    }else if (rankrank[x] > rankrank[y]) {
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


int main(){
    int N, K, L;
    set<pair<int, int>> S;
    cin >> N >> K >> L;
    init(N);
    for (int i = 0; i < K; ++i){
        int p,q;
        cin >> p >> q;
        if (p > q) swap(p,q);
        S.insert(make_pair(p, q));
    }
    for (int i = 0; i < L; ++i){
        int r,s;
        cin >> r >> s;
        if (r > s) swap(r,s);
        if (S.find(make_pair(r,s)) != S.end()){
            unite(r,s);
        }
    }
    for (int i = 1; i <= N; ++i){
        cout << getSize(i) << endl;
    }
    return 0;
}