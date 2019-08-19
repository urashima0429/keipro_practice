#include <iostream>
#include <map>
using namespace std;

// WA

const int MOD = 1e9+7;
int N, M;

map<int, int> prime_factor(int n){
    map<int, int> res;
    for (int i = 2; i*i <= n; ++i){
        while(n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) res[n] += 1;
    return res;
}


int main(){
    cin >> N >> M;;
    auto m = prime_factor(M);
    for (auto d : m){
        cout << d.first << ":" << d.second << endl;
    }
}