#include <iostream>
using namespace std;
typedef long long ll;

int S(int n){
    int count = 0;
    while (n){
        count += n % 10;
        n /= 10;
    }
    return count;
}
int main(){
    int A,B;
    cin >> A >> B;

    cout << max(S(A), S(B)) << endl;
    return 0;
}
