#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; ++i){
        int s;
        cin >> s;
        A.push_back(s);
    }
    A.push_back(0);

    long long  l = 0, r = 0, ans = 0;
    while (r < N){
        if (A[r] < A[r+1]){
            r++;
        }else{
            ans += (r-l+1)*(r-l+2)/2;
            l = ++r;
        }
    }
    cout << ans << endl;
    return 0;
}