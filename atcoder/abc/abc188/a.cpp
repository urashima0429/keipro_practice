#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int A,B;
    cin >> A >> B;
    cout << (max(A, B) < min(A, B) + 3 ? "Yes" : "No") << endl;
    return 0;
}
