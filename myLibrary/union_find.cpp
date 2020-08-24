#include <iostream>
using namespace std;

const int MAX_N = 100010;
int par[MAX_N];
int size[MAX_N];
int _rank[MAX_N];

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
