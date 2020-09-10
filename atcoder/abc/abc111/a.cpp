#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.length(); ++i){
    	S[i] = (S[i] == '1' ? '9' : '1');
    }
    cout << S << endl;
    return 0;
}