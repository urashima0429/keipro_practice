#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, M=0;
    bool can = true;
    cin >> N;
    for (int i = 0; i< N; ++i){
        int h;
        cin >> h;
        if (M - h > 1) {
            can = false;
            break;
        }
        M = max(M, h);
    }
    cout << (can ? "Yes" : "No") << endl;

}