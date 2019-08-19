#include <iostream>
#include <vector>
#include<iomanip>
#include <algorithm>
using namespace std;

int N, K;
double INF = 100;
vector<double> W, P, X;

bool check(double x){
    for (int i = 0; i < N; ++i){
        X[i] = W[i] * (P[i] - x);
    }
    sort(X.begin(), X.end());
    double sum = 0;
    for (int i = N-K; i < N; ++i){
        sum += X[i];
    }
    return (sum < 0);
}

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        int w,p;
        cin >> w >> p;
        W.push_back(w);
        P.push_back(p);
        X.push_back(0);
    }

    double l = 0, m = 0, r = INF; 
    for (int i = 0; i < 100; ++i){
        m = (l + r) / 2;
        if (check(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << setprecision(15) << l << endl;
}