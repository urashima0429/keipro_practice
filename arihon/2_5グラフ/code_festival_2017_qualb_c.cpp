#include <iostream>
#include <vector>
using namespace std;

// WA

const int MAX_N = 1e5+10;
int N, M, V[MAX_N];
vector<int> E[MAX_N];

void dfs(int v, int g){
    V[v] = g;
    for (auto e : E[v]){
        if (V[e] == -1){
            dfs(e, 1 - g);
        }
    }
    return;
}

int main(){
    cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        V[i] = -1; 
    }
    for (int i = 0; i < M; ++i){
        int a,b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1,0);

    int sum0 = 0, sum1 = 0;
    for (int i = 1; i <= N; ++i){
        if (V[i] == 1) sum1++;
        else sum0++;
    }
    cout << sum0 * sum1 - M << endl;

    return 0;
}