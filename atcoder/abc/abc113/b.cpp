#include <iostream>
using namespace std;

int main() {
    int N, T, A;
    cin >> N >> T >> A;

    int min = 1e9, ans = 0, target = (T - A) * 1000;
    for (int i = 1; i <= N; ++i){
        int h, d;
        cin >> h;
        d = abs(target - 6 * h);
        if (d < min){
            min = d;
            ans = i;
        }
    }

    cout << ans << endl;
}