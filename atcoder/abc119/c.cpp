#include <iostream>
#include <algorithm>
using namespace std;

int N, A, B, C, L[10], INF = 1e9;

int rec(int i, int a, int b, int c){
	if (i == N){
		if (a != 0 && b != 0 && c != 0)	{
			return abs(A-a) + abs(B-b) + abs(C-c);
		}else{
			return INF;			
		}
	}
	return min({
		rec(i + 1, a, b, c),
		rec(i + 1, a + L[i], b, c) + (a == 0 ? 0 :10),
		rec(i + 1, a, b + L[i], c) + (b == 0 ? 0 :10),
		rec(i + 1, a, b, c + L[i]) + (c == 0 ? 0 :10)
	});
}

int main() {

    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; ++i){
    	cin >> L[i];
    }

    cout << rec(0,0,0,0) << endl;
}