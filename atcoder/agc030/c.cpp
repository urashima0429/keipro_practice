#include <iostream>
using namespace std;

long long N;

int rec(long long i, int t, int f, int s){
    if (i > N) return 0;
    int self = (t >= 1 && f >= 1 && s >= 1) ? 1 : 0;
    return rec(10 * i + 3, t+1, f, s) 
         + rec(10 * i + 5, t, f+1, s) 
         + rec(10 * i + 7, t, f, s+1) 
         + self;
}

int main() {
    cin >> N;
    cout << rec(0LL, 0, 0, 0) << endl;
}