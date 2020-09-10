#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



int main(){
    int N, M;
    vector<pair<int, int>> v;
    priority_queue<int> q;
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b)); 
    }
    sort(v.begin(), v.end());

    int j = 0, ans = 0; 
    for (int i = 1; i <= M; ++i){
        while(j < N && v[j].first <= i){
            q.push(v[j++].second);
        }
        if (!q.empty()){
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}