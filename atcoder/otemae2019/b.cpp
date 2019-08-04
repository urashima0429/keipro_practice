#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N, K;
    vector<int> X;
    cin >> M >> N >> K;
    int a;
    for (int i = 0; i < N; ++i){
    	cin >> a;
    	X.push_back(a-1);
    }
    sort(X.begin(), X.end());

    int ans = 0;
    for(int i = 0; i < M; ++i){
	    int sum = upper_bound(X.begin(), X.end(), i) - lower_bound(X.begin(), X.end(), i);
	    for (int j = 1; j <= K; ++j){
	    	if (binary_search(X.begin(), X.end(), i+j)
	    	|| 	binary_search(X.begin(), X.end(), i-j)){
	    		sum++;
	    	}
	    }
	    ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}