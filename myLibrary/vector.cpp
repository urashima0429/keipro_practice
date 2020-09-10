#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    // 外延表記での初期化
    vector<int> v1 = {1,2,3,4};

    // 要素数と初期値を指定して初期化 
    vector<int> v2(3, 5); // {5,5,5}

    // 複製
    vector<int> v3(v1); // {1,2,3,4}

    // 二次元可変長配列
    std::vector<std::vector<int>> vv;




    vector<int> v = {1,2,3,4};
    
    // vectorが空かどうかを返す
    v.empty(); // {1,2,3,4} => false

    // vectorのサイズを返す
    v.size(); // {1,2,3,4} => 4

    // 最後の要素への参照を返す
    v.front(); // = v[0]

    // 最後の要素への参照を返す
    v.back(); // = v[v.size() - 1]

    // 最初の要素のイテレーターを返す
    v.begin();

    // 最後の要素の次のイテレーターを返す
    v.end();

    // 末尾に要素を追加する O(1)
    v.push_back(5); // {1,2,3,4} => {1,2,3,4,5}

    // 任意のindexに要素を挿入する O(N)
    v.insert(v.begin() + 4, 7); // {1,2,3,4,5} => {1,2,3,4,7,5}

    // 末尾の要素を削除する O(1)
    v.pop_back(); //末尾 {1,2,3,4,7,5} => {1,2,3,4,7}

    // 任意のindexを削除する O(N)
    v.erase(v.begin() + 2); //{1,2,3,4,7} => {1,2,4,7}

    // 任意の範囲を削除する O(N)
    v.erase(v.begin() + 1, v.begin() + 3); //{1,2,4,7} => {1,7}
    



    // 条件ベースforループ
    // イテレーターでアクセス
    for(auto itr = v.begin(); itr != v.end(); ++itr) {
        cout << *itr << endl;   //{1,7}
    }
    // 配列風にアクセス
    for(int i = 0; i != v.size(); ++i) {
        cout << v[i] << endl;   //{1,7}
    }


    // 範囲ベースforループ(全要素に対して行うときはスマート) 
    for (auto _v : v){
        cout << _v << endl;     //{1,7}
    }

    // イテレーターで指定した範囲内の指定要素の個数をカウント
    count(v.begin(), v.end(), 1); // 1

    // イテレーターで指定した範囲内で最初の指定要素のイテレーター
    find(v.begin(), v.end(), 1);

    // need #include <algorithm>
    // イテレーターで指定した範囲内を昇順ソート
    sort(v.begin(), v.end());

    // イテレーターで指定した範囲内を降順ソート
    sort(v.begin(), v.end(), greater<int>());

    // イテレーターで指定した範囲内の要素を逆順にする
    reverse(v.begin(), v.end());

    vector<pair<int, int>> pv;
    pv.push_back(make_pair(4,5));
    pv.push_back(make_pair(1,3));
    pv.push_back(make_pair(0,9));
    
    // pairはfirstの値でソートされる
    sort(pv.begin(), pv.end());
    for (auto p : pv) cout << p.first << p.second << endl; 
    // 0 9
    // 1 3 
    // 4 5


}