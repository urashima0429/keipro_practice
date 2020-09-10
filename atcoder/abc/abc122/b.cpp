#include <iostream>
#include <string>
using namespace std;

bool isACGT(char a){
    if (
        a == 'A'
        || a == 'C'
        || a == 'G'
        || a == 'T') return true;
    else return false;
}

int main() {
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < S.length(); ++i){
        int counter = 0;
        for (int j = i; j < S.length(); ++j){
            if ( isACGT(S[j]) ) counter++;
            else break;
        }
        ans = (counter > ans ? counter : ans);
    }
    cout << ans << endl;
    return 0;
}