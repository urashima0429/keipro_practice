#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main(){
	int N, M;
	cin >> N >> M;
	vector<long long> v1;
	for (int i = 0; i < N; ++i){
		int a;
		cin >> a;
		v1.push_back(a);
	}
	sort(v1.begin(), v1.end(), greater<int>());

	vector<pair<long long, int>> v2;
	for (int i = 0; i < M; ++i){
		int b;
		long long c;
		cin >> b >> c;
		v2.push_back(make_pair(-c,b));
	}
	sort(v2.begin(), v2.end());

	long long ans = 0;
	int num = 0;
	int addr1 = 0;
	int addr2 = 0;
	while(num < N){
		if (v1[addr1] > -v2[addr2].first){
			ans += v1[addr1++];
			num += 1;
		}else{
			int l = min(N - num, v2[addr2].second);
			ans += -v2[addr2++].first * l;
			num += l;
		}
	}

    cout << ans << endl;
}
