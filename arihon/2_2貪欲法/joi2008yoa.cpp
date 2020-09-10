#include <iostream>
using namespace std;

int main() {

    int N, ans = 0;
    cin >> N;
    N = 1000 - N;
    ans += N / 500;
    N = N % 500;
    ans += N / 100;
    N = N % 100;
    ans += N / 50;
    N = N % 50;
    ans += N / 10;
    N = N % 10;
    ans += N / 5;
    N = N % 5;
    ans += N / 1;
    cout << ans << endl;
}
