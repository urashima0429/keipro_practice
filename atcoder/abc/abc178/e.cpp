#include <iostream> 
using namespace std;
typedef long long ll;

int main() {
    const ll INF = 1e9+10;
    ll N, m_z = INF, M_z = -INF, m_w = INF, M_w = -INF;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        ll x, y, z, w;
        cin >> x >> y;
        z = x + y;
        w = x - y;
        m_z = min(m_z, z);
        M_z = max(M_z, z);
        m_w = min(m_w, w);
        M_w = max(M_w, w);
    }

    cout << max(M_z - m_z, M_w - m_w) << endl;
    return 0;
}