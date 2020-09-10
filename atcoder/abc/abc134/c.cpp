#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }

    vector<int> v(A);
    sort(v.begin(), v.end());
    if (v[N-2] == v[N-1]){
        for (int i = 0; i < N; ++i){
            cout << v[N-1] << endl;
        }
    }else{
        for (int i = 0; i < N; ++i){
            if (A[i] == v[N-1]){
                cout << v[N-2] << endl;
            }else{
                cout << v[N-1] << endl;
            }
        }
            
    }


    return 0;
}