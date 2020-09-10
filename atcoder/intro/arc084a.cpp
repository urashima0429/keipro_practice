#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> A, B, C;
    cin >> N;
    int a;
    for (int i = 0; i < N; ++i) {cin >> a; A.push_back(a);}
    for (int i = 0; i < N; ++i) {cin >> a; B.push_back(a);}
    for (int i = 0; i < N; ++i) {cin >> a; C.push_back(a);}
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int ans = 0;
    for (int i = 0; i < N; ++i){
        int b = lower_bound(B.begin(), B.end(), C[i]) - B.begin();
        for (int j = 0; j < b; ++j){
            int a = lower_bound(A.begin(), A.end(), B[j]) - A.begin();
            ans += a;
        }
    }
    cout << ans << endl;
}