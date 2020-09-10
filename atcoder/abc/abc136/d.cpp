#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string S;
    vector<int> ans;
    cin >> S;

    int l = 0, r = 0;
    for (int i = 0; i < S.length(); ++i){
        if (S[i] == 'R'){
            r++;
        }else{
            l++;
            if(i == S.length() - 1 || S[i+1] == 'R'){
                for (int j = 0; j < r-1; ++j) ans.push_back(0);
                if (abs(l-r) % 2 == 0){
                    int k = (l + r)/2;
                    ans.push_back(k);
                    ans.push_back(k);
                }else{
                	if (r % 2 == 1){
	                    ans.push_back((r+l)/2+1);
	                    ans.push_back((r+l)/2);
                	}else{
	                    ans.push_back((r+l)/2);
	                    ans.push_back((r+l)/2+1);
                	}
                }
                for (int j = 0; j < l-1; ++j) ans.push_back(0);
                l = 0; r = 0;
            }
        }
    }
    for (auto a : ans){
	    cout << a << " ";
    }cout << endl;
    return 0;
}