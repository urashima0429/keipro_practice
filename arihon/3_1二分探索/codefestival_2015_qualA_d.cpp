#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M, INF = 1e9;
vector<int> X;

bool check(int m){
    int prev = 0;
    for (int i = 0; i < M; ++i){
        if( X[i] - 1 <= prev){
            prev = X[i] + m; 
        }else{
            if (X[i] - m > prev) return false;
            prev = max(X[i], X[i] + (m - 2*(X[i]-prev-1)) ); 
        }
        // cout << m << ":" << prev << endl;
    }
    // cout << "c:" << (prev >= N) << endl;
    return prev >= N; 


}

int main(){

    cin >> N >> M;
    for (int i = 0; i < M; ++i){
        int x;
        cin >> x;
        X.push_back(x);
    }

    int l = 0, m, r = INF; 
    while (l + 1 < r){
        m = (l + r) / 2;
        if (check(m)){
            r = m;
        }else{
            l = m;
        }
        // cout << "l" << l << "::" << "r" << r << endl;
    }
    cout << l << endl;
}