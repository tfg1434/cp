#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));

        ll ne = -INFF, se = -INFF, sw = -INFF, nw = -INFF;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] != 'B') continue;

                nw = max(nw, -i-j); ne = max(ne, -i+j);
                se = max(se, i+j); sw = max(sw, i-j);
            }
        }

        ll mn = INFF;
        pll ans = {-1, -1};
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                ll res = max({ i + j + nw, -i+j+sw, i-j+ne, -i-j+se });
                if (res < mn) {
                    mn = res;
                    ans = {i, j};
                }
            }
        }

        cout << ans.first+1 << ' ' << ans.second+1 << '\n';
    }    
    
    return 0;
}

