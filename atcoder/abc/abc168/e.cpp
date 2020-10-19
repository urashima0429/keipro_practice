#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(){
    int N;
    vector<tuple<double, ll, ll> > p, n;
    cin >> N;
    for (int i = 0; i < N; ++i){
        ll a, b;
        cin >> a >> b;
        if (a*b>=0) {
            p.push_back(make_tuple((double)a/double(b), a, b));
        }else{
            n.push_back(make_tuple((double)a/double(b), a, b));
        }
    }



    for (int i = 0; i < N; ++i){
        cout << get<0>(iwashi[i]) << endl;
    }

    return 0;
}