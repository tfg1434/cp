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
        ll n; cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        ll ans0 = 0;
        for (int i = 1; i < n; i++) 
            ans0 += abs(a[i] - a[i - 1]);

        ll ans = ans0 - max(abs(a[0] - a[1]), abs(a[n - 1] - a[n - 2]));
        for (int i = 2; i < n; i++) {
            ans = min(ans, ans0
                - abs(a[i-0] - a[i-1])
                - abs(a[i-1] - a[i-2])
                + abs(a[i-0] - a[i-2]));
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

