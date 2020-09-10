#include <iostream>
using namespace std;


int main() {
    long long X, Y;
    cin >> X >> Y;

    long long th = Y / X;
    long long t = 1;
    int ans = 0;
    while(t <= th){
        ans++;
        t <<= 1;
    }
    cout << ans << endl;
    return 0;
}