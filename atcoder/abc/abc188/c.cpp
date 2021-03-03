#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N, A[1<<16];
    cin >> N;
    for (int i = 0; i < (1<<N); ++i){
        cin >> A[i];
    }

    int first_M = 0;
    int first_M_index = 0;
    for (int i = 0; i < (1<<(N-1)); ++i){
        if (first_M < A[i]){
            first_M = A[i];
            first_M_index = i+1;
        }
    }

    int second_M = 0;
    int second_M_index = 0;
    for (int i = (1<<(N-1)); i < (1<<N); ++i){
        if (second_M < A[i]){
            second_M = A[i];
            second_M_index = i+1;
        }
    }

    cout << (first_M > second_M ? second_M_index : first_M_index) << endl;
}
