#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	int N;
    string S;
	cin >> N >> S;

    int r_sum = 0;
    for (int i = 0; i < N; ++i){
        if (S[i] == 'R') r_sum++;
    }
    int res = 0;
    for (int i = 0; i < r_sum; ++i){
        if (S[i] != 'R') res++;
    }

    cout << res << endl; 
	return 0;
}