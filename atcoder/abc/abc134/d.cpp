#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    
    int N;
    bool A[200010], C[200010];
    vector<int> B;
    cin >> N;
    for (int i = 1; i <= N; ++i){
        bool a;
        cin >> a;
        A[i] = (a>0?true:false);
    }
    int sum = 0;
    for (int i = N; i >= 1; --i){
        int j = i;
        bool c = A[i];
        while (j + i <= N){
            j += i;
            c ^= C[j];
        }
        C[i] = c;
        if (c) {
            sum++;
            B.push_back(i);
        }
    }
    
    cout << sum << endl;
    for (auto b : B){
        cout << b <<endl;
    }

}


