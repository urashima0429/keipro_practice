#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// 可変長配列

int max(std::vector<int> v)
{
    int maxVal = INT_MIN;
    for(int i = 0; i < (int)v.size(); ++i) {
        if( v[i] > maxVal )
            maxVal = v[i];
    }
    return maxVal;
}

int max(std::vector<int> &v)
{
    int maxVal = INT_MIN;
    for(int i = 0; i < (int)v.size(); ++i) {
        if( v[i] > maxVal )
            maxVal = v[i];
    }
    return maxVal;
}

int main(){


    // 要素数100, 初期値5 
    // vector<int> v(100, 0);
    vector<int> v = {1,2,3,4};

    // copy
    // vector<int> v(v_int2);

    // 二次元配列
    std::vector<std::vector<int>> vv{{1, 2, 3}, {4, 5, 6}};

    // add
    v.push_back(5); //末尾 {1,2,3,4,5}
    v.insert(v.begin() + 4, 7); //任意 {1,2,3,4,7,5}

    // delete
    v.pop_back(); //末尾 {1,2,3,4,7}
    v.erase(v.begin() + 2); //任意 {1,2,4,7}
    v.erase(v.begin() + 1, v.begin() + 3); //{1,7}
    
    // other
    v.empty();
    v.size();

    // イテレータとは抽象化されたポインタのことである。 
    // イテレータはコンテナの要素を指し、
    // *演算子でイテレータが指す要素を参照・変更することができ、 
    // インクリメント・デクリメントで次・前の要素に移動することができる。 

    vector<int>::iterator itr;
    for(itr = v.begin(); itr != v.end(); ++itr) {
        cout << *itr << endl;
    }

    for(int i = 0; i != v.size(); ++i) {
        cout << v[i] << endl;
    }

    // count
    count(v.begin(), v.end(), 1);

    // find
    find(v.begin(), v.end(), 1);

    // sum
    // need #include <numeric>
    int a = accumulate(v.begin(), v.end(), 0);
    cout << a << endl;

    // sort
    // need #include <algorithm>
    sort(v.begin(), v.end());

    // reverse
    reverse(v.begin(), v.end());
}