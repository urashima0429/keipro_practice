#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    string res = ""; 
    cin >> N;
    while(N){
        res = (char)( (N-1) % 26 + 'a') + res;
        N = (N-1) / 26;
    }
 
    cout << res << endl;
}