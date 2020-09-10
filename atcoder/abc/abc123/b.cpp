#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int m = 10;
    int m_i = 5;
    int A[5];
    for (int i = 0; i < 5; ++i){
        cin >> A[i];
    }

     for (int i = 0; i < 5; ++i){
        int d = A[i] % 10;
        if (m > d && d > 0){
            m = d;
            m_i = i;
        }
     }

    for (int i = 0; i < 5; ++i){
        if (i == m_i) ans += A[i];
        else ans += (int)((A[i] + 9)/10) * 10;
    }
    cout << ans << endl;
    return 0;
}