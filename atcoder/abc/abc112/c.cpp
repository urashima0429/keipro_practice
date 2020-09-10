#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){

    int N;
    vector<pair<int, pair<int, int>>> v;
    cin >> N;
    for (int i = 0; i < N; ++i){
        int x,y,h;
        cin >> x >> y >> h;
        v.push_back(make_pair(h, make_pair(x,y)));
    }
    sort(v.begin(), v.end());
    
    for (int cx = 0; cx <= 100; ++cx){
        for (int cy = 0; cy <= 100; ++cy){
            bool check = true;
            int ch = v[N-1].first + abs(v[N-1].second.first - cx) + abs(v[N-1].second.second - cy);
            for (int i = 0; i < N-1; ++i){
                int h = v[i].first;
                int x = v[i].second.first;
                int y = v[i].second.second;
                if (h != max(0, ch - abs(x - cx) - abs(y - cy))){
                    check = false;
                    break;
                }
            }
            if (check) {
                cout << cx << " " << cy << " " << ch << endl;
            }
        }
    }
    
    return 0;
}

