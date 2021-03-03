#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if (C == 0){
        cout << (A > B ? "Takahashi" : "Aoki") << endl;
    } else {
        cout << (A >= B ? "Takahashi" : "Aoki") << endl;    
    }

    return 0;
}
