#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int MAX_N = 500 + 10;
	int N, K, A[MAX_N], sum = 0;;
	cin >> N >> K;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
        sum += A[i];
    }

    int ans = 1;
    for (int i = 1; i <= sum; ++i){
        if (sum % i == 0) {
            int t = sum / i;

            int difsum = 0;
            for (int j = 0; j < N; ++j){
                difsum += abs(A[j] - t);
            }            
            if (difsum <= K*2) {
                ans = max(ans, )
            }

        }
    }


    cout << 0 << endl;
    return 0;
}