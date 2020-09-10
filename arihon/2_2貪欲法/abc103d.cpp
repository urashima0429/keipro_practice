#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    vector<pair<int, int>> v;
    cin >> N >> M;
    for (int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());

    int ans = 0;
    int cut = 0;
    for (int i = 0; i < M; ++i){
        auto p = v[i];
        int a = p.second;
        int b = p.first; 
        if (cut < a){
            ans++;
            cut = b-1;
        }
    }
    cout << ans << endl;


    return 0;
}
