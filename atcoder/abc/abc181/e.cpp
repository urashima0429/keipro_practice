#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
typedef long long ll;

int main() {
    int N, M, H[200010];
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        cin >> H[i];        
    }
    sort(H, H+N);

    for (int i = 0; i < N-1; ++i){
        cout << H[i+1] - H[i] << endl;;        
    }
    
    // cout << sum << endl;
    return 0;
}