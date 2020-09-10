#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int N;
    vector<int> A;
    map<int, int> m;

    cin >> N;
    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }

    int l = 0, ans = 0;
    for (int r = 0; r < N; ++r){
        m[A[r]]++;
        while (l < r && m[A[r]] > 1){
            m[A[l++]]--;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
    return 0;
}