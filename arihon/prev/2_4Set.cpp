#include <iostream>
#include <set>
using namespace std;

// 順序付集合
// 重複可能なものはmultiset

int main(){
    set<int> s;
  
    // add 
    s.insert(1);
    s.insert(3);
    s.insert(5);

    // search1
    set<int>::iterator ite;
    ite = s.find(1);
    if (ite == s.end()) puts("not found");

    // search2
    if (s.count(3) != 0) puts("found");

    // delete
    s.erase(3);

    // foreach
    for (ite = s.begin(); ite != s.end(); ++ite){
        cout << *ite << endl;
    }
}