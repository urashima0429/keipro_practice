#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int ctoi(char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

int main(){
    string S;
    bool yes = false;
    vector<int> num(10, 0);
    
    cin >> S;
    for (int i = 0; i < S.length(); ++i){
        num[ctoi(S[i])]++;
    }
    if (S.length() == 1 && num[8] == 1){
        yes = true;
    } else if (S.length() == 2){
        for (int i = 0; i < 10; ++i){
            for (int j = i; j < 10; ++j){
                if (
                    (
                        false
                        || i == j && num[i] >= 2
                        || i != j && num[i] >= 1 && num[j] >= 1
                    )
                    &&
                    (
                        (10 * i + j) % 8 == 0
                        || (10 * j + i) % 8 == 0
                    )
                ){
                    yes = true;
                }
            }
        }
    } else if (S.length() >= 3){
        for (int i = 1; i < 10; ++i){
            for (int j = i; j < 10; ++j){
                for (int k = j; k < 10; ++k){
                    if (
                        (  
                            false
                            || i == j && j == k && num[i] >= 3
                            || i == j && j != k && num[i] >= 2 && num[k] >= 1
                            || j == k && k != i && num[j] >= 2 && num[i] >= 1
                            || k == i && i != j && num[k] >= 2 && num[j] >= 1
                            || i != j && j != k && k != i && num[i] >= 1 && num[j] >= 1 && num[k] >= 1 
                        )
                        &&
                        (
                            (100 * i + 10 * j + k) % 8 == 0
                            || (100 * i + 10 * k + j) % 8 == 0
                            || (100 * j + 10 * i + k) % 8 == 0
                            || (100 * j + 10 * k + i) % 8 == 0
                            || (100 * k + 10 * i + j) % 8 == 0
                            || (100 * k + 10 * j + i) % 8 == 0
                        )               
                    ){
                        yes = true;
                    }

                }
            }
        }

    }

    if (yes){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
