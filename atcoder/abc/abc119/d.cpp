#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int A, B, Q;
    cin >> A >> B >> Q;

	vector<long long> s(A), t(B);
    for (int i = 0; i < A; ++i){
    	cin >> s[i];
    }
    for (int i = 0; i < B; ++i){
    	cin >> t[i];
    }
    for (int i = 0; i < Q; ++i){

    	long long x;
    	cin >> x;
	    int sr = lower_bound(s.begin(), s.end(), x) - s.begin();
	    int sl = sr - 1;
	    int tr = lower_bound(t.begin(), t.end(), x) - t.begin();
	    int tl = tr - 1;

	    long long ret = 1LL << 60;
	    if (sr < A && tr < B) {
	      ret = min(ret, (s[sr] - x) + abs(s[sr] - t[tr]));
	      ret = min(ret, (t[tr] - x) + abs(s[sr] - t[tr]));
	    }
	    if (sl >= 0 && tl >= 0) {
	      ret = min(ret, (x - s[sl]) + abs(s[sl] - t[tl]));
	      ret = min(ret, (x - t[tl]) + abs(s[sl] - t[tl]));
	    }
	    if (sr < A && tl >= 0) {
	      ret = min(ret, (s[sr] - x) + abs(s[sr] - t[tl]));
	      ret = min(ret, (x - t[tl]) + abs(s[sr] - t[tl]));
	    }
	    if (sl >= 0 && tr < B) {
	      ret = min(ret, (x - s[sl]) + abs(s[sl] - t[tr]));
	      ret = min(ret, (t[tr] - x) + abs(s[sl] - t[tr]));
	    }
	    cout << ret << endl;
    }
}