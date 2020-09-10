#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    bool z = false;
    vector<int> S;

    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        int s;
        cin >> s;
        if (s == 0) z = true;
        S.push_back(s);
    }

    int l = 0, r = 0, ans = 0;
    long long P = 1;
    while (r < N){
        P *= S[r++];
        while (l < r && P > K){
            P /= S[l++];
        }
        ans = max(ans, r-l);
    }

    if (z){
        cout << N << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}