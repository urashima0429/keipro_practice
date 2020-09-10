#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18+10;
int N;
vector<long long> H, S;
vector<double> T;

bool check(long long X){
    for (int i = 0; i < N; ++i){
        T[i] = (double)(X-H[i])/S[i];
    }
    sort(T.begin(), T.end());
    for (int i = 0; i < N; ++i){
        if(T[i] < i) return false;
    }
    return true;
}

int main(){

    cin >> N;
    for (int i = 0; i < N; ++i){
        int h, s;
        cin >> h >> s;
        H.push_back(h);
        S.push_back(s);
        T.push_back(0);
    }

    long long l = 0, r = INF; 
    while(l + 1 < r){
        long long m = (l + r) / 2;
        if (check(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << endl;
}