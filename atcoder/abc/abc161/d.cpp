#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main(){
    int K;
    queue<ll> q;
    cin >> K;

    for (ll i = 1; i < 10; ++i){
        q.push(i);
    }
    for (int i = 1; i < K; ++i){
        ll t = q.front(); q.pop();
        if (t % 10 != 0) {
            q.push(t * 10 + t % 10 - 1);
        } 
        q.push(t * 10 + t % 10);
        if (t % 10 != 9) {
            q.push(t * 10 + t % 10 + 1);
        }
    }

    cout << q.front() << endl;
    return 0;
}