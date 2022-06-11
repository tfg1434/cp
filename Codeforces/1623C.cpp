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
        ll n; cin >> n;
        vector<ll> h(n);
        for (auto& x : h) cin >> x;

        auto check = [&](ll x) {
            vector<ll> curr(all(h));
            for (ll i = n-1; i >= 2; i--) {
                if (curr[i] < x) return false;
                ll d = min(h[i], curr[i] - x) / 3;
                curr[i-1] += d;
                curr[i-2] += 2*d;
            }

            return curr[0] >= x && curr[1] >= x;
        };

        ll l = 0, r = 1e9;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (check(m)) {
                l = m+1;
            } else {
                r = m-1;
            }
        }

        cout << l-1 << endl;
    }    
    
    return 0;
}

