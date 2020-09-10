#include <iostream>
using namespace std;

// WA
int main(){
    int N;
    cin >> N;   
    cout << N << ":";
    int n = N;
    for (int i = 2; i * i <= N; ++i){
        while (n % i == 0){
            cout << " " << i;
            n /= i;
        }
    }
    cout << endl;
    return 0;
}