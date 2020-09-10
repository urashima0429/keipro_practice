#include <iostream>
#include <vector>
using namespace std;

// 約数の列挙
// O(n^(1/2))
vector<int> divisor(int n){
    vector<int> res;
    for (int i = 1; i * i <= n; ++i){
        if (n % i == 0){
            res.push_back(i);
            if (i != n/i) res.push_back(n/i);
        }
    }
    return res;
}

int main(){
    int N;
    cin >> N;

    auto v = divisor(N);
    for (auto i : v){
        cout << i << endl;
    }
    return 0;
}