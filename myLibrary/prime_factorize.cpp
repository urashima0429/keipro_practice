#include <iostream>
#include <map>
using namespace std;

// 素因数分解
// O(n^(1/2))
map<int, int> prime_factorize(int n){
    map<int, int> res;
    for (int i = 2; i * i <= n; ++i){
        while(n % i == 0){
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

int main(){
    int N;
    cin >> N;

    auto m = prime_factorize(N);
    for (auto i : m){
        cout << i.first << ":" << i.second << endl;
    }
    return 0;
}