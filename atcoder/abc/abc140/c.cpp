#include <iostream>
using namespace std;

int main(){
    int N, B[110], ans = 0;
    cin >> N;
    for (int i = 0; i < N-1; ++i){
        cin >> B[i];
    }
    
    ans += B[0];
    for (int i = 0; i < N-2; ++i){
        ans += min(B[i], B[i+1]);
    }
    ans += B[N-2];
    cout << ans << endl;
    return 0;
}