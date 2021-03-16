#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, X;
    cin >> N >> X;
    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;

        if (a != X) {
            cout << a << " ";
        }
    }

    cout << endl;
    return 0;
}
