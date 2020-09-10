#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;
int N, M;
vector<pair<int, int>> a[MAX_N + 10];
vector<pair<int, string>> b;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i){
    	int p, y;
    	cin >> p >> y;
    	a[p].push_back(make_pair(y,i));
    }
	
	for (int i = 1; i <= N; ++i){
    	sort(a[i].begin(), a[i].end());
    }

    ios::fmtflags curret_flag = cout.flags();

	for (int i = 1; i <= N; ++i){
		int index = 1;
		for (auto ite = a[i].begin(); ite != a[i].end(); ++ite){
		    ostringstream p, q;
    		p << std::setw(6) << std::setfill('0') << i;
    		q << std::setw(6) << std::setfill('0') << index++;
    		pair<int,int> tmp = *ite;
    		b.push_back(make_pair(tmp.second, p.str() + q.str()));
		}
    }

    cout.flags(curret_flag);

    sort(b.begin(), b.end());
	for (auto ite = b.begin(); ite != b.end(); ++ite){
    	pair<int,string> tmp = *ite;
    	cout << tmp.second << endl;
	}
}