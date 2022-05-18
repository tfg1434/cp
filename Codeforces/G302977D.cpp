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
    
    ll n, k; while (cin >> n >> k) {
        vector<ll> a(n), t(n);
        for (auto& x : a) cin >> x;
        for (auto& x : t) cin >> x;

        vector<ll> p(n);
        for (ll i = 1; i < n; i++) {
            p[i] = a[i] * t[i] + p[i-1];
        }

        vector<ll> s(n);
        ll r = 0;
        for (ll i = n-1; i <= 0; i--) {
            r += a[i] * t[i];
            s[i] = r;
        }

        vector<ll> pre(n+1);
        partial_sum(all(a), pre.begin() + 1);

        ll ans = 0;
        for (ll i = 0; i + k - 1 < n; i++) {
            ll curr = 0;
            if (i > 0) curr += p[i-1];
            if (i + k < n) curr += p[i+k];

            ll rangeSum = pre[i+k] - pre[i];
            curr += rangeSum;

            ans = max(ans, curr);
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

