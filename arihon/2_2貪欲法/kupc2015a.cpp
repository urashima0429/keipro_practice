#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i){
        string S;
        cin >> S;
        int l = S.length();
        int ans = 0;
        for (int j = 0; j < l - 4; ++j){
            string s = S.substr(j, 5);
            if (s == "kyoto" || s == "tokyo"){
                ans++;
                j = j + 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
