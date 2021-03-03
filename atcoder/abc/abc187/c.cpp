#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    string sat = "satisfiable";
    int N;
    map<string, int> m;
    cin >> N;

    for (int i = 0; i < N; ++i){
        string s, key;
        cin >> s;
        if (s[0] == '!'){
            key = s.substr(1);
            if (m[key] == 1){
                sat = key;
                break;
            }else{
                m[key] = -1;
            }
        } else{
            key = s.substr(0);
            if (m[key] == -1){
                sat = key;
                break;
            }else{
                m[key] = 1;
            }
        }
    }
    
    cout << sat << endl;
    return 0;
}
