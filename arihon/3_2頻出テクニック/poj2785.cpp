#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    const int MAX_N = 4000 + 10;
    int N, A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            v.push_back(C[i] + D[j]);
        }   
    }
    sort(v.begin(), v.end());
    
    long long ans = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            int _ab = -(A[i] + B[j]);
            ans += upper_bound(v.begin(), v.end(), _ab) - lower_bound(v.begin(), v.end(), _ab); 
        }   
    }
    cout << ans << endl;
    return 0;
}
