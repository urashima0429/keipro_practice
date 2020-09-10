#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int K, mod = 0, res = 0;
	cin >> K;
    while (true){
        mod = (mod*10 + 7) % K;
        res++;
        if (mod == 0) {
            break;
    }
        if (res > K) {
            res = -1;
            break;
        }
    }
    cout << res << endl; 
	return 0;
}