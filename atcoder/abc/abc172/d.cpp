#include <iostream>
using namespace std;
typedef long long ll;


const int MAX_A = 10000010;
int divisor[MAX_A];

int sieve(int n){
    for (int i = 2; i <= n; ++i) divisor[i] = i;
	for (int i = 2; i <= n; i++){
		if (divisor[i] == i){
			for (int j = i+i; j <= n; j += i) {
                divisor[j] = i;
			}
		}
	}
    return 0;
}


int main() {
    ll N;
    cin >> N;
    sieve(N);

    ll sum = 0;
    for (ll i = 1; i <= N; ++i){

        ll res = 1, a = i;
        while (a != 1){

            int k = 1;
            int d = divisor[a];
            while(a%d==0) {
                a/=d;
                k++;
            }
            res *= k;
        }
        sum += i * res; 
    }

    cout << sum << endl;
	return 0;
}