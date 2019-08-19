#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    string s,t;
    vector<int> A[26];
    cin >> s >> t;
    for (int i = 1; i <= s.length(); ++i){
        A[s[i-1] - 97].push_back(i);
    }

    bool cant = false;
    int prev = 0, ans = 0;
    for (int i = 1; i <= t.length(); ++i){
        if (A[t[i-1] - 97].size() <= 0) {
            cant = true;
            break;
        }
        vector<int> c = A[t[i-1] - 97];
        for (auto _c : c){
            if (c)
        }
        
        cout << prev <<endl;

    }
    if (cant){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}