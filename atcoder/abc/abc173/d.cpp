#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int N;
    vector<int> v;
    priority_queue<int> q;
	cin >> N;
    for (int i = 0; i < N; ++i){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<int>());

    ll sum = 0;
    q.push(v[0]);
    for (int i = 1; i < N; ++i){
        sum += q.top();
        q.pop();
        q.push(v[i]);
        q.push(v[i]);
    }

    cout << sum << endl;
	return 0;
}