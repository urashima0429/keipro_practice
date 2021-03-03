#include <iostream>
using namespace std;
typedef long long ll;

int N, K, T[1<<3][1<<3];
ll res = 0; 
void dfs(int now, int set, int sum){
    if (now == 0 && set == (1<<N)-1) {
        if (sum == K) res++;
        return;
    }
    for (int i = 0; i < N; ++i){
        if (set & (1<<i)) continue;
        dfs(i, set ^ (1<<i), sum + T[now][i]);
    }

}
int main() {

    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> T[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << res << endl;
    return 0;
}