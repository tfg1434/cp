#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }

int n;
const int max_n = 16;
int a[max_n], b[max_n];
bool dp[1 << max_n][max_n];

void solve() {
    cin >> n;
    memset(dp, 0, sizeof dp);

    string inp_a[n], inp_b[n];
    {
        map<string, int> m_a, m_b;
        for (int i = 0; i < n; i++) {
            cin >> inp_a[i] >> inp_b[i];
            if (!m_a.count(inp_a[i]))
                m_a[inp_a[i]] = m_a.size();
            if (!m_b.count(inp_b[i]))
                m_b[inp_b[i]] = m_b.size();
            a[i] = m_a[inp_a[i]];
            b[i] = m_b[inp_b[i]];
        }
    }

    for (int i = 0; i < n; i++) dp[1 << i][i] = true;
    for (int msk = 0; msk < 1<<n; msk++) {
        for (int last = 0; last < n; last++) {
            for (int j = 0; j < n; j++) if (!(msk & (1 << j)) && (a[j] == a[last] || b[j] == b[last])) {
                dp[msk | (1 << j)][j] |= dp[msk][last];
            }
        }
    }

    int ans = 0;
    for (int msk = 0; msk < 1<<n; msk++) {
        for (int last = 0; last < n; last++) {
            if (dp[msk][last]) ans = max(ans, __builtin_popcount(msk));
        }
    }
    cout << n-ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
