#include <iostream>
#include <algorithm>
using namespace std;

int N, p[10];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i){
      cin >> p[i];
    }

    sort(p, p + N);

    int ans = p[N-1]/2;
    for (int i = 0; i < N-1; ++i){
        ans += p[i];
    }
  cout << ans << endl;
}