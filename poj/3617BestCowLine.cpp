#include <iostream>
#include <string>
using namespace std;

// 6 A C D B C B

int main(){

    // input
    int N;
    char S[2000+1];
    char T[2000+1];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> S[i];
    }

    int a = 0, b = N-1;

    int t_index = 0;
    while (a <= b){

        bool left;
        for (int i = 0; a + i <= b; ++i){
            if (S[a+i] < S[b-i]){
                left = true;
                break;
            }else if (S[a+i] > S[b-i]){
                left = false;
                break;
            }   
        }
        if (left) T[t_index++] = S[a++];
        else      T[t_index++] = S[b--];
    }

    for (int i = 0; i < N/80 + 1; ++i){
        char tmp[80];
        for (int j = 0; j < 80; ++j){
            if (80*i+j >= N) break;
            tmp[j] = T[80*i+j];
        }
        cout << tmp << endl;
    }



}