#include <iostream>
using namespace std;
 
int main(){
    const int MAX_N = 1e5 + 10;
    int N, A[MAX_N];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
 
    int B = 0;
    int h = 1;
    for (int i = 0; i < N; ++i){
        B += h*A[i];
        h *= -1;
    }
 
    for (int i = 0; i < N; ++i){
        cout << B << " ";
        B = 2*A[i] - B; 
    }
    cout << endl;
    return 0;
}