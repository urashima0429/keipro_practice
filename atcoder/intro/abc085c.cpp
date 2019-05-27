#include <iostream>
using namespace std;

int main() {
    int N;
    int Y;
	int x = -1, y = -1, z = -1;

	cin >> N >> Y;

	for (int i = 0; i <= N; ++i){
		for (int j = 0; j <= N - i; ++j){
			int k = N - i - j;
			if (10000*i + 5000*j + 1000*k == Y){
				x = i;
				y = j;
				z = k;
			}
		}
	}

	cout << x << " " << y << " " << z << endl;
}