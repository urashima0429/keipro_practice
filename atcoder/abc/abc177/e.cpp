#include <iostream> 
using namespace std;
typedef long long ll;

const int MAX_A = 1000010;
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

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N, g;
    bool is_pairwise = true, mod[1000010];
    for (int i = 2; i < 1000000; ++i) mod[i] = false;
    sieve(1000000);
    
    cin >> N;
    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        if (i == 0){
            g = a;
        }else{
            g = gcd(a, g);
        }

        while (a != 1){
            int t = divisor[a];
            if (mod[t]) is_pairwise = false;
            mod[t] = true;
            while(a%t==0) a/=t;
        }
    }

    if (is_pairwise){
        cout << "pairwise coprime" << endl;
    } else if (g == 1){
        cout << "setwise coprime" << endl;
    }else {
        cout << "not coprime" << endl;
    }
    return 0;
}