#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 111;
    while(N > ans){
        ans += 111;
    }
    cout << ans << endl;
    return 0;
}