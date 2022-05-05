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
    
    ll n; while (cin >> n) {
        vector<ll> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        vector<ll> pre(n+1, 0);
        for (ll i = 0; i < n; i++) {
            pre[i+1] = pre[i] + a[i]*b[i];
        }

        ll ans = pre[n];
        auto f = [&](ll l, ll r, ll& curr) {
            curr += a[l] * b[r];
            curr += a[r] * b[l];
            ans = max(ans, curr + pre[l] + (pre[n] - pre[r+1]));
        };

        for (ll c = 0; c < n; c++) {
            ll curr = a[c] * b[c];
            for (ll l = c-1, r = c+1; l>=0 && r<n; --l, r++) {
                f(l, r, curr);
            }
            curr = 0;
            for (ll l = c, r = c+1; l>=0 && r<n; --l, r++) {
                f(l, r, curr);
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

