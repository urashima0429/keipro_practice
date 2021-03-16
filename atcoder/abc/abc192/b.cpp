#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    bool OK = true;
    string S;
    cin >> S;
    for (int i = 0; i < S.length(); ++i){
        if (i % 2 == 0){
            if (65 <= S[i] && S[i] <= 90 ){
                OK = false;
            }
        } else {
            if (97 <= S[i] && S[i] <= 122 ){
                OK = false;
            }
        }
    }
    cout << (OK ? "Yes" : "No") << endl;
    return 0;
}
