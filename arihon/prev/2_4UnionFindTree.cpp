#include <iostream>
using namespace std;


const int MAX_N = 50000;
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