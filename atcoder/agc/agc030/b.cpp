#include <iostream>
#include <set>
using namespace std;

int L, N, X[200000 + 1];

int main() {
    cin >> L >> N;
    for (int i = 0; i < N; ++i){
        cin >> X[i];
    }

    int ans = 0;

    // left
    bool clockwise = true;
    int x = 0;
    int next = 0;
    int prev = N-1;
    for (int i = 0; i < N; ++i){
        if (!clockwise){
            ans += X[next] - x;
            x = X[next];
            next++;
        }else{
            ans += L - (X[prev] - x);
            x = X[prev];
            prev--;
        }
        clockwise = !clockwise;
    }   

    cout << ans << endl;

}