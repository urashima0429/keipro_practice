#include <iostream>
using namespace std;

int main() {
    int A, B, ans = 0;
    cin >> A >> B;
    while( (A-1)* ans < B-1){
        ans++;
    }
    cout << ans << endl;
}