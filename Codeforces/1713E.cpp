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

constexpr ll SZ = 2e5 + 5;
ll par[SZ], sze[SZ];
void make(ll v) {
    par[v] = v;
}
ll find(ll v) {
    if (v < 0) return -find(-v);
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}
void join(ll a, ll b) {
    a = find(a);
    b = find(b);

    if (abs(a) != abs(b)) {
        if (a > 0) par[a] = b;
        else par[-a] = -b;
    }
}

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<vector<ll>> a(n+1, vector<ll> (n+1));
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        iota(par+1, par+n+1, 1);

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (a[i][j] < a[j][i]) join(i, j);
                if (a[i][j] > a[j][i]) join(i, -j);
            }
        }

        for (ll i = 1; i <= n; i++) {
            if (find(i) < 0) continue;
            for (ll j = 1; j <= n; j++) {
                swap(a[i][j], a[j][i]);
            }
        }

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }    
    
    return 0;
}

