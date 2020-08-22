#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

// TLE

int main(){
    string s,t;
    vector<int> A[26];
    cin >> s >> t;
    int S = s.length();
    int T = t.length();
    for (int i = 1; i <= S; ++i){
        A[s[i-1] - 97].push_back(i);
        A[s[i-1] - 97].push_back(i + S);
    }
    for (int i = 1; i <= 26; ++i){
        sort(A[i-1].begin(), A[i-1].end());
    }
    
    bool check = false;
    ll ans = 0LL;
    int prev = 0;
    for (int i = 1; i <= T; ++i){
        auto v = A[t[i-1] - 97]; 
        auto b = upper_bound(v.begin(), v.end(), prev);
        if (b == v.end()) {
            check = true;
            break;
        }
        int k = b - v.begin();
        ans += (ll)(v[k] - prev);
        prev = v[k] >= S ? v[k]-S : v[k];
    }
    if (check){
        cout << -1 << endl;       
    }else{
        cout << ans << endl;        
    }
    return 0;
}















































       









