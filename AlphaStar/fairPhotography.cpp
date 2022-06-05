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
    
    ll n; cin >> n;
    vector<pair<ll, char>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    sort(all(a));
    vector<ll> x(n), b(n);
    for (ll i = 0; i < n; i++) {
        x[i] = a[i].first;
        char c = a[i].second;
        if (c == 'G') b[i] = -1;
        else b[i] = 1;
    }

    ll ans = 0;
    for (ll i = 0; i < n; ) {
        ll sz = 1;
        while (i + sz < n && b[i + sz] == b[i]) sz++;
        ans = max(ans, x[i+sz-1] - x[i]);
        i += sz;
    }

    vector<ll> pre(2*n, INFF);
    ll curr = 0;
    for (ll i = 0; i < n; i++) {
        pre[n + curr] = min(x[i], pre[n + curr]);
        curr += b[i];
        ans = max(ans, x[i] - pre[n + curr]);
    }

    cout << ans << '\n';
    
    return 0;
}

