#include <iostream>
using namespace std;

int main(){
    long long L, R;

    cin >> L >> R;
    if(R - L > 2100){
        cout << 0 << endl;
    }else{
        long long ans = 2019;
        for (long long i = L; i < R; ++i){
            for (long long j = i + 1; j <= R; ++j){
                ans = min(ans, (i * j) % 2019 ); 
            }
        }
        cout << ans << endl;
    }
    return 0;
}