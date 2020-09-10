#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int black = 48;
const int white = 49;

int main(){
    string S;
    cin >> S;
    int N = S.length();


    int ans_w = 0;
    for (int i = 0; i < N; ++i){
        int _01 = (i%2 == 0 ? white : black);
        if (S[i] != _01){
            ans_w++;
        }
    }

    int ans_b = 0;
    for (int i = 0; i < N; ++i){
        int _01 = (i%2 == 0 ? black : white);
        if (S[i] != _01){
            ans_b++;
        }
    }

    cout << min(ans_b, ans_w) << endl;

}