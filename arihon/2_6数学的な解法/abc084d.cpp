#include <iostream>
using namespace std;

const int MAX_N = 1e5+10;
int prime[MAX_N];
bool is_prime[MAX_N];
bool like_2017[MAX_N];
int sum[MAX_N];

int sieve(int n){
	int p = 0;
	for (int i = 0; i <= n; ++i) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++){
		if (is_prime[i]){
			prime[p++] = i;
			for (int j = 2*i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return p;
}

int main(){
    sieve(1e5);
    for (int i = 1; i < 1e5; i+=2){
    	like_2017[i] = is_prime[i] && is_prime[(i+1)/2];
    }
    
    int s = 0;
    for (int i = 1; i <= 1e5; ++i){
    	if(like_2017[i]) s++;
    	sum[i] = s;
    }
    

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i){
    	int l,r;
    	cin >> l >> r;
    	cout << sum[r] - sum[l-1] << endl;;
    }
}