#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX_N = 100000;

int main(){

    // input
    int N, S[MAX_N], T[MAX_N];
    pair<int, int> work[MAX_N];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> S[i];
    }
    for (int i = 0; i < N; ++i){
        cin >> T[i];
    }

    // initialize
    for (int i = 0; i < N; ++i){
        work[i].first = T[i];
        work[i].second = S[i];
    }
    
    sort(work, work+N);

    int ans = 0, t = 0;
    for (int i = 0; i < N; ++i){
        if (t < work[i].second){
            ans++;
            t = work[i].first;
        }
    }

    cout << ans << endl;


}