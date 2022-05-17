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


ll kadane(const vector<ll>& a) {
    ll best = 0, curr = 0;
    for (auto x : a) {
        curr = max(0ll, curr + x);
        best = max(best, curr);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2 == 0) sum += a[i];
        }

        ll curr = 0, mx = 0;
        for (ll i = 1; i < n; i += 2) {
            curr += a[i] - a[i-1];
            curr = max(0ll, curr);
            mx = max(mx, curr);
        }
        
        curr = 0;
        for (ll i = 2; i < n; i += 2) {
            curr += a[i-1] - a[i];
            curr = max(0ll, curr);
            mx = max(mx, curr);
        }

        cout << sum + mx << '\n';
    }    
    
    return 0;
}

