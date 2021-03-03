#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N, C;
    vector<tuple<int,int,int>> v;
    cin >> N >> C;
    for (int i = 0; i < N; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back(make_tuple(a,b,c));
    }

    sort(v.begin(), v.end());

    ll cost = 0;
    for (auto t : v){
        cout << get<0>(t) << ":" << get<1>(t) << ":" << get<2>(t) << endl;
    }


}
