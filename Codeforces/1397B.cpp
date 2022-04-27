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
    
    ll n;
    while (cin >> n) {
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        sort(all(a));
        if (n <= 2) {
            cout << a[0] - 1 << '\n';
            continue;
        }

        ll ans = INFF, c;
        for (c = 1; pow(c, n-1) <= (1+1e10); c++) {
            ll cost = 0;
            for (ll j = 0; j < n; j++) {
                cost += abs(pow(c, j) - a[j]);
            }
            ans = min(ans, cost);
        }

        cout << ans << '\n';
    }
    
    return 0;
}

