#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

// WA

int main() {
    int N, M;
    vector<int> A, B, C, W;
    vector<tuple<int,int,int,int>> VT;
    cin >> N >> M;
    VT.push_back(make_tuple(0,0,0,0));
    for (int i = 0; i < N; ++i){
        int a,b,c,w;
    	cin >> a >> b >> c >> w;
        VT.push_back(make_tuple(w,a,b,c));
    }

    sort(VT.begin(), VT.end());
    for (auto v : VT){
        W.push_back(get<0>(v));
        A.push_back(get<1>(v));
        B.push_back(get<2>(v));
        C.push_back(get<3>(v));
    }

    for (int i = 0; i < M; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        int a = upper_bound(A.begin(), A.end(), x) - A.begin();
        int b = upper_bound(B.begin(), B.end(), y) - B.begin();
        int c = upper_bound(C.begin(), C.end(), z) - C.begin();
        int w = min(min(a,b),c) - 1;
        cout << W[w] << endl;
    }
}