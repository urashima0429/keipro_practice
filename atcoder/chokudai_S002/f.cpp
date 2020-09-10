#include <iostream>
#include <set>
using namespace std;


struct edge{int a, b; };

int main(){
    int N;
    cin >> N;
    long long ans = 0;
    set<edge> s;
    set<edge>::iterator ite;

    for (int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a,b);
        s.insert(edge{a, b});
        
    }
    cout << ans << endl;
    return 0;
}