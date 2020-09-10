#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int N, L[110];
	cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> L[i];
    }

    int res = 0;
    for (int i = 0; i < N-2; ++i){
        for (int j = i+1; j < N-1; ++j){
            for (int k = j+1; k < N; ++k){
                int a = L[i], b = L[j], c = L[k];
                if (a != b && b != c && c != a && a+b>c && b+c>a && c+a>b){
                    res++;
                }
            }   
        }
    }

    cout << res << endl; 
	return 0;
}