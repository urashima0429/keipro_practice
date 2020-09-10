#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 100010;
const int MAX_Q = 100010;
int N, Q, A[MAX_N];


// char T[MAX_Q];
// int L[MAX_Q], R[MAX_Q], X[MAX_Q];
// int main(){
//     cin >> N >> Q;
//     for (int i = 0; i < N; ++i){

//     } 
// }


// 1<<18-1 = 262143 >= 2 * 1e5
const int DAT_SIZE = 1<<18-1;
ll data[DAT_SIZE], datb[DAT_SIZE];

void add(int a, int b, int x, int k, int l, int r){
    if (a <= l && r <= b){
        data[k] += x;
    }
    else if(l < b && a < r){
        datb[k] += (min(b,r) - max(a,l)) * x;
        add(a, b, x, k *2 + 1, l, (l+r)/2);
        add(a, b, x, k *2 + 2, (l+r)/2, r);
    }
}