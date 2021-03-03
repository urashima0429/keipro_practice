#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    char C[3];
    cin >> C;
    cout << (C[0] == C[1] && C[1] == C[2] ? "Won" : "Lost") << endl;
    return 0;
}
