#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int X, Y, Z, K;
    ll a;
    vector<ll> A, B, C, D, E, F;
    cin >> X >> Y >> Z >> K;
    for(int i = 0; i < X; ++i){
        cin >> a;
        A.push_back(a);        
    }
    for(int i = 0; i < Y; ++i){
        cin >> a;
        B.push_back(a);        
    }
    for(int i = 0; i < Z; ++i){
        cin >> a;
        C.push_back(a);        
    }
    
    for( auto a : A ){
        for ( auto b : B){
            D.push_back(a+b);
        }
    }
    sort(D.begin(), D.end(), greater<ll>());
    for (int i = 0; i < min(K, X*Y); ++i){
        E.push_back(D[i]);
    }
    
    
    for( auto e : E ){
        for ( auto c : C){
            F.push_back(e+c);
        }
    }
    sort(F.begin(), F.end(), greater<ll>());
    for (int i = 0; i < K; ++i){
        cout << F[i] << endl;
    }
}

