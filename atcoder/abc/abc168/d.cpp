#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include<iomanip>
using namespace std;
typedef long long ll;


int main(){
    int N, M, MAX_N = 1e5+10;
    vector<int> E[MAX_N];
    int ans[MAX_N];
    queue<int> q;
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        ans[i] = -1;
    }
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        E[a-1].push_back(b-1);
        E[b-1].push_back(a-1);
    }

    q.push(0);
    while (!q.empty()){
        int v0 = q.front(); q.pop();
        for (int i = 0; i < E[v0].size(); ++i){
            int v1 = E[v0][i];
            if (ans[v1] == -1){
                ans[v1] = v0;
                q.push(v1);
            }
        }
    }
    bool check = true;
    for (int i = 1; i < N; ++i){
        check = check && (ans[i] != -1);
    }

    if (check) {
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    for (int i = 1; i < N; ++i){
        cout << ans[i]+1 << endl;
    }
    return 0;
}