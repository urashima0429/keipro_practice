#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int N, cnt = 0;
    bool res = false;
    cin >> N;
    for (int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        if(a == b) {
            cnt++;
        }else {
            cnt = 0;
        }
        if(cnt >= 3) res = true;
    }

    cout << (res ? "Yes" : "No") << endl;
	return 0;
}