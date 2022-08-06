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
constexpr ll M = 4e5+5;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pll> snek;
    for (ll i = 0, row = 0, idx = 0; i < M; i++) {
        snek.push_back({row, idx});
        if (i % 2 == 1) idx++;
        else row = (row+1)%2;
    }

    int T; cin >> T; while (T--) {
        ll m; cin >> m;
        vector<vector<ll>> a(2, vector<ll>(m));
        for (ll i = 0; i < 2; i++) for (ll j = 0; j < m; j++) cin >> a[i][j];
        a[0][0] = -1;

        auto checkHook = [&](ll row, ll idx, ll x) {
            for (ll i = idx; i < m; i++) if (a[row][i] >= x++) return false;
            row = (row+1)%2;
            for (ll i = m-1; i >= idx; i--) if (a[row][i] >= x++) return false;
            return true;
        };

        auto check = [&](ll x) {
            for (ll i = 0; i < 2*m; i++) {
#define row first
#define idx second
                if (a[snek[i].row][snek[i].idx] >= x) {
                    if (i%2 == 0) {
                        if (checkHook(snek[i].row, snek[i].idx, x)) return true;
                        if (i - 2 >= 0 && checkHook(snek[i-2].row, snek[i-2].idx, x-2)) return true;
                    } else {
                        if (checkHook(snek[i-1].row, snek[i-1].idx, x-1)) return true;
                    }
                    return false;
                }
                x++;
#undef row
#undef idx
            }
            return true;
        };

        ll t = 2e9;
        for (ll i = 2e9; i; i >>= 1) {
            while (t - i >= 0 && check(t-i)) t -= i;
        }

        cout << t + 2*m-1 << endl;

    }    
    
    return 0;
}

