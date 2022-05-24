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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll a, b, q; cin >> a >> b >> q;
        vector<bool> tru(a*b);
        for (ll x = 0; x < a*b; x++) {
            bool y = ((x % a) % b) != ((x % b) % a);
            tru[x] = y;
        }
        vector<ll> pre(a*b+1, 0);
        for (ll x = 0; x < a*b; x++) {
            pre[x+1] = pre[x] + tru[x];
        }
        // cout << pre << '\n';

        auto f = [&](ll p) {
            ll full = p / (a*b);
            ll rem = p % (a*b);
            ll res = pre[a*b] * full + pre[rem];
            return res;
        };

        for (ll i = 0; i < q; i++) {
            ll l, r; cin >> l >> r;
            l++; r++;
            
            ll ans = f(r) - f(l-1);
            cout << ans << ' ';
        }
        cout << '\n';
    }    
    
    return 0;
}

