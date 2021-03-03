#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N, M, m;
    vector<int> A;
    cin >> N >> M;
    m = N+10;
    A.push_back(0);
    A.push_back(N+1);
    for (int i = 0; i < M; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end());

    int prev = A[0];
    for (int i = 1; i <= M+1; ++i){
        int diff = A[i] - prev - 1;
        if (diff > 0){
            m = min(m, diff);
        }
        prev = A[i];
    }
    if (m == N+10){
        cout << 0 << endl;
    } else {
        int prev = A[0];
        int res = 0;
        for (int i = 1; i <= M+1; ++i){
            int diff = A[i] - prev - 1;
            if (diff > 0){
                res += (diff / m) + (diff % m ? 1 : 0);
            }
            prev = A[i];
        }
        cout << res << endl;
    }

    return 0;
}
