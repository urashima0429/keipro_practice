#include <iostream>
using namespace std;


const long long MAX_N = 1e15;
const long long INF = 1e15;
long long N;

int main(){
    cin >> N;

    long long ans = 0;
    long long prev = N;
    for (long long i = 0; i < 5; ++i){
        long long input;
        cin >> input;
        ans += prev / input + 1;
        prev = min(input, prev);
    }
    cout << ans << endl;
    return 0;
}