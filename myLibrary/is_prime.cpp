#include <iostream>
using namespace std;

// 素数判定
// O(n^(1/2))
bool is_prime(int n){
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main(){
    int N;
    cin >> N;
    if (is_prime(N)){
        cout << "true" << endl; 
    } else {
        cout << "false" << endl; 
    }
    return 0;
}