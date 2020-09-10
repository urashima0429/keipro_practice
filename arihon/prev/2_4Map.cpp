#include <iostream>
#include <map>
#include <string>
using namespace std;

// key -> value
// 重複可能なものはmultimap

int main(){
    map<int, const char*> m;

    // add 
    m.insert(make_pair(1,"ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED";

    // search1
    map<int, const char*>::iterator ite;
    ite = m.find(1);
    puts(ite->second);

    ite = m.find(2);
    if (ite == m.end()) puts("not found");

    puts(m[10]);

    m.erase(10);

    for (ite = m.begin(); ite != m.end(); ++ite){
        cout << ite->first << ite->second << endl;
    }
}