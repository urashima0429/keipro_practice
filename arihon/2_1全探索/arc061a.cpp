#include <iostream>
#include <string>
using namespace std;

string S;
int d[12];

long long dfs(int i, long long s, long long b){
    if (i == S.length()) return s + b;
    return 
        dfs(i+1, s + b, d[i]) 
        + dfs(i+1, s, 10*b+d[i]);
}

int main() {
    cin >> S;
    for (int i = 0; i < S.length(); ++i){
        d[i] = S[i] - 48;
    }
    cout << dfs(1, 0, d[0]) << endl;
    return 0;
}