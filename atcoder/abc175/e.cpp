#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int N, K;
double A[200000 + 10];

bool check(double l){
    int res = 0;
    for (int i = 0; i < N; ++i){
        res += (int)(ceil(A[i] / l)) - 1;
    }
    return res <= K;
}

int main() {
	cin >> N >> K;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }

    double l = 0.0, m, r = 1e9+10;
    for (int i = 0; i < 1000; ++i){
        m = (l + r) / 2;
        if (check(m)){
            r = m;
        }else{
            l = m;
        }
    }

    cout << (int)ceil(m) << endl;     
	return 0;
}