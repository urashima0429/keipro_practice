#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 100000;
const int MAX_E = 100000;
int par[MAX_V + 10];
int size[MAX_V + 10];
int rankrank[MAX_V + 10];
long V, E, A[MAX_E], B[MAX_E];
long long ans[MAX_E];


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
    cin >> V >> E;
    for (long long i = 0; i < E; ++i){
    	cin >> A[i] >> B[i];
    }
    init(V);
    for (long long i = 0; i < E ; ++i) ans[i] = 0LL;

	int da;
    for (long long i = E-1; i >= 0; --i){
		if (i == E-1) ans[i] = V*(V-1)/2;
		else ans[i] = ans[i+1] - da;
		da = isSame(A[i], B[i]) ? 0 : getSize(A[i]) * getSize(B[i]);
    	unite(A[i], B[i]);
    }

    for (long long i = 0; i < E ; ++i){
    	cout << ans[i]<< endl;
    }
    return 0;
}