#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 2e5 + 10;
int N, Q, D[MAX_N], X[MAX_N];
vector<int> G[MAX_N];

void dfs(int v, int sum){
    sum += X[v];
    D[v] = sum;
    for (auto _v : G[v]){
        if (D[_v] == -1) dfs(_v, sum);
    }
    return;
}

int main(){
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) X[i] = 0;
    for (int i = 1; i <= N; ++i) D[i] = -1;
    for (int i = 0; i < N-1; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < Q; ++i){
        int p, x;
        cin >> p >> x;
        X[p] += x;
    }

    dfs(1, 0);

    for (int i = 1; i <= N; ++i){
        cout << D[i] << " ";
    }cout << endl;

    return 0;
}