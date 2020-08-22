#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int MAX_N = 20;
    int N, V[MAX_N], C[MAX_N];    
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> V[i];
    }   
    for (int i = 0; i < N; ++i){
        cin >> C[i];
    }  

    int ans = 0;
    for (int i = 0; i < N; ++i){
        ans += max(0, V[i] - C[i]);
    }
    
    cout << ans << endl;
}