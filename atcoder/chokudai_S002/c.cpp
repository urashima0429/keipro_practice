#include <iostream>

using namespace std;

int main(){
    const int MAX_N = 1e5 + 10;
    int N;
    cin >> N;

    int ans = 2;
    for (int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        ans = (a+b > ans ? a+b : ans);
    }

    cout << ans << endl;
    return 0;
}