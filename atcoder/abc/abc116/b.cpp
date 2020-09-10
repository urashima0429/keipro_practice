#include <iostream>
#include <set>
using namespace std;

int s;

int main() {
    cin >> s;

    set<int> as;
    int ans = 1;

    int a = s;
    while(true){
        if(as.count(a) == 0){
            as.insert(a);
            if(a % 2 == 0){
                a = a / 2;
            }else{
                a = 3 * a + 1;
            }
        }else{
            break;
        }
        ans++;
    }

    cout << ans << endl;
}