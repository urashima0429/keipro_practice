#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N;
    ll t = 1;
    ll f = 1;
    cin >> N;
    for (int i = 0; i < N; ++i){
        string s;
        cin >> s;
        if(s == "AND"){
            f = t + 2*f;
        }else{
            t = f + 2*t;
        }
    }
    cout << t << endl;
}
