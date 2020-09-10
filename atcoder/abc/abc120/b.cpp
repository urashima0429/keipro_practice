#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    int c0 = gcd(A,B);

    int i = 0;
    for (int j = c0; 0 < j; --j){        
        if (c0 % j == 0) {
            i++;
        }
        if (i == K) {
            cout << j << endl;
            break;
        }
    }
    return 0;
}