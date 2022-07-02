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
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    
    ll n; cin >> n;
    ll curr = 0;
    ll ans = 0;
    vector<ll> s(n), t(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> s[i] >> t[i] >> b[i];
    }

    vector<ll> d(1005);
    for (ll i = 0; i < n; i++) {
        d[s[i]] += b[i];
        d[t[i]] -= b[i];
    }
    for (ll time = 0; time <= 1004; time++) {
        curr += d[time];
        ans = max(ans, curr);
    }
    // for (ll time = 0; time <= 1005; time++) {
        // for (ll i = 0; i < n; i++) {
            // if (time == s[i]) curr += b[i];
            // else if (time == t[i]) curr -= b[i];
            // ans = max(ans, curr);
        // }
    // }

    cout << ans << endl;
    
    return 0;
}

