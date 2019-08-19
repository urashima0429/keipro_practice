#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    const int MAX_N = 1e5+10;
    int N;
    string S[MAX_N];
    cin >> N;
    for (int i = 0; i < N; ++i){
        string s;
        cin >> s;
        int a[10];
        for (int j = 0; j < 10; ++j){
            a[j] = s[j]-0;
        }
        sort(a, a+10);
        for (int j = 0; j < 10; ++j){
            s[j] = a[j];
        }
        S[i] = s;
    }
    sort(S, S+N);

    long long ans = 0;
    long long sum = 1;
    string n, p = S[0];
    for (int i = 1; i < N; ++i){
        n = S[i];
        if(p == n){
            sum += 1;
        }else{
            ans += sum * (sum-1) / 2;
            sum = 1;
        }
        p = n;
    }
    ans += sum * (sum-1) / 2;


    cout << ans << endl;


}