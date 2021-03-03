#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    int N, res;
    string S;
    cin >> N >> res >> S;
    for (int i = 0; i < N; ++i){
        if (S[i] == 'o') res++;
        if (S[i] == 'x') res = max(0, res-1);
    }
    cout << res << endl;
    return 0;
}
