#include <iostream>
#include <string>
using namespace std;

bool match(string s, string t){
    int l = s.length();
    for (int i = 0; i < l; ++i){
        if (s[i] != '?' && s[i] != t[i]){
            return false;
        }
    }
    return true;
}

int main() {
    string S, T, ans = "UNRESTORABLE";
    cin >> S >> T;
    int sl = S.length();
    int tl = T.length();
    for (int i = sl-tl; i >= 0; --i){
        string s = S.substr(i, tl);
        if (match(s, T)){
            ans = S.substr(0, i) + T + S.substr(i + tl, sl - tl - i);
            for (int j = 0; j < ans.length(); j++){
                if (ans[j] == '?') ans[j] = 'a';
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}