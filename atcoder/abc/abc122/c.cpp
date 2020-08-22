#include <iostream>
#include <string>
using namespace std;


const int MAX_N = 100000;
int N, Q;
string S;
int ans[MAX_N];

int main(){
    for (int i = 0; i < N; ++i){
        ans[i] = 0;
    }

    // input
    cin >> N >> Q >> S;

    char prev;
    int counter = 0;
    for (int i = 0; i < N; ++i){
        if (prev == 'A' && S[i] == 'C') ++counter;
        ans[i] = counter;
        prev = S[i];
    }

    for (int i = 0; i < Q; ++i){
        int l, r;
        cin >> l >> r;
        cout << ans[r-1] - ans[l-1] << endl;
    }

    return 0;
}