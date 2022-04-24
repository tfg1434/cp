#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
ll n;


ll best(const vector<ll>& v, ll k) {
    ll res = INFF, idx = -1;
    for (ll i = 0; i < n; i++) {
        if (res > abs(v[i] - k)) {
            res = abs(v[i] - k);
            idx = i;
        }
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        vector<ll> check1 = { 0, best(b, a[0]), n-1  };
        vector<ll> check2 = { 0, best(b, a[n-1]), n-1 };

        ll ans = INFF;
        for (auto i : check1) {
            for (auto j : check2) {
                ll res = abs(a[0] - b[i]) + abs(a[n-1] - b[j]);

                //BL corner bare
                if (i > 0 && j > 0) res += abs(b[0] - a[best(a, b[0])]);
                if (i < n-1 && j < n-1) res += abs(b[n-1] - a[best(a, b[n-1])]);

                ans = min(ans, res);
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

