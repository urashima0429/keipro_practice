#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_pair(pair<int,int> a, pair<int,int> b){
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    const int INF = 1e9; 
    const int MAX_N = 1e5 + 10; 
    int N, dp[MAX_N];
    vector<pair<int, int>> v;
    cin >> N;
    for (int i = 0; i < N; ++i){
        int h, w;
        cin >> h >> w;
        v.push_back(make_pair(h, w));
    }
    sort(v.begin(), v.end(), cmp_pair);

    // for (int i = 0; i < N; ++i){
    //     cout << v[i].first << ":" << v[i].second << endl;
    // }

    for (int i = 0; i < N; ++i){
        dp[i] = INF;
    }
    dp[i] = 1;

    




    return 0;
}
