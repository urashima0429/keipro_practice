#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    const int MAX_N = 1e5 + 10;
    int N;
    vector<int> A;
    cin >> N;
    for (int i = 0; i < N; ++i){
        A.push_back(0);
    }

    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        int b = upper_bound(A, A+N) - A;
        cout << b << endl;
    }
}