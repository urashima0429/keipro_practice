#include <iostream>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}


int main() {
    bool yes = false;
	int N, X[110], Y[110];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < N; ++i){
        for (int j = i+1; j < N; ++j){
            for (int k = j+1; k < N; ++k){
                int v0x = X[j] - X[i];
                int v0y = Y[j] - Y[i];

                if (v0y < 0) {
                    v0x = -v0x;
                    v0y = -v0y;
                }
                int g0 = gcd(v0x, v0y);
                
                int v1x = X[k] - X[i];
                int v1y = Y[k] - Y[i];
                if (v1y < 0) {
                    v1x = -v1x;
                    v1y = -v1y;
                }
                int g1 = gcd(v1x, v1y);
                
                if (v0x / g0 == v1x / g1 && v0y / g0 == v1y / g1){
                    yes = true;
                    // cout << "i:" << i << endl;
                    // cout << "j:" << j << endl;
                    // cout << "k:" << k << endl;
                    // cout << "v0x:" << v0x << endl;
                    // cout << "v0y:" << v0y << endl;
                    // cout << "v1x:" << v1x << endl;
                    // cout << "v1y:" << v1y << endl;
                    // cout << "g0:" << g0 << endl;
                    // cout << "g1:" << g1 << endl;

                }
            }
        }
    }
    if (yes){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
	return 0;
}