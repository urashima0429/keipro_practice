#include <iostream>
using namespace std;

const int MAX_N = 200010;
int _par[MAX_N];
int _size[MAX_N];
int _rank[MAX_N];

void init(int n){
    for (int i = 0; i < n; i++){
        _par[i] = i;
        _size[i] = 1;
        _rank[i] = 0;
    }
}

int getRoot(int x){
    if (_par[x] == x){
        return x;
    }else{
        return _par[x] = getRoot(_par[x]);
    }
}

void unite(int x, int y){
    x = getRoot(x);
    y = getRoot(y);
    if (x == y) return;
    if (_rank[x] == _rank[y]) {
        _par[y] = x;
        _size[x] = _size[x] + _size[y];
        _rank[x]++;  
    }else if (_rank[x] < _rank[y]) {
        _par[x] = y;
        _size[y] = _size[x] + _size[y];
    }else if (_rank[x] > _rank[y]) {
        _par[y] = x;
        _size[x] = _size[x] + _size[y];
    }
}

int getSize(int x){
    return _size[getRoot(x)];
}

bool isSame(int x, int y){
    return getRoot(x) == getRoot(y);
}


int main(){

    int N, M;
    cin >> N >> M;
    init(N);
    for (int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        unite(a-1, b-1);
    }

    int res = 1;
    for (int i = 0; i < M; ++i){
        res = max(res, getSize(i));
    }
    cout << res << endl;
}
