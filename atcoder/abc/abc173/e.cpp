#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    ll MOD = 1e9+7, prd = 1;
    vector<ll> pos, neg;
	cin >> N >> K;
    for (int i = 0; i < N; ++i){
        ll t;
        cin >> t;
        if (t < 0) {
            neg.push_back(t);
        } else {
            pos.push_back(t);
        }
    }

    if (K == N){
        // 自明
        for (int i = 0; i < pos.size(); ++i){
            prd = prd * pos[i] % MOD;
        }
        for (int i = 0; i < neg.size(); ++i){
            prd = prd * neg[i] % MOD;
        }
    } else {
        // K < N
        if (K%2 == 1){
            if (N == neg.size()){
                // うまく選んでも負になってしまうので
                // 絶対値が小さくなるように選ぶ
                sort(neg.begin(), neg.end());
                for (int i = 0; i < K; ++i){
                    prd = prd * neg[N-i-1] % MOD;
                }
            } else {
                // 正の数を奇数個、負の数を偶数個選べば必ず正にできる
                sort(pos.begin(), pos.end());
                sort(neg.begin(), neg.end());
                int k = K, n_i = 0, p_i = pos.size()-1;

                // 一番大きい整数を予約しておく
                prd = prd * pos[p_i] % MOD;
                k--;
                p_i--;

                while(k >= 2){
                    if (neg.size() < 2) {
                        prd = prd * pos[p_i-1] % MOD;
                        prd = prd * pos[p_i] % MOD;
                        p_i -= 2;
                        k -= 2;
                    } else if (pos.size() < 2){
                        prd = prd * neg[n_i] % MOD;
                        prd = prd * neg[n_i+1] % MOD;
                        n_i += 2;
                        k -= 2;
                    } else if (neg[n_i] * neg[n_i+1] <= pos[p_i-1] * pos[p_i]){
                        prd = prd * pos[p_i-1] % MOD;
                        prd = prd * pos[p_i] % MOD;
                        p_i -= 2;
                        k -= 2;
                    } else {
                        prd = prd * neg[n_i] % MOD;
                        prd = prd * neg[n_i+1] % MOD;
                        n_i += 2;
                        k -= 2;
                    }
                }
            }
        }else{
            // 正の数を偶数個、負の数を偶数個選べば必ず正にできる
            sort(pos.begin(), pos.end());
            sort(neg.begin(), neg.end());
            int k = K, n_i = 0, p_i = pos.size()-1;
            while(k >= 2){
                if (neg.size() < 2) {
                    prd = prd * pos[p_i-1] % MOD;
                    prd = prd * pos[p_i] % MOD;
                    p_i -= 2;
                    k -= 2;
                } else if (pos.size() < 2){
                    prd = prd * neg[n_i] % MOD;
                    prd = prd * neg[n_i+1] % MOD;
                    n_i += 2;
                    k -= 2;
                } else if (neg[n_i] * neg[n_i+1] <= pos[p_i-1] * pos[p_i]){
                    prd = prd * pos[p_i-1] % MOD;
                    prd = prd * pos[p_i] % MOD;
                    p_i -= 2;
                    k -= 2;
                } else {
                    prd = prd * neg[n_i] % MOD;
                    prd = prd * neg[n_i+1] % MOD;
                    n_i += 2;
                    k -= 2;
                }
            }
        }
    }
    cout << (prd + MOD) % MOD << endl; 
	return 0;
}