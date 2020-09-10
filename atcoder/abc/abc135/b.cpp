#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
int main() {
    int N;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; ++i){
    	int a;
    	cin >> a;
    	v.push_back(a); 
    }

    vector<int> v2(v);
    sort(v2.begin(), v2.end());

    int sum = 0;
    for (int i = 0; i < N; ++i){
    	if (v[i] != v2[i]) sum++;
    }
    if (sum <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;   
}