#include <iostream>
using namespace std;


const int MAX_N = 50000;
const int MAX_K = 100000;
int par[MAX_N * 3 + 10];
int rankrank[MAX_N * 3 + 10];

void init(int n){
    for (int i = 0; i < n; i++){
        par[i] = i;
        rankrank[i] = 0;
    }
}

int find(int x){
    if (par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
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

bool same(int x, int y){
    return find(x) == find(y);
}

int main() {

    //initialize
    int N;
    int K;
    int T[MAX_K], X[MAX_K], Y[MAX_K];

    // input
    cin >> N >> K;
    for (int i = 0; i < K; ++i){
        cin >> T[i] >> X[i] >> Y[i];
    }

    init(N * 3);

    int ans = 0;
    for (int i = 0; i < K; i++){
        int t = T[i];
        int x = X[i] - 1;
        int y = Y[i] - 1;

        if (x < 0 || N <= x || y < 0 || N <= y){
            ans++;
            continue;
        }

        if (t == 1){
            if (same(x, y + N) || same(x, y + 2 * N)){
                ans++;
            }else{
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }else{
            if (same(x, y) || same(x, y + 2 * N)){
                ans++;
            }else{
                unite(x, y + N);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }
    }

    cout << ans << endl;
}