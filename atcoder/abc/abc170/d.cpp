#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int N, res = 0;
bool check[1000010];

void insert(int n){
    for (int i = n; i <= 1000000; i += n){
        check[i] = true;
    }
}

int main(){
    for (int i = 0; i <= 1000000; ++i) check[i] = false;
    vector<int> v, v2;
    cin >> N;
    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());


    for (int i = 1; i < N; ++i){
        if (v[i-1] == v[i] && !check[v[i]]) insert(v[i]);
    }    

    for (int i = 0; i < N; ++i){
        int a = v[i];
        if (!check[a]) {
            res++;
            insert(a);
        }
    }
    cout << res << endl;
    return 0;
}