#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18+10;
long long N, K;
vector<int> A, B;

long long count(long long X){
    long long num = 0;
    for (int i = 0; i < N; ++i){
        num += upper_bound(B.begin(), B.end(), X/A[i]) - B.begin();
    }
    return num;
}

int main(){

    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < N; ++i){
        int b;
        cin >> b;
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long l = 0, r = INF; 
    while(l + 1 < r){
        long long m = (l + r) / 2;
        if (count(m) >= K){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r << endl;
}